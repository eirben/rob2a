#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, armEncoder,     sensorQuadEncoder)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rightMotor,    tmotorVex393, openLoop)

void remote_control_arm(){
	int power = 30;
	while(1 == 1)
	{
		if(vexRT[Btn6D] == 1){
			motor[armMotor]  = power;
		}
		else if(vexRT[Btn6U] == 1){
			motor[armMotor]  = -power;
		}
		else {
			motor[armMotor] = 0;
		}
	}
}

task main()
{
	remote_control_arm();
}