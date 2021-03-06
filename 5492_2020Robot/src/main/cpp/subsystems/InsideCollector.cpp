/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/InsideCollector.h"
#include "OpenOneMotor.h"
#include "RobotMap.h"
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
WPI_TalonSRX* ICMotor;
WPI_TalonSRX* OCMotor;
WPI_TalonSRX* TriggerMotor;
WPI_TalonSRX* GroundwheelMotor;
WPI_TalonSRX* FlywheelMotor;
frc::DigitalInput collectorLimit{0};
InsideCollector::InsideCollector() {}

// This method will be called once per scheduler run
void InsideCollector::Periodic() {
    if (!Init) {
        InsideCollector::InsideCollectorInit();
        Init = true;
    }
    //TransMotor(0.0);
    //Trigger(0.0);
    //Flywheel(0.0);
}

void InsideCollector::InsideCollectorInit() {
    OpenOneMotor* OpenICMotor = new OpenOneMotor();
    ICMotor = OpenICMotor->Open(insideCollector);
    OCMotor = OpenICMotor->Open(outsideCollector);
    TriggerMotor = OpenICMotor->Open(triggerMotor);
    FlywheelMotor = OpenICMotor->Open(flywheelMotor);
    GroundwheelMotor = OpenICMotor->Open(groundwheelmotor);
    FlywheelMotor->Config_kP(0, flywheelP, 0);
    FlywheelMotor->Config_kI(0, flywheelI, 0);
    FlywheelMotor->Config_kD(0, flywheelD, 0);
    //Groundwheel turns opposite direction to the Flywheel
    GroundwheelMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, flywheelMotor);
    GroundwheelMotor->SetInverted(true);
    FlywheelMotor->SetInverted(true);
    //
    // Hack to override the 15 Amp for 1-second current limit which is set by OpenOneMotor
    // This changes it from 15 Amps to 50 Amps for the two flywheel motors
    GroundwheelMotor->ConfigPeakCurrentLimit(50, 0);
    FlywheelMotor->ConfigPeakCurrentLimit(50, 0);
 
}
void InsideCollector::OutsideMotor(double speed) {
    OCMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void InsideCollector::TransMotor(double speed) {
    ICMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void InsideCollector::Trigger(double speed) {
    TriggerMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void InsideCollector::Flywheel(double speed) {
    FlywheelMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void InsideCollector::Collection() {
    TransMotor(ICCollectSpeed);
    OutsideMotor(OCCollectSpeed);
    if (!collectorLimit.Get()) {
        Trigger(0);
    }
    else{

        Trigger(TriggerCollectSpeed);
    }

    Flywheel(0.0);
}

void InsideCollector::Shooting(double speed) {
    FlywheelMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, speed);
    if (-FlywheelMotor->GetSensorCollection().GetQuadratureVelocity()>(speed-error)) {
        Trigger(TriggerCollectSpeed);
        TransMotor(ICCollectSpeed);
        OutsideMotor(OCCollectSpeed);

    }
    else {
        
        Trigger(0.0);
        TransMotor(0.0);
        OutsideMotor(0.0);
    }
    std::cout << FlywheelMotor->GetSensorCollection().GetQuadratureVelocity();
}

void InsideCollector::Spitting() {
    Trigger(TriggerSpitSpeed);
    TransMotor(ICSpitSpeed);
    OutsideMotor(OCSpitSpeed);
    Flywheel(0.0);
}