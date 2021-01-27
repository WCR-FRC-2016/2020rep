/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveStraight.h"
#include <ctre/Phoenix.h>

DriveStraight::DriveStraight(DriveBase* drivebase, double distance): m_drivebase{drivebase}, m_distance{distance} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drivebase});
}

// Called when the command is initially scheduled.
void DriveStraight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
  //m_drivebase->ArcadeDrive(m_rotation,m_distance);
  double goal = m_distance*20000;
  FrontL->Set(ctre::phoenix::motorcontrol::ControlMode::Position, goal);
  FrontR->Set(ctre::phoenix::motorcontrol::ControlMode::Position, goal);
  BackL->Set(ctre::phoenix::motorcontrol::ControlMode::Position, goal);
  BackR->Set(ctre::phoenix::motorcontrol::ControlMode::Position, goal);
//printf("DriveStraight-Execute\n");
}

// Called once the command ends or is interrupted.
void DriveStraight::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveStraight::IsFinished() { return false; }
