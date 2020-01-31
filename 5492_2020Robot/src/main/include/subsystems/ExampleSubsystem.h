/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "RobotMap.h"
#include "ctre/Phoenix.h"

class ExampleSubsystem : public frc2::SubsystemBase {
 public:
  ExampleSubsystem();
  void Init();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  bool initialized = false;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
