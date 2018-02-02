#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    right_lineFollower, sensorLineFollower)
#pragma config(Sensor, in4,    center_lineFollower, sensorLineFollower)
#pragma config(Sensor, in5,    left_lineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  stop_button,    sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)
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
task main()
{
  wait1Msec(100);

  //Clear Encoders

  for(int i = 1; i<=5; i++) {
  	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	while(SensorValue[leftEncoder] > -564*i)  // While less than 5 rotations on the leftEncoder...
	  {
	    //...Move Forward
	    motor[rightMotor] = 127;
	    motor[leftMotor] = 127;
	  }
	  while(SensorValue[leftEncoder] <= 0)  // While less than 5 rotations on the leftEncoder...
	  {
	    //...Move Backward
	    motor[rightMotor] = -127;
	    motor[leftMotor] = -127;
	  }
  }
}
