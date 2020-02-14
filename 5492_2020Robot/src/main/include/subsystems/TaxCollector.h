/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

class TaxCollector : public frc2::SubsystemBase {
 public:
  TaxCollector();
  void InitCollector();
  void Pivot();
  void StateChange();
 
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  bool Initialized = false;
  double pivotDirection = 0.0;
  bool pivotState = true;
  //true is up, false is down
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
