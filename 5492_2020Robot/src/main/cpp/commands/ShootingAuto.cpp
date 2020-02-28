/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootingAuto.h"
#include "commands/Baseline.h"
#include "commands/AutoAim.h"
#include "commands/AutoxTurret.h"
#include "commands/ShootGroup.h"
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h> 
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ShootingAuto::ShootingAuto(DriveBase* drivebase, InsideCollector* IC, Turret* turret) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(frc2::ParallelDeadlineGroup{AutoxTurret(turret, -90), Baseline(drivebase) },
  frc2::ParallelCommandGroup(AutoAim(turret), ShootGroup(IC))
  );
}
