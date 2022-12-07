/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
//Joshua Clemons

int alarmTrigged = 0;
int num_of_alarms = 0;

time_t start,stop;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmTrigged = 1;
  num_of_alarms++;
  //exit(1); //exit after printing
}

void handler2(int signum) // CTRL-C
{ //signal handler
  int totaltime;
  stop = time(NULL);
  totaltime = stop - start;  
  printf("Number Of Alarms %d in %d secs\n", num_of_alarms, totaltime);

}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM 
  signal(SIGINT,handler2); //register handler to handle SIGINT
  start = time(NULL);
  while(1)
  {
    alarmTrigged = 0;
    alarm(1); //Schedule a SIGALRM for 1 second
    while(!alarmTrigged)
      ; //busy wait for signal to be delivered
    printf("Turing Was Right!\n");
  }
  return 0; //never reached
}