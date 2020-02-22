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
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "VisionerCornerFinder.h"

Turret::Turret() 
{
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
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
    xTurretMotor = OpenTurretMotor->Open(xTurret);
	xTurretMotor->SetInverted(true);
    yTurretMotor = OpenTurretMotor->Open(yTurret);
	xTurretMotor->SetSelectedSensorPosition(0);
	yTurretMotor->SetSelectedSensorPosition(0);
	table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    init = true;

}

void Turret::ManualxAxis (double x)
{
    xTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, x);
}

void Turret::ManualyAxis (double y)
{
	y = (yTurretMotor->GetSelectedSensorPosition() > 700 && (y<0))?0:y;
    yTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, y);
}
//Vision
//
//
void Turret::AutoxAxis(double position){
	double difference = xTurretMotor->GetSelectedSensorPosition() - position;
	double parsedSpeed = (difference>yTurretError)?xTurretP * difference + xTurretMin:0.0;
	xTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, parsedSpeed);
}
void Turret::AutoyAxis(double position){
	double difference = yTurretMotor->GetSelectedSensorPosition() - position;
	double parsedSpeed = (difference>yTurretError)?yTurretP * difference + yTurretMin:0.0;
	yTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, parsedSpeed);
}
void Turret::SwapLedMode(int mode)	{
	//1 is off, 3 is on
	table->PutNumber("ledMode",mode);
}
void Turret::SetStreamMode(){
	// 0 standard sidebyside, 1 picture in picture main, 2 pip secondary 
	streamMode = (streamMode == 1)?2:1;
	table->PutNumber("stream", streamMode);
}
void Turret::SetCamMode(int mode) {
	// 0 vision process, 1 driver cam
	table->PutNumber("camMode", mode);
}
double* Turret::ReturnVisionX(){
	table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
	targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0); 
	targetArea = table->GetNumber("ta",0.0);
	targetCenterX = table->GetNumber("tx",0.0);
	visionData[0] = targetOffsetAngle_Horizontal;
	visionData[1] = targetArea;
	visionData[2] = targetCenterX;
	xCorners = table->GetNumberArray("tcornx ", defaultVision);
	yCorners = table->GetNumberArray("tcorny", defaultVision);
	VisionerCornerFinder* CornerFinder = new VisionerCornerFinder();
	visionData[3] = CornerFinder->LostandFound(xCorners, yCorners);
	printf("Diff=%f\n",visionData[2]);
	return visionData;
}
void Turret::ISee(){
	SwapLedMode(3);
	double offSetX = ReturnVisionX()[2]; 
	double parsedSpeed = offSetX * xTurretVisionP + .025;
	parsedSpeed = (parsedSpeed > .05 || parsedSpeed < -.05)?parsedSpeed:0;
	xTurretMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, parsedSpeed);
}







