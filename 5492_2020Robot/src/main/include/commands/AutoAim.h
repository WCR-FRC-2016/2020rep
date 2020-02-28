/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>
#include "subsystems/Turret.h"
#include <frc2/command/InstantCommand.h>
class AutoAim
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 AutoAim> {
 public:
  AutoAim(Turret* turret);
 private:
  Turret m_turret;
  frc2::InstantCommand m_TrackX{[this] {return m_turret.ISee();} , {&m_turret} };
};
