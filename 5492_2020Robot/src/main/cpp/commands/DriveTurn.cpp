/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveTurn.h"
#include <ctre/Phoenix.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "RobotMap.h"

DriveTurn::DriveTurn(DriveBase* drivebase, bool right): m_drivebase{drivebase}, m_right{right} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drivebase});
}

// Called when the command is initially scheduled.
void DriveTurn::Initialize() {
  // 21pi/9pi inches in motor clicks
  m_goalL = m_right?109956:47124 + m_drivebase->returnPositionL();
  // 9pi/21pi inches in motor clicks
  m_goalR = m_right?47124:109956 + m_drivebase->returnPositionR();
  m_drivebase->setMotorsPO(m_right?0.8:0.343,m_right?0.343:0.8);
  //m_drivebase->setMotors(10000,10000);
}

// Called repeatedly when this Command is scheduled to run
void DriveTurn::Execute() {
  //m_drivebase->ArcadeDrive(m_rotation,m_distance);
  //m_drivebase->AutoMotors(m_goal);
  //m_drivebase->setMotors(m_goal,m_goal);
  frc::Shuffleboard::GetTab("Numbers").Add("driveBasePosition",m_drivebase->returnPositionL());
  frc::Shuffleboard::GetTab("Numbers").Add("command","Turn");
  printf("DriveTurn-Execute\n");
}

// Called once the command ends or is interrupted.
void DriveTurn::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveTurn::IsFinished() { return (m_drivebase->returnPositionL()>m_goalL-driveBaseError) && (m_drivebase->returnPositionL()<m_goalL+driveBaseError) && (m_drivebase->returnPositionR()>m_goalR-driveBaseError) && (m_drivebase->returnPositionR()<m_goalR+driveBaseError); }
