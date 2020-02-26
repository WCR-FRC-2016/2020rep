/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoMove.h"

AutoMove::AutoMove(DriveBase* drivebase): m_drivebase{drivebase} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drivebase});
}

// Called when the command is initially scheduled.
void AutoMove::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoMove::Execute() {
  m_drivebase->ArcadeDrive(0,0.2);
}

// Called once the command ends or is interrupted.
void AutoMove::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoMove::IsFinished() { return false; }
