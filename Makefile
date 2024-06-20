main: main.o acturator.o sensor.o as.o
	gcc -o main main.o acturator.o sensor.o as.o -l wiringPi -pthread -lmysqlclient


main.o: out.h main.c
	gcc -c main.c -l wiringPi -pthread

acturator.o: out.h acturator.c
	gcc -c acturator.c -l wiringPi

sensor.o: out.h sensor.c
	gcc -c sensor.c -l wiringPi

as.o: as.s
	as -o as.o as.s
clean:
	rm *.o main
