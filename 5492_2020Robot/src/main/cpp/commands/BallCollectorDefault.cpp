/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/BallCollectorDefault.h"


BallCollectorDefault::BallCollectorDefault(InsideCollector* insidecollector) {
  // Use AddRequirements() here to declare subsystem dependencies.
  AddRequirements({insidecollector});
}

// Called when the command is initially scheduled.
void BallCollectorDefault::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void BallCollectorDefault::Execute() {
  
  m_insidecollector->TransMotor(0.0);
  m_insidecollector->Trigger(0.0);
  m_insidecollector->Flywheel(0.0);

}

// Called once the command ends or is interrupted.
void BallCollectorDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool BallCollectorDefault::IsFinished() { return false; }
