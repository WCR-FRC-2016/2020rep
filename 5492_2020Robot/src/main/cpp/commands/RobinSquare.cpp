/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RobinSquare.h"
#include "commands/ArcadeDrive.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
RobinSquare::RobinSquare(DriveBase* drivebase) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(ArcadeDrive(drivebase, [this] {return 0.0;}, [this] {return 0.2;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.2;}, [this] {return 0.1;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.0;}, [this] {return 0.2;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.2;}, [this] {return 0.1;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.0;}, [this] {return 0.2;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.2;}, [this] {return 0.1;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.0;}, [this] {return 0.2;}).WithTimeout(1_s),
              ArcadeDrive(drivebase, [this] {return 0.2;}, [this] {return 0.1;}).WithTimeout(1_s));
}
