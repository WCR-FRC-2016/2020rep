/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#pragma once
class VisionerCornerFinder {
 public:
  double LostandFound(std::vector<double> xArray,std::vector<double> yArray);
  VisionerCornerFinder();
};
