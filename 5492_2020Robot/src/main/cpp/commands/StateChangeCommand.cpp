/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StateChangeCommand.h"

StateChangeCommand::StateChangeCommand(TaxCollector* TC):m_TC{TC} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({TC});
}

// Called when the command is initially scheduled.
void StateChangeCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StateChangeCommand::Execute() {
  m_TC->StateChange();
}

// Called once the command ends or is interrupted.
void StateChangeCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool StateChangeCommand::IsFinished() { return false; }
