/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

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

 private:
  bool initialized = false;
  double driveConstant = -1;
  double speed = 1;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
