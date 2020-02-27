/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include<frc/shuffleboard/Shuffleboard.h>
#include "commands/ArcadeDrive.h"
#include "commands/BallCollectorDefault.h"
#include "commands/TaxEvasion.h"
#include "commands/LiftDefault.h"
#include <frc2/command/button/Button.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PrintCommand.h>
#include "commands/Baseline.h"
#include <frc/smartdashboard/SmartDashboard.h>
RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
m_chooser.SetDefaultOption("Baseline", &m_baseLine);
m_chooser.AddOption("BaseLine", &m_baseLine);

frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

m_driveBase.SetDefaultCommand(ArcadeDrive(&m_driveBase, 
  [this] { return m_driverStick.GetX(frc::GenericHID::kRightHand);},
  [this] { return -m_driverStick.GetY(frc::GenericHID::kLeftHand) ;}
  ));


m_turret.SetDefaultCommand(ManualTurret(&m_turret,
  [this] { return m_manStick.GetX(frc::GenericHID::kRightHand);},
  [this] { return m_manStick.GetY(frc::GenericHID::kLeftHand);}
));
m_doYouEvenLift.SetDefaultCommand(LiftDefault(&m_doYouEvenLift));

m_insideCollector.SetDefaultCommand(BallCollectorDefault(&m_insideCollector) );
m_collector.SetDefaultCommand(TaxEvasion(&m_collector));
  // Configure the button bindings
  ConfigureButtonBindings();
  
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

    m_driverB.WhenPressed(m_reverseDrive);
    m_driverY.WhenPressed(m_slowDrive);

    m_driverRT.WhenHeld(m_Extend);
    m_driverStart.WhileHeld(m_Delatch);
    m_driverBack.WhileHeld(m_Latch);
    m_driverLT.WhileHeld(m_Lift);

    m_manA.WhileHeld(m_collection);
    m_manRT.WhileHeld(m_shoot);
    m_manStart.WhileHeld(m_fastshoot);
    m_manStart.WhileHeld(m_halfHood);
    m_manB.WhileHeld(m_spit);
    m_manX.WhenPressed(m_stateChange);
    m_manY.WhileHeld(m_TrackX);
  
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}