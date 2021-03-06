/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

class InsideCollector : public frc2::SubsystemBase {
 public:
  InsideCollector();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void InsideCollectorInit();
  void TransMotor(double speed);
  void Trigger(double speed);
  void Flywheel(double speed);
  void Collection();
  void Shooting(double speed);
  void Spitting();
  void OutsideMotor(double speed);

 private:
 bool Init = false;
 double ICCollectSpeed = -0.5;
 double TriggerCollectSpeed = 0.5;
 double ICSpitSpeed = 0.5;
 double OCSpitSpeed = 0.5;
 double OCCollectSpeed = -.35;
 double TriggerSpitSpeed = -0.5;
 int passes = 0;
 
 double error = 1500;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
