/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/Button.h>
#include <frc2/command/InstantCommand.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveBase.h"
#include "subsystems/TaxCollector.h"
#include "commands/ArcadeDrive.h"
#include "frc/XboxController.h"
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  
 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;
  DriveBase m_driveBase;
  TaxCollector m_collector;

  frc::XboxController m_driverStick{0};
  frc::XboxController m_manStick{1};
  frc2::Button m_driverB{[&] {return m_driverStick.GetBButtonPressed();} };
  frc2::InstantCommand m_reverseDrive{[this] {m_driveBase.reverseDrive(true);} };
  frc2::Button m_driverY{[&] {return m_driverStick.GetYButtonPressed();} };
  frc2::InstantCommand m_slowDrive{[this] {m_driveBase.slowDrive(true);} };
  frc2::Button m_manX{[&] {return m_manStick.GetXButtonPressed();} };
 
  frc2::InstantCommand m_stateChange{[this] {m_collector.StateChange(); } };
  frc2::InstantCommand m_taxEvasion{[this] {m_collector.Pivot();} };
  void ConfigureButtonBindings();
};
