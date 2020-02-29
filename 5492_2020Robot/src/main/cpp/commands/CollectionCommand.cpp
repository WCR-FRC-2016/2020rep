/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CollectionCommand.h"

CollectionCommand::CollectionCommand(InsideCollector* IC): m_IC{IC} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({IC});
}

// Called when the command is initially scheduled.
void CollectionCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CollectionCommand::Execute() {
  m_IC->Collection();
}

// Called once the command ends or is interrupted.
void CollectionCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool CollectionCommand::IsFinished() { return false; }
