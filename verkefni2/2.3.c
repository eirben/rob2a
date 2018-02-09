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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|
|*                                                                                                    *|
|*
\*-----------------------------------------------------------------------------------------------4246-*/

void drive(int right_speed = 127, int left_speed = 127) {
	motor[rightMotor] = right_speed;
	motor[leftMotor]  = left_speed;
}

void turn(int right_speed, int left_speed) {
	const int ONE_FOURTH_ROTATION = 290;
  //const int ONE_FOURTH_ROTATION = 330;
	SensorValue[rightEncoder] = SensorValue[leftEncoder] = 0;

	while(abs(SensorValue[leftEncoder]) < ONE_FOURTH_ROTATION) {
		drive(right_speed, left_speed);
	}
}

void turn_left() {
	turn(-50, 50);
}

void turn_right() {
	turn(50, -50);
}

void drive_half_meter() {
	//const int HALF_METER = 564;
  const int HALF_METER = 200; // while testing, let's not go too far
	for(int i = 1; i<=2; i++) {
		SensorValue[rightEncoder] = SensorValue[leftEncoder] = 0;
		while(abs(SensorValue[leftEncoder]) < HALF_METER) {
			if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) {
				drive(80,80);
			}
			else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])	{
				drive(60,80);
			}
			else {
				drive(80,60);
			}
		}
	}
}

task main()
{
	//drive_half_meter();
	turn_left();
	//drive_half_meter();
	//turn_right();
	//drive_half_meter();
	//turn_right();
	//drive_half_meter();
}
