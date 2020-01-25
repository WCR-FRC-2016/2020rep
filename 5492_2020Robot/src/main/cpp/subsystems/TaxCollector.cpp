/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TaxCollector.h"
#include "RobotMap.h"
#include <ctre/Phoenix.h>
#include "OpenOneMotor.h"

WPI_TalonSRX * Collector;
WPI_TalonSRX * Pivoter;

TaxCollector::TaxCollector() {
    
}
void TaxCollector::InitCollector(){
    OpenOneMotor* OpenCollector = new OpenOneMotor();
    OpenOneMotor* OpenPivoter = new OpenOneMotor();
    Collector = OpenCollector->Open(collectorWheel);
    Pivoter = OpenPivoter->Open(collectorPivot);

}
void TaxCollector::Collect(){
    
    collectionDirection = (collectionDirection != collectionSpeed)?collectionSpeed:0.0;

    
    Collector->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, collectionDirection);
}
void TaxCollector::Spit(){
    collectionDirection = (collectionDirection != spitSpeed)?spitSpeed:0.0;

    
    Collector->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, collectionDirection);
}
void TaxCollector::Pivot(){
        pivotDirection = (pivotDirection <= 0.0)?pivotSpeed:-pivotSpeed;
}

// This method will be called once per scheduler run
void TaxCollector::Periodic() {
    if(!Initialized){
        TaxCollector::InitCollector();
        Initialized = true;
    }
}
