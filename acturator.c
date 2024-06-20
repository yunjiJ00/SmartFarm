#include "out.h"


void act_fan_on()
{
	pinMode(FAN,OUTPUT);
	digitalWrite(FAN,1);
}
void act_fan_off()
{
	pinMode(FAN,OUTPUT);
	digitalWrite(FAN,0);
}

void act_motor_on()
{
	pinMode(DCMOTOR,OUTPUT);
  	digitalWrite(DCMOTOR,1);
}

void act_motor_off()
{
	pinMode(DCMOTOR,OUTPUT);
	digitalWrite(DCMOTOR,0);
}

int wiringPicheck()
{
	if(wiringPiSetup()==-1)
	{
		fprintf(stdout,"error",strerror(errno));
		return 1;
	}
}

