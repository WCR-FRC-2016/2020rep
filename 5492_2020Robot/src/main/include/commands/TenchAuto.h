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
#include "subsystems/TaxCollector.h"
#include "subsystems/DriveBase.h"
#include <frc2/command/InstantCommand.h>
#include "RobotMap.h"
class TenchAuto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 TenchAuto> {
 public:
  TenchAuto(DriveBase* drivebase, InsideCollector* IC, TaxCollector* TC, Turret* turret);
  TaxCollector m_collector;
  Turret m_turret;
  InsideCollector m_insideCollector;

};
