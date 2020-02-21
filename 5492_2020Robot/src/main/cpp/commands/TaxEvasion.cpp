/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TaxEvasion.h"
#include "subsystems/TaxCollector.h"
TaxEvasion::TaxEvasion(TaxCollector *collector) : m_collector{collector}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({collector});
}

// Called when the command is initially scheduled.
void TaxEvasion::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TaxEvasion::Execute() {
  m_collector->Pivot();
}

// Called once the command ends or is interrupted.
void TaxEvasion::End(bool interrupted) {}

// Returns true when the command should end.
bool TaxEvasion::IsFinished() { return false; }
