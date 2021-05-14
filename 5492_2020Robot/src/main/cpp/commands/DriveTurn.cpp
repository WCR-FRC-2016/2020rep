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
  m_goalA = m_right?90:-90 + m_drivebase->GetHeading();
  
  // If needed, the distance each motor travels is 47124/109956 encoder clicks
  
  // :)

  wpi::outs() << " _|_|_|              _|                      _|_|_|_|_|\n";
  wpi::outs() << " _|    _|  _|  _|_|      _|      _|    _|_|      _|      _|    _|  _|  _|_|  _|_|_|\n";
  wpi::outs() << " _|    _|  _|_|      _|  _|      _|  _|_|_|_|    _|      _|    _|  _|_|      _|    _|\n";
  wpi::outs() << " _|    _|  _|        _|    _|  _|    _|          _|      _|    _|  _|        _|    _|\n";
  wpi::outs() << " _|_|_|    _|        _|      _|        _|_|_|    _|        _|_|_|  _|        _|    _|\n\n";

  m_drivebase->setMotorsPO(m_right?0.8:0.343,m_right?0.343:0.8);
}

// Called repeatedly when this Command is scheduled to run
void DriveTurn::Execute() {
  //frc::Shuffleboard::GetTab("Numbers").Add("driveBasePosition",m_drivebase->returnPositionL());
  //frc::Shuffleboard::GetTab("Numbers").Add("command","Turn");
  wpi::outs() << "DriveTurn-Execute\n";
}

// Called once the command ends or is interrupted.
void DriveTurn::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveTurn::IsFinished() { return (m_drivebase->GetHeading()>m_goalA-driveBaseAngleError) && (m_drivebase->GetHeading()<m_goalA+driveBaseAngleError); }
