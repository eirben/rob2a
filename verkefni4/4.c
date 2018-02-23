#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, armEncoder,     sensorQuadEncoder)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rightMotor,    tmotorVex393, openLoop)


/* verkefni 4
Neptunus / Isar

Robot turns successfully away from obstacles when they are right in front of it
but it has trouble when approaching walls from acute angles.
I'm considering a solution that involves checking the encoders when the robot is
attempting to drive forward with some frequency, and if their value hasn't
changed by a significant amount then the robot starts a sequence of backing up
and then turning left.
*/

void stop(){
	motor[rightMotor] = motor[leftMotor] = 0;
}

void drive(int right_speed = 127, int left_speed = 127) {
	motor[rightMotor] = right_speed;
	motor[leftMotor]  = left_speed;
}

task solve() {
	int speed;
	int sonar_value;
	int distance = 50;
	while(true) {
		sonar_value = SensorValue(sonarSensor);
		speed = 50;
		if (sonar_value > distance || sonar_value < 0) {
			drive(speed, speed);
		} else {
			stop();
			wait10Msec(100);
			drive(speed, -speed);
			wait10Msec(200);
		}

		clearLCDLine(0);
    displayLCDPos(0,0);
    displayNextLCDString("Sonar: ");
    displayNextLCDNumber(SensorValue(sonarSensor));
	}
}

task main()
{
	StartTask(solve);
	while( !( SensorValue(lightSensor) > 400 || vexRT[Btn8D] ) ){}
	StopAllTasks();
}