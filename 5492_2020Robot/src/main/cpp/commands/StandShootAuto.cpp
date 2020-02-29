/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StandShootAuto.h"
#include <frc2/command/ParallelRaceGroup.h>
#include "commands/ShootCommand.h"
#include "commands/AutoxTurret.h"
#include "commands/AutoAimCommand.h"
#include "commands/AutoMove.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
StandShootAuto::StandShootAuto(Turret* turret, InsideCollector* IC, DriveBase* drivebase) {
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(frc2::ParallelRaceGroup{AutoxTurret(turret, -90)}.WithTimeout(3_s),
  frc2::ParallelRaceGroup{AutoAimCommand(turret)}.WithTimeout(1.5_s),
  frc2::ParallelRaceGroup{ShootCommand(IC)}.WithTimeout(1_s),
  frc2::ParallelRaceGroup{ShootCommand(IC)}.WithTimeout(4_s),
  frc2::ParallelRaceGroup{AutoMove(drivebase, 0.2)}.WithTimeout(2_s) 
  );
}
