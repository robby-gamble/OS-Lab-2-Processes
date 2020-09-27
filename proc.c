#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define MAX 2
void main(int argc, char *argv[]){
	
	int pid[MAX];
  int status;
  int i;
  int j;
  int k;
  time_t t;
  
  
  for(i = 0; i < MAX; i++){
    

    pid[MAX] = fork(); //Fork make a child and return two different numbers.

    switch(pid[MAX]){
      case  0:            //Child
        srand((unsigned) time(&t));
        for(k = 0; k<rand()%30; k++){
           printf("Child Pid: %d is going to sleep!\n",getpid());
            sleep(rand()%10);
            printf("Child Pid: %d is awake!  Where is my Parent: %d\n",getpid(),getppid());
        }
        exit(0); //When it is done it will exit successfully.
        break;

      case -1:             //error
        break;

      default:             //Parent, pid is child's pid

        break;
    }
  }
  
  for(j = 0; j < MAX; j++){
    wait(&status);  // We want the parent to wait until the child is done, and removes the child info. 
    printf("Child Pid: %d has completed...\n", pid[MAX]);
  }
	printf("Parent Terminating! Child status: %d\n", status);
}
