/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TenchAuto.h"
#include <frc2/command/ParallelRaceGroup.h>
#include "commands/ShootCommand.h"
#include "commands/AutoxTurret.h"
#include "commands/AutoAimCommand.h"
#include "commands/AutoMove.h"
#include "commands/StateChangeCommand.h"
#include "commands/CollectionCommand.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
TenchAuto::TenchAuto(DriveBase* drivebase, InsideCollector* IC, TaxCollector* TC, Turret* turret) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(StateChangeCommand(TC),
     AutoxTurret(turret, -90),
     frc2::ParallelRaceGroup{AutoAimCommand(turret), ShootCommand(IC)}.WithTimeout(1_s),
     frc2::ParallelRaceGroup{AutoAimCommand(turret), ShootCommand(IC)}.WithTimeout(3_s),
     frc2::ParallelRaceGroup{AutoMove(drivebase, 0.2), CollectionCommand(IC)}.WithTimeout(2_s),
     frc2::ParallelRaceGroup{AutoMove(drivebase, -0.2)}.WithTimeout(2_s),
     frc2::ParallelRaceGroup{AutoAimCommand(turret), ShootCommand(IC)}.WithTimeout(1_s),
     frc2::ParallelRaceGroup{AutoAimCommand(turret), ShootCommand(IC)}.WithTimeout(3_s)

  
  );
}
