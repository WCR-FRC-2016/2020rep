/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

const int frontLeftDrive = 14; //encoder
const int frontRightDrive = 1; //encoder
const int backLeftDrive = 15;
const int backRightDrive = 0;

const int liftMaster = 12;
const int liftApprentice = 13;

const int xTurret = 4;
const int yTurret = 5;
const double xTurretVisionP = 0.020;


const double xTurretP = 0.0001;
const double xTurretMin = 0.1;
const double xTurretError = 200;
const double xTurret90 = 6960;
const double xTurret180 = 13860;
const double xTurretn60 = -4620; //limmit 1
const double xTurret240 = 18480; //limit 2
const double xTurretDegree = 77;

const double yTurretP = 0.005;
const double yTurretError = 10;
const double yTurretMin = .15;

const int insideCollector = 8; //Stage 1 Storage
const int outsideCollector = 6; //Collectro instake wheels
const int triggerMotor = 9; // Stage 2 Storage
const int flywheelMotor = 2; // Upper Shooter Motor
const int groundwheelmotor = 3; // Lower Shooter Motor

const double RampTime = 0.375;
const double RightP = 0.0678;
const double RightI = 6.78E-6;
const double RightD = 0;
const double LeftP = 0.073814156 ;
const double LeftI = 7.3814156E-6;
const double LeftD = 0;
const double flywheelP = 0.65;
const double flywheelI = 0;
const double flywheelD = 0;

const double MaxOutput = 1;
const double NominalOutput = .25;
const double PIDDeadband = 0.011415692;
//The IRS is coming for you.
const int collectorPivot = 7;

const double ShootingSpeed = 17500;
const double FastShootingSpeed = 20000;
const double pivotSpeedUp = 1 ;
const double pivotSpeedDown = -0.5;
const double pivotCurrentLimit = 3;

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
