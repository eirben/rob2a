#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
int dist = 0;

void drive(int dist){
		SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	while(dist > abs(SensorValue[leftEncoder])){

		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{

			motor[rightMotor] = 80;
			motor[leftMotor]  = 80;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{

			motor[rightMotor] = 60;
			motor[leftMotor]  = 80;
		}
		else
		{

			motor[rightMotor] = 80;
			motor[leftMotor]  = 60;
		}
	}
}
void driveB(int dist){
		SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	while(dist > abs(SensorValue[leftEncoder])){
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{

			motor[rightMotor] = -80;
			motor[leftMotor]  = -80;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
		{

			motor[rightMotor] = -60;
			motor[leftMotor]  = -80;
		}
		else
		{

			motor[rightMotor] = -80;
			motor[leftMotor]  = -60;
		}
	}
}
void stopmotor(){
			motor[rightMotor] = 0;
			motor[leftMotor]  = 0;
			wait1Msec(1500);
	}

task main()
{
	wait1Msec(1000);

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
	for(int i = 1;i<10;i++){

	if(i%2){
  dist += 700;
	drive(dist);

	}
	else{
	driveB(dist);

	}
	stopmotor();

	/*
		dist += 250;
		drive(dist);
		stopmotor();
		dist += 250;
		driveB(dist);
		stopmotor();
		*/
	}
}
