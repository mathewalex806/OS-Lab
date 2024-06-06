#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
    key_t key;
    key = ftok("shmfile", 'R');
    int shmid = shmget(key, 1024, IPC_CREAT|0666);

    pid_t child = fork();

    if (child<0)
    {
        printf("Failed to create a child");
        exit(EXIT_FAILURE);
    }
    else if(child == 0)
    {
        //Child Process
        char *shm = shmat(shmid, NULL,0);
        printf("Starting the reading process.\n");
        printf(shm);
        shmdt(shm);
        exit(EXIT_SUCCESS);
    }
    else
    {
        //Parent process
        char *shm = shmat(shmid, NULL, 0);
        printf("\nStarting the writing process.\n");
        sprintf(shm,"Hello,world2");
        printf("\nFinished writing process.\n");
        wait(NULL);
        shmdt(shm);
        exit(EXIT_SUCCESS);
    }

}