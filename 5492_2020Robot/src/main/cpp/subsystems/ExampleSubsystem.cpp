/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ExampleSubsystem.h"
#include "RobotMap.h"
#include "ctre/Phoenix.h"
#include "OpenOneMotor.h"

//WPI_TalonSRX * MotorName Here

ExampleSubsystem::ExampleSubsystem() {
  // Implementation of subsystem constructor goes here.
}
void ExampleSubsystem::Init() {
  initialized = true;
  OpenOneMotor* OpenMotor = new OpenOneMotor();
  //Uncomment
  //MotorName = OpenMotor->Open(ID);
}
void ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
  if(!initialized){
    ExampleSubsystem::Init();
  }
}
