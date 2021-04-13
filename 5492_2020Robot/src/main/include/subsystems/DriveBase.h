/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/ADXRS450_Gyro.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/RobotDrive.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>


class DriveBase : public frc2::SubsystemBase {
 public:
  DriveBase();
  void DriveBaseInit();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  void Periodic();
  void ArcadeDrive(double xAxis, double yAxis);
  void RampSwitch(bool rampOn);
  void reverseDrive(bool bButton);
  void slowDrive(bool yButton);
  void ResetEncoders();
  bool CheckEncoders(double clicks);
  void TankDriveVolts(units::volt_t left, units::volt_t right);
  double GetHeading() const;
  frc::Pose2d GetPose();
  void ResetOdometry(frc::Pose2d pose);
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

  void setMotors(double left, double right);
  void AutoMotors(double position);
  double returnPosition();
 private:
  bool initialized = false;
  double driveConstant = -1;
  double speed = 1;
  
  WPI_TalonFX * FrontL;
  WPI_TalonFX * FrontR;
  WPI_TalonFX * BackL; 
  WPI_TalonFX * BackR;

  frc::ADXRS450_Gyro m_gyro;

  frc::DifferentialDriveOdometry * m_odometry;
  
  frc::DifferentialDrive * _diffDrive;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
