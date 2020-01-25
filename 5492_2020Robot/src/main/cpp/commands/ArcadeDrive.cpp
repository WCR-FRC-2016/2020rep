/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive(DriveBase* drivebase, std::function<double()> rotation, std::function<double()> forward) : m_drivebase{drivebase}, m_rotation{rotation}, m_forward{forward}  {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drivebase});
}

// Called when the command is initially scheduled.
void ArcadeDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute() {
  double passRotation = (abs(m_rotation()*1000) > 200?m_rotation():0.0);
  double passForward = (abs( m_forward()*1000) > 200?m_forward():0.0);
  m_drivebase->ArcadeDrive(passRotation, passForward);
}

// Called once the command ends or is interrupted.
void ArcadeDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool ArcadeDrive::IsFinished() { return false; }
