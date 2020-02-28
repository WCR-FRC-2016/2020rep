/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>
#include "subsystems/InsideCollector.h"
#include <frc2/command/InstantCommand.h>
#include <RobotMap.h>
class ShootGroup 
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 ShootGroup> {
 public:
  ShootGroup(InsideCollector* IC);
private:
  InsideCollector m_IC;
  frc2::InstantCommand m_shoot{[this] {m_IC.Shooting(ShootingSpeed);}, {&m_IC} };
};
