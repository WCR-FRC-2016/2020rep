/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveStraight.h"
#include <ctre/Phoenix.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "RobotMap.h"

DriveStraight::DriveStraight(DriveBase* drivebase, double distance): m_drivebase{drivebase}, m_distance{distance} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drivebase});
}

// Called when the command is initially scheduled.
void DriveStraight::Initialize() {
  m_goalL = m_distance*20000 + m_drivebase->returnPositionL();
  m_goalR = m_distance*20000 + m_drivebase->returnPositionR();

  // :)

  wpi::outs() << " _|_|_|              _|                          _|_|_|    _|                          _|            _|          _|\n";
  wpi::outs() << " _|    _|  _|  _|_|      _|      _|    _|_|    _|        _|_|_|_|  _|  _|_|    _|_|_|        _|_|_|  _|_|_|    _|_|_|_|\n";
  wpi::outs() << " _|    _|  _|_|      _|  _|      _|  _|_|_|_|    _|_|      _|      _|_|      _|    _|  _|  _|    _|  _|    _|    _|\n";
  wpi::outs() << " _|    _|  _|        _|    _|  _|    _|              _|    _|      _|        _|    _|  _|  _|    _|  _|    _|    _|\n";
  wpi::outs() << " _|_|_|    _|        _|      _|        _|_|_|  _|_|_|        _|_|  _|          _|_|_|  _|    _|_|_|  _|    _|      _|_|\n";
  wpi::outs() << "                                                                                                 _|\n";
  wpi::outs() << "                                                                                             _|_|\n\n";

  m_drivebase->setMotorsPO(0.5, 0.5);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	//frc::Shuffleboard::GetTab("Numbers").Add("driveBasePosition",m_drivebase->returnPositionL());
  //frc::Shuffleboard::GetTab("Numbers").Add("command","Straight");
  
  wpi::outs() << "DriveStraight-Execute\n";
}

// Called once the command ends or is interrupted.
void DriveStraight::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveStraight::IsFinished() { return (m_drivebase->returnPositionL()>m_goalL-driveBaseError) && (m_drivebase->returnPositionL()<m_goalL+driveBaseError) && (m_drivebase->returnPositionR()>m_goalR-driveBaseError) && (m_drivebase->returnPositionR()<m_goalR+driveBaseError); }
