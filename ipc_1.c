#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
    key_t key; int shmid; char *ptr , *shm;
    key = ftok("shmfile", 'R');
    shmid = shmget(key, 1024, IPC_CREAT|0666);
    shm = shmat(shmid, NULL, 0);

    ptr = shm;
    printf(ptr);

    shmdt(shm);

}