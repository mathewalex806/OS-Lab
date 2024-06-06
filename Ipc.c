#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
    key_t key; 
    int shmid;
    char *shm ,*ptr;

    key = ftok("shmfile", 'R');
    shmid = shmget(key, 1024, IPC_CREAT|0666);
    shm = shmat(shmid, NULL, 0);
    ptr = shm;
    sprintf(ptr,"This is writing into the shared memory");
    printf("Writing completed.");
    printf(ptr);
    shmdt(shm);
}