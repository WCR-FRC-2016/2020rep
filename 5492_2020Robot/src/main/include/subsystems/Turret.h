/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class Turret : public frc2::SubsystemBase {
 public:
  Turret();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void TurretInit();
  void ManualxAxis(double x);
  void ManualyAxis(double y);

  //Vision Stuff
  double targetOffsetAngle_Horizontal;
 	double targetOffsetAngle_Vertical;
 	double targetArea;
  double targetSkew;
	nt::NetworkTableEntry ledmode;
	std::shared_ptr<NetworkTable> table;
  double* ReturnVisionX();
  std::vector<double> xCorners;
	std::vector<double> yCorners;
  void SwapLedMode(int mode);
	int streamMode = 2;
  double visionData[3] = {0.0,0.0,0.0};
  double defaultVision[4] = {1.0,0.0,0.0,0.0};
  void SetCamMode(int mode);
	void SetStreamMode();
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonSRX* xTurretMotor;
  WPI_TalonSRX* yTurretMotor;
  bool init = false;

  
};
