/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoxTurret.h"
#include "RobotMap.h"
AutoxTurret::AutoxTurret(Turret* turret, double degrees): m_turret{turret}, m_degrees{degrees} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({turret});
}

// Called when the command is initially scheduled.
void AutoxTurret::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoxTurret::Execute() {
  m_turret->AutoxAxis(m_degrees*xTurretDegree);
}

// Called once the command ends or is interrupted.
void AutoxTurret::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoxTurret::IsFinished() { return (m_turret->returnxPositon() < m_degrees*xTurretDegree + xTurretError && m_turret->returnxPositon() > m_degrees*xTurretDegree - xTurretError); }
