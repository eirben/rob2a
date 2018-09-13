#pragma config(Sensor, dgtl3,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port1,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port10,           leftMotor,     tmotorNormal, openLoop)


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
int dist = 0;

void drive(int dist){ // svo hann keyrir beint og keyrir afram ad nota encoderana
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
void driveB(int dist){ // her er hann ad niota encoderana til ad keyra afturabak og keyra beint
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
void stopmotor(){ //stoppa alla motora
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
  dist += 500;
	drive(dist);

	}
	else{
	driveB(dist);

	}
	stopmotor();


	}
}
