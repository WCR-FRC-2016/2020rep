/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "RobotMap.h"
#include "commands/AutoyTurret.h"

AutoyTurret::AutoyTurret(Turret* turret, double position): m_turret{turret}, m_position{position} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({turret});
  }

// Called when the command is initially scheduled.
void AutoyTurret::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoyTurret::Execute() {
  m_turret->AutoyAxis(m_position);
}

// Called once the command ends or is interrupted.
void AutoyTurret::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoyTurret::IsFinished() { (m_turret->returnyPosition() < m_position + yTurretError && m_turret->returnyPosition() > m_position - yTurretError); }
