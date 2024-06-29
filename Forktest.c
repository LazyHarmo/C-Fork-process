#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int temp = 10;
  pid_t pid;
  /* fork a child process */
  pid = fork();   // return 0 to the child process
                  // whereas the nonzero process id of
                  // the child is returned to the parent

  if(pid < 0) { /* error occurred */
     fprintf(stderr,"Fork Failed");
     exit(-1);
  }
  else if(pid == 0) {  /* child process */
    // sleep(5);
    printf("This is a child process. pid = %d, parent pid = %d\n",getpid(),getppid());
    sleep(2);
    printf("This is a child process. I woke up! \n");
    //execlp("/bin/ls","ls",NULL);
    //while(1)
    //  temp++;
    //printf("CHILD: temp = %d\n",temp);
  }
  else { /* parent process*/
    sleep(5);
    printf("This is a parent process. pid = %d, child pid = %d\n",getpid(),pid);
    /* parent will wait for the child to complete */
    wait(NULL);
    printf("PARENT: Child Complete.\n");
    printf("PARENT: temp = %d\n",temp);
    exit(0);
  }
}