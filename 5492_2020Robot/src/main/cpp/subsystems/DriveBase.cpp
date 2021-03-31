/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveBase.h"
#include "RobotMap.h"

DriveBase::DriveBase() {
	
}

void DriveBase::DriveBaseInit() {
    initialized = true;
		FrontL = new WPI_TalonFX (frontLeftDrive);
		FrontR = new WPI_TalonFX (frontRightDrive);
		BackL = new WPI_TalonFX (backLeftDrive);
		BackR = new WPI_TalonFX (backRightDrive);
		_diffDrive = new frc::DifferentialDrive(*FrontL, *FrontR);

		//0s motors
		FrontR->ConfigFactoryDefault();
		FrontL->ConfigFactoryDefault();
		BackR->ConfigFactoryDefault();
		BackL->ConfigFactoryDefault();
//Inverting motors: two motors on a single gear have to drive oppisite directions.
		FrontR->SetInverted(true);
		FrontL->SetInverted(false);
		BackR->SetInverted(true);
		BackL->SetInverted(false);

		// enabled, limit(amp), trigger threshold(amp), trigger time threshold (s)
		//StatorCurrentLimitConfiguration* stator_limit =
		//    new StatorCurrentLimitConfiguration(true, 0, 50, 1);
		SupplyCurrentLimitConfiguration* supply_limit =
		    new SupplyCurrentLimitConfiguration(true, 0, 50, 1);
		
		// Default limit of 0 seems mildly odd..

		/*
		FrontL->ConfigStatorCurrentLimit(*stator_limit);
		FrontR->ConfigStatorCurrentLimit(*stator_limit);
		BackL->ConfigStatorCurrentLimit(*stator_limit);
		BackR->ConfigStatorCurrentLimit(*stator_limit);
		*/

		FrontL->ConfigSupplyCurrentLimit(*supply_limit);
		FrontR->ConfigSupplyCurrentLimit(*supply_limit);
		BackL->ConfigSupplyCurrentLimit(*supply_limit);
		BackR->ConfigSupplyCurrentLimit(*supply_limit);

		/*
		// Old TalonSRX current limit setup, just in case
		FrontR->ConfigPeakCurrentLimit(50,0);
		FrontL->ConfigPeakCurrentLimit(50,0);
		BackR->ConfigPeakCurrentLimit(50,0);
		BackL->ConfigPeakCurrentLimit(50,0);

		FrontR->ConfigPeakCurrentDuration(1000,0);
		FrontL->ConfigPeakCurrentDuration(1000,0);
		BackR->ConfigPeakCurrentDuration(1000,0);
		BackL->ConfigPeakCurrentDuration(1000,0);

		FrontR->EnableCurrentLimit(true);
		FrontL->EnableCurrentLimit(true);
		BackR->EnableCurrentLimit(true);
		BackL->EnableCurrentLimit(true);
		*/

		FrontL->ConfigOpenloopRamp(RampTime, 0);
    	FrontR->ConfigOpenloopRamp(RampTime, 0);
   		BackL->ConfigOpenloopRamp(RampTime, 0);
    	BackR->ConfigOpenloopRamp(RampTime, 0);

		/*
		FrontL->ConfigClosedloopRamp(ClosedLoopRampTime, 0);
    	FrontR->ConfigClosedloopRamp(ClosedLoopRampTime, 0);
   		BackL->ConfigClosedloopRamp(ClosedLoopRampTime, 0);
    	BackR->ConfigClosedloopRamp(ClosedLoopRampTime, 0);
		//*/

		FrontR->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 0);
		FrontL->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 0);


		//PID BTW
		FrontR->SelectProfileSlot(0,0);
		FrontR->Config_kP(0, RightP, 0);
		FrontR->Config_kI(0, RightI, 0);
		FrontR->Config_kD(0, RightD, 0);
		FrontR->Config_kF(0, RightF, 0);
		FrontL->SelectProfileSlot(0,0);
		FrontL->Config_kP(0, LeftP, 0);
		FrontL->Config_kI(0, LeftI, 0);
		FrontL->Config_kD(0, LeftD, 0);
		FrontL->Config_kF(0, LeftF, 0);

		FrontR->ConfigNominalOutputForward(NominalOutput, 0);
		FrontR->ConfigNominalOutputReverse(-NominalOutput, 0);
		FrontL->ConfigNominalOutputForward(NominalOutput, 0);
		FrontL->ConfigNominalOutputReverse(-NominalOutput, 0);

		FrontR->SetSensorPhase(false);
		FrontL->SetSensorPhase(false);

		
		// Configure MotionMagic for froont motors (back motors are followers)
	    FrontL->ConfigMotionCruiseVelocity(7500); // target velocity
	    FrontL->ConfigMotionAcceleration(7500);  // max acceleration
		FrontL->ConfigMotionSCurveStrength(1,0);  // acceleration smoothing (0-8)
		
		// Config FrontR same as FrontL
	    FrontR->ConfigMotionCruiseVelocity(7500);
	    FrontR->ConfigMotionAcceleration(7500);
		FrontR->ConfigMotionSCurveStrength(1,0);


		FrontR->ConfigPeakOutputForward(MaxOutput, 0);
		FrontR->ConfigPeakOutputReverse(-MaxOutput, 0);
		FrontL->ConfigPeakOutputForward(MaxOutput, 0);
		FrontL->ConfigPeakOutputReverse(-MaxOutput, 0);

		FrontR->ConfigNeutralDeadband(PIDDeadband, 0);
		FrontL->ConfigNeutralDeadband(PIDDeadband, 0);

		FrontR->SetSelectedSensorPosition(0,0,10);
		FrontL->SetSelectedSensorPosition(0,0,10);

		_diffDrive->SetSafetyEnabled(false);

	
		_diffDrive->SetExpiration(.5);
		BackL->Follow(*FrontL);
		BackR->Follow(*FrontR);
		//BackL->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, frontLeftDrive);
		//BackR->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, frontRightDrive);
		printf("Done setting up motor \n");

}
void DriveBase::ResetEncoders(){
	FrontL->SetSelectedSensorPosition(0);
	FrontR->SetSelectedSensorPosition(0);
}
bool DriveBase::CheckEncoders(double clicks){
	return (FrontL->GetSelectedSensorPosition() >= clicks || FrontR->GetSelectedSensorPosition() >=clicks);
}
void DriveBase::ArcadeDrive(double xAxis, double yAxis) {
  	double parsedLeft;
	double parsedRight;
	double parsedX;
	double parsedY;

	double power = 2.3;

	//New stuff here for driver improvements.
	double minX = 0.65;
	double minY = 0.5;
	double ySlope = (1-minY)/(1);
	double xSlope = (minX-1)/(1);
	double XSC = 0;
	//Setting inputs to a power

	//YAxis setup to have a minimum value required to drive the Talon when the YAxis is not zero.
	/*		Yaxis Parsed
		    |  /
		    | /
	minY	|/
		    |
	--------------------- YAxis Raw
		    |
	       /| -minY
	      /	|
	     /	|
	*/ 
	//XAxis scaled to have a maximum value of 1 when the Yaxis is 0 and a minimum value of minX when the Y axis is 1. 

	/*	XSC
		|
1.0	    	|\
		| \
		|  \
		|   \
		|    \
		|     \
		|      \
		| 	\
      	    Minx|	 \
		|	 |\		
		|	 | \		
		|	 |  \	
		----------------YAxis
	   	0.0 	 1.0

	*/
	if (yAxis > 0) {
		yAxis = ySlope * yAxis + minY;
		XSC = xSlope * yAxis + 1.0;
		xAxis = xAxis * XSC;
	} 
	else if (yAxis < 0) {
		yAxis = ySlope * yAxis - minY;
		XSC = xSlope * -yAxis + 1.0;
		xAxis = xAxis * XSC;
	}
	


	parsedX = xAxis *speed; //pow((xAxis>0)?xAxis:-xAxis, power) * (xAxis / (xAxis>0)?xAxis:-xAxis);

	parsedY = pow((yAxis>0)?yAxis:-yAxis, power) * (yAxis / (yAxis>0)?yAxis:-yAxis) * driveConstant * speed;

	if (yAxis < 0)
	{
		//TO BE
		//FILLED IN
		//Turning Left?
		
			parsedLeft = parsedY - parsedX;
			parsedRight = parsedY + parsedX;
		
	}
	else
	{
			parsedLeft = parsedY - parsedX;
			parsedRight = parsedY + parsedX;
	}
	_diffDrive->TankDrive(-parsedLeft, parsedRight, false);

}

