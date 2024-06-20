#include "out.h"

pthread_t threads[1];

int main(void){
	int i;
	int rc;
	int status;
	int thread_id, thread_id0;

	
	if(wiringPicheck()) printf("fail");


	connector = mysql_init(NULL);
	if(!mysql_real_connect(connector, DBHOST,DBUSER,DBPASS,DBNAME,3306,NULL,0))
	{
		fprintf(stderr,"%s\n",mysql_error(connector));
		return 0;
	}
	team1();
	printf("MySQL(rpidb),opened.\n");
	signal(SIGINT, (void *)sig_handler);
	
	thread_id = pthread_create(&threads[0],NULL,sensor123(),NULL);
	while(1);
	return 0;
}

void sig_handler(int signo)
{
	printf("process stop");
	act_motor_off();

	act_fan_off();
	exit(0);
}


	