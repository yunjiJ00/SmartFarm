#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>
#include <mysql/mysql.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#define DBHOST "127.0.0.1"
#define DBUSER "root"
#define DBPASS "root"
#define DBNAME "team1"

#define FAN 22
#define DCMOTOR  23	
#define MOTION_IN 0
#define MAXTIMINGS 85 //TEMP,HUMID

static int DHTPIN =11;
static int dht22_dat[5] = {0,0,0,0,0};
int ret_humid, ret_temp;
void myInterrupt(void);
void pinmodeset(void);
char query[1024];

MYSQL *connector;
MYSQL_RES *result;
MYSQL_ROW row;
int temper, humid;

int wiringPicheck(void);
int wiringPiSPIcheck(void);
extern int team1(void);
void *sensor123();
void get_temperature_sensor();
void get_humidity_sensor();
int read_dht22_dat_temp();
int read_dht22_dat_humid();
static uint8_t sizecvt(const int read);
void act_fan_on();
void act_fan_off();
void act_motor_on();
void act_motor_off();
void sig_handler(int signo);
