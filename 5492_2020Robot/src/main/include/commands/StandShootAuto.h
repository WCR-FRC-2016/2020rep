/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Turret.h"
#include "subsystems/InsideCollector.h"
#include "subsystems/DriveBase.h"
class StandShootAuto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 StandShootAuto> {
 public:
  StandShootAuto(Turret* turret, InsideCollector* InsideCollector, DriveBase* drivebase);
};
