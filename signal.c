/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
//Joshua Clemons

int alarmTrigged = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5);

  
  alarmTrigged =1;
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 1 second
  while(!alarmTrigged)
    ; //busy wait for signal to be delivered
  printf("Turing Was Right!\n");
  return 0; //never reached
}

