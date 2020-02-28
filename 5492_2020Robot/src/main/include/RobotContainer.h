/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/Button.h>
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveBase.h"
#include "subsystems/TaxCollector.h"
#include "commands/ArcadeDrive.h"
#include "frc/XboxController.h"
#include "subsystems/Turret.h"
#include "commands/ManualTurret.h"
#include "subsystems/InsideCollector.h"
#include <frc2/command/PrintCommand.h>
#include "subsystems/DoYouEvenLift.h"
#include "Robotmap.h"
#include "commands/Baseline.h"
#include <frc/smartdashboard/SendableChooser.h>
#include "commands/ShootingAuto.h"
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
  InsideCollector m_insideCollector;
  DriveBase m_driveBase;
  TaxCollector m_collector;
  Turret m_turret;
  DoYouEvenLift m_doYouEvenLift;

  frc::SendableChooser<frc2::Command*> m_chooser;
  Baseline m_baseLine{&m_driveBase};
  ShootingAuto m_shootingAuto{&m_driveBase, &m_insideCollector, &m_turret};
  frc2::InstantCommand m_TrackX{[this] {return m_turret.ISee();} , {&m_turret} };
  frc2::Button m_manY{[&] {return m_manStick.GetYButton();}};

  frc::XboxController m_driverStick{0};
  frc::XboxController m_manStick{1};
  frc2::Button m_driverB{[&] {return m_driverStick.GetBButtonPressed();} };
  frc2::InstantCommand m_reverseDrive{[this] {m_driveBase.reverseDrive(true);} };
  frc2::Button m_driverY{[&] {return m_driverStick.GetYButtonPressed();} };
  frc2::InstantCommand m_slowDrive{[this] {m_driveBase.slowDrive(true);} };


  frc2::Button m_driverRT{[&] {return (0.5 < m_driverStick.GetTriggerAxis(frc::GenericHID::kRightHand));} };
  frc2::Button m_driverLT{[&] {return (0.5 < m_driverStick.GetTriggerAxis(frc::GenericHID::kLeftHand));} };
  frc2::Button m_driverStart{[&] {return m_driverStick.GetStartButton();} };
  frc2::Button m_driverBack{[&] {return m_driverStick.GetBackButton();} };

  frc2::InstantCommand m_Lift{[this] {m_doYouEvenLift.Lift();}, {&m_doYouEvenLift} };
  frc2::InstantCommand m_Extend{[this] {m_doYouEvenLift.Extend();}, {&m_doYouEvenLift} };
  frc2::InstantCommand m_Latch{[this] {m_doYouEvenLift.Latch();}, {&m_doYouEvenLift} };
  frc2::InstantCommand m_Delatch{[this] {m_doYouEvenLift.Delatch();}, {&m_doYouEvenLift} };


  frc2::Button m_manA{[&] {return m_manStick.GetAButton();} };
  frc2::InstantCommand m_collection{[this] {m_insideCollector.Collection();}, {&m_insideCollector} };
  frc2::Button m_manB{[&] {return m_manStick.GetBButton();} };
  frc2::InstantCommand m_spit{[this] {m_insideCollector.Spitting();}, {&m_insideCollector} };
  frc2::Button m_manRT{[&] {return (0.5 < m_manStick.GetTriggerAxis(frc::GenericHID::kRightHand));} };
  frc2::InstantCommand m_shoot{[this] {m_insideCollector.Shooting(ShootingSpeed);}, {&m_insideCollector} };
  frc2::Button m_manStart{[&]{return m_manStick.GetStartButton();} };
  frc2::InstantCommand m_fastshoot{[this] {m_insideCollector.Shooting(FastShootingSpeed);}, {&m_insideCollector} };
  frc2::InstantCommand m_halfHood{[this] {m_turret.AutoyAxis(300);}, {&m_turret} };

  frc2::Button m_manX{[&] {return m_manStick.GetXButtonPressed();} };
  frc2::InstantCommand m_stateChange{[this] {m_collector.StateChange(); }, {&m_collector} };

  

  void ConfigureButtonBindings();
};
