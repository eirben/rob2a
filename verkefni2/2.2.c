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

/* verkefni 2.2
Neptunus / Isar

radius hjóla eru 2 tommur, ummál er því 12,57 tommur eða 32cm
Til að ná 50cm þarf 50/31,93 = 1,566 snúninga eða 1,566*360 gráður = 564 gráður
*/
void drive(int power = 127) {
	motor[rightMotor] = motor[leftMotor] = power;
}

task main()
{
  const int HALF_METER = 564;
  wait1Msec(100);
  for(int i = 1; i<=5; i++) {
  	SensorValue[rightEncoder] = SensorValue[leftEncoder] = 0;
  	while(abs(SensorValue[leftEncoder]) < i * HALF_METER) {
	    drive();
	  }
	  // comment
	  while(SensorValue[leftEncoder] < 0) { // doesn't stop despite value going over 0 - not sure how to proceed
	    drive(-127);
	  }
  }
}
