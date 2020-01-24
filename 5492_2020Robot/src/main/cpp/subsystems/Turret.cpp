/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "RobotMap.h"
#include "Robot.h"
#include "RobotContainer.h"
#include <ctre/Phoenix.h>
#include "subsystems/Turret.h"
#include "OpenOneMotor.h"

Turret::Turret() 
{

}

// This method will be called once per scheduler run
void Turret::Periodic() 
{
    if (!init)
    {
        TurretInit();
    }
}

void Turret::TurretInit() 
{
    OpenOneMotor* OpenTurretMotor = new OpenOneMotor();
    //Update values later
    xTurretMotor = OpenTurretMotor->Open(9);
    yTurretMotor = OpenTurretMotor->Open(10);
    init = true;

}

void Turret::ManualxAxis (double x)
{
    xTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, x);
}

void Turret::ManualyAxis (double y)
{
    yTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, y);
}




