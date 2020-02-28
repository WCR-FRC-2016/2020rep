/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootCommand.h"
#include "RobotMap.h"
ShootCommand::ShootCommand(InsideCollector* IC):m_IC{IC} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ShootCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootCommand::Execute() {
  m_IC->Shooting(ShootingSpeed);
}

// Called once the command ends or is interrupted.
void ShootCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool ShootCommand::IsFinished() { return false; }
