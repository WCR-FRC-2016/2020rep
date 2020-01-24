/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ManualTurret.h"

ManualTurret::ManualTurret(Turret* turret,std::function<double()> x, std::function<double()> y) : m_turret{turret}, m_x{x}, m_y{y} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ManualTurret::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualTurret::Execute() 
{
  m_turret->ManualxAxis(m_x());
  m_turret->ManualyAxis(m_y());
}

// Called once the command ends or is interrupted.
void ManualTurret::End(bool interrupted) {}

// Returns true when the command should end.
bool ManualTurret::IsFinished() { return false; }
