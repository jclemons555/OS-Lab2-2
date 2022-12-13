//Joshua Clemons
/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

time_t start, end;
int wait = 1;

void alrm_handler(int signum) {
  printf("SIGALRM Triggered!\n");
  wait = 0;
}

void sigint_handler(int signum) {
  time(&end);
  int time_elapsed =  end - start;
  printf("\nTime Elapsed: %d seconds\n", time_elapsed);
  exit(1);
}


int main(int argc, char * argv[]) {
  signal(SIGINT, sigint_handler);
  signal(SIGALRM, alrm_handler);
  time(&start);
  while (1) {
    alarm(1);
    while(wait);
    wait = 1;
  }
  return 0;
}