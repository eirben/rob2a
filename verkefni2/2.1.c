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

/* verkefni 2.1
Neptunus / Isar
*/

void stop(int ms = 400){
	motor[rightMotor] = motor[leftMotor] = 0;
	wait1Msec(ms);
}

void driveforward(int timer) {
	SensorValue[rightEncoder] = SensorValue[leftEncoder] = 0;
	int power = 60;
	int lesspower = 50;
	ClearTimer(T1);
	while(time1[T1] < timer) {
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) {
			motor[rightMotor] = motor[leftMotor] = power;
		}
		else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])	{
			motor[rightMotor] = lesspower;
			motor[leftMotor] = power;
		}
		else {
			motor[rightMotor] = power;
			motor[leftMotor] = lesspower;
		}
	}
	stop();
}

void drivebackward(int timer) {
	SensorValue[rightEncoder] = SensorValue[leftEncoder] = 0;
	int power = -60;
	int lesspower = -50;
	ClearTimer(T1);
	while(time1[T1] < timer) {
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) {
			motor[rightMotor] = motor[leftMotor] = power;
		}
		else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])	{
			motor[rightMotor] = lesspower;
			motor[leftMotor] = power;
		}
		else {
			motor[rightMotor] = power;
			motor[leftMotor] = lesspower;
		}
	}
	stop();
}

task main()
{
	int timer = 1000;
	for (int counter = 0; counter < 5; counter++) {
		driveforward(timer);
		drivebackward(timer);
		timer += 1000;
	}
}
