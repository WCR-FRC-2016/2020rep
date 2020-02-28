/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoAimCommand.h"

AutoAimCommand::AutoAimCommand(Turret* turret): m_turret{turret} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({turret});
}

// Called when the command is initially scheduled.
void AutoAimCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoAimCommand::Execute() {
  m_turret->ISee();
}

// Called once the command ends or is interrupted.
void AutoAimCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoAimCommand::IsFinished() { return false; }
