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


/* verkefni 2.3
Neptunus / Isar

Utreikningar:
Fjarlægð milli hjóla horn í horn eru 33cm - því er ummál hrings eru um 104cm
til að snúast um 90 gráður þarf hvert hjól að ferðast um einn fjórðung hrings, eða 26cm
26/32 = 0,8125
0,8125 * einn hringur(360) = 292
*/

void drive(int right_speed = 127, int left_speed = 127) {
	motor[rightMotor] = right_speed;
	motor[leftMotor]  = left_speed;
}

void turn(int right_speed, int left_speed) {
	const int ONE_FOURTH_ROTATION = 292;
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
	const int HALF_METER = 564;
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
	drive_half_meter();
	turn_left();
	drive_half_meter();
	turn_right();
	drive_half_meter();
	turn_right();
	drive_half_meter();
}