void DriveBase::setMotors (double left, double right) {
	FrontL->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, left);
	//BackL->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, left);
	FrontR->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, right);
	//BackR->Set(ctre::phoenix::motorcontrol::ControlMode::MotionMagic, right);
}
void DriveBase::AutoMotors (double position){
	double difference =  position - FrontL->GetSelectedSensorPosition();
	double parsedSpeed = (abs(difference*100)/100>driveBaseError)?driveBaseP * difference:0.0;
	if (abs(100*difference)/100 > driveBaseError){
		parsedSpeed = (parsedSpeed > 0)?parsedSpeed + driveBaseMin:parsedSpeed - driveBaseMin;
	}
	//printf("AutoMotors");
	//printf(static_cast<char*>(parsedSpeed));
	//printf(static_cast<char*>(FrontL->GetSelectedSensorPosition()));
	FrontL->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, parsedSpeed);
}
double DriveBase::returnPosition (){
	return FrontL->GetSelectedSensorPosition();
}

void DriveBase::reverseDrive (bool bButton) {
if (bButton) {
	driveConstant = driveConstant * -1;
}
}
void DriveBase::slowDrive (bool yButton) {
	if (yButton){
		if (speed == 1)
		{
			speed = .5;
		}
		else
		{
			speed = 1;
		}
		
	}
}

// This method will be called once per scheduler run
void DriveBase::Periodic() {
    if(!initialized){
        DriveBaseInit();
    }
}
