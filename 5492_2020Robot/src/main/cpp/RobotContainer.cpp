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
#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>
RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
m_chooser.SetDefaultOption("Robin Square",&m_robinSquare);
m_chooser.AddOption("Baseline", &m_baseLine);
m_chooser.AddOption("Shooting Straight", &m_shootingAuto );
m_chooser.AddOption("Shoot Standing",&m_standShootAuto);
m_chooser.AddOption("Trench Run Auto",&m_tenchAuto);

frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

m_driveBase.SetDefaultCommand(ArcadeDrive(&m_driveBase, 
  [this] { return m_driverStick.GetX(frc::GenericHID::kRightHand);} ,
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
    m_driverRBumper.WhenPressed(m_slowDrive);

    m_driverRT.WhileHeld(m_Extend);
    m_driverStart.WhileHeld(m_Delatch);
    m_driverBack.WhileHeld(m_Latch);
    m_driverLT.WhileHeld(m_Lift);

    m_manA.WhileHeld(m_collection);
    m_manRT.WhileHeld(m_shoot);
    m_manStart.WhileHeld(m_fastshoot);
   // 2020Mar17 Walko
   // Commented out following line; it's mapped to same button as fastshoot, and seems to just jiggle hood back and forth.  Presumably intent is to adjust hood and y-shooting angle on fastshoot
   // m_manStart.WhileHeld(m_halfHood);
    m_manB.WhileHeld(m_spit);
    m_manX.WhenPressed(m_stateChange);
    m_manY.WhileHeld(m_TrackX);
    m_manLBumper.WhileHeld(m_halfHood);
  
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
  
  /*

  // Create a voltage constraint to ensure we don't accelerate too fast
  
  frc::DifferentialDriveKinematics kDriveKinematics = frc::DifferentialDriveKinematics(kTrackwidth);

  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          ks, kv, ka),
      kDriveKinematics, 10_V);

  // Set up config for trajectory
  frc::TrajectoryConfig config(kMaxSpeed,
                               kMaxAcceleration);
  
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);

  wpi::SmallString<64> deployDirectory;
  frc::filesystem::GetDeployDirectory(deployDirectory);
  wpi::sys::path::append(deployDirectory, "paths");
  wpi::sys::path::append(deployDirectory, "Test.wpilib.json");

  //frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);

  frc::Trajectory trajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
      // End 3 meters straight ahead of where we started, facing forward
      frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass the config
      config);

  frc2::RamseteCommand ramseteCommand(
      trajectory, [this]() { return m_driveBase.GetPose(); },
      frc::RamseteController(kRamseteB,
                             kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(ks, kv, ka),
      kDriveKinematics,
      [this] { return m_driveBase.GetWheelSpeeds(); },
      frc2::PIDController(kPDriveVel, 0, 0),
      frc2::PIDController(kPDriveVel, 0, 0),
      [this](auto left, auto right) { m_driveBase.TankDriveVolts(left, right); },
      {&m_driveBase});

  // Reset odometry to the starting pose of the trajectory.
  m_driveBase.ResetOdometry(trajectory.InitialPose());

  // no auto
  return new frc2::SequentialCommandGroup(
      std::move(ramseteCommand),
      frc2::InstantCommand([this] { m_driveBase.TankDriveVolts(0_V, 0_V); }, {}));
  */
}