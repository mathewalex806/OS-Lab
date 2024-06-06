#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    for (int i=0; i<3; i++)
    {
        pid_t p= fork();
        if (p<0)
        {
            printf("Failed to create a child\n");
            exit(EXIT_FAILURE);
        }
        
        else if (p==0)
        {
            //child process
            printf("Child Process Pid (%d) created by parent process Pid (%d)\n", getpid(),getppid());
            exit(EXIT_SUCCESS);
        }
    }
    for (int i=0; i<100; i++)
    {
        wait(NULL);
    }
    printf("Parent process completed %d",getpid());
}
