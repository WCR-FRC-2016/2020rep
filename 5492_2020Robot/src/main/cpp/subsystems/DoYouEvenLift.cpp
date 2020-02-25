/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DoYouEvenLift.h"
#include "RobotMap.h"
#include "OpenOneMotor.h"
#include <ctre/Phoenix.h>
DoYouEvenLift::DoYouEvenLift() {

}
void DoYouEvenLift::LiftInit() {
    OpenOneMotor *OpenMotor = new OpenOneMotor();
    LiftMasterMotor = OpenMotor->Open(liftMaster);
    LiftApprentinceMotor = OpenMotor->Open(liftApprentice);
    LiftApprentinceMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, liftMaster);
    init = true;
}
void DoYouEvenLift::Lift(){
    LiftMasterMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);

}
void DoYouEvenLift::Extend(){
    LiftMasterMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.5);

}
void DoYouEvenLift::Latch(){
    LatchMotor.Set(0);
}
void DoYouEvenLift::Delatch(){
    LatchMotor.Set(1);
}

void DoYouEvenLift::Default(){
    LiftMasterMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
}
// This method will be called once per scheduler run
void DoYouEvenLift::Periodic() {
    if (!init) {
        LiftInit();
    }
}
