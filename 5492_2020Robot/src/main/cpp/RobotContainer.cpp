/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/ArcadeDrive.h"
#include <frc2/command/button/Button.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/InstantCommand.h>
RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
m_driveBase.SetDefaultCommand(ArcadeDrive(&m_driveBase, 
  [this] { return -(m_driverStick.GetX(frc::GenericHID::kRightHand));},
  [this] { return m_driverStick.GetY(frc::GenericHID::kLeftHand);}
  ));


  // Configure the button bindings
  ConfigureButtonBindings();

  
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
    frc2::JoystickButton(&m_driverStick, 2).WhenPressed(&reverseDrive);

  //
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
