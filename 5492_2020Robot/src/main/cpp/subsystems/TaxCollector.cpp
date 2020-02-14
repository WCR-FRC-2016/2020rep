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

    OpenOneMotor* OpenPivoter = new OpenOneMotor();
    Pivoter = OpenPivoter->Open(collectorPivot);

}

void TaxCollector::Pivot(){
        pivotDirection = 0.0;
        if(Pivoter->GetOutputCurrent() < pivotCurrentLimit){
            pivotDirection = (pivotState)?pivotSpeedUp:-pivotSpeedDown;
        }
        Pivoter->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, pivotDirection);
}
void TaxCollector::StateChange(){
    pivotState = !pivotState;
}
// This method will be called once per scheduler run
void TaxCollector::Periodic() {
    if(!Initialized){
        TaxCollector::InitCollector();
        Initialized = true;
    }
}
