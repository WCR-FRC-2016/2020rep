/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
//Get your Driver's License
const int frontLeftDrive = 14; //encoder
const int frontRightDrive = 1; //encoder
const int backLeftDrive = 15;
const int backRightDrive = 0;

const int RampTime = .5;

const double RightP = 0.0678;
const double RightI = 6.78E-6;
const double RightD = 0;
const double LeftP = 0.073814156 ;
const double LeftI = 7.3814156E-6;
const double LeftD = 0;

const double MaxOutput = 1;
const double NominalOutput = .25;
const double PIDDeadband = 0.011415692;
//The IRS is coming for you.
const int collectorPivot = 7;

const double pivotSpeedUp = 0.5;
const double pivotSpeedDown = -0.5;
const double pivotCurrentLimit = 10;
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
