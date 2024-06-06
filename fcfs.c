#include <stdio.h>
#include <stdlib.h>

struct Process 
{
    int pid;
    int arrival;
    int bursttime;
    int completiontime;
    int turnaroundtime;
    int waitingtime;
};

void displayProcess(struct Process p1[], int size)
{
    printf("\nPid\t\tArrival Time\t\t Burst Time\t\t Completiontime\t\t Turnaround time\t\tWaiting time\n");
    for (int i=0; i<size; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p1[i].pid,p1[i].arrival,p1[i].bursttime,p1[i].completiontime,p1[i].turnaroundtime,p1[i].waitingtime);
    }
}

void FirstCFS(struct Process p1[], int size)
{
    int current =0;
    for (int i=0; i<size; i++)
    {
        int execution = p1[i].bursttime;
        current+= execution;
        p1[i].completiontime = current;
        p1[i].turnaroundtime = p1[i].completiontime - p1[i].arrival;
        p1[i].waitingtime = p1[i].turnaroundtime - execution;
    }
}

void main()
{
    int no_process;
    printf("Enter the number of processes\t:");
    scanf("%d",&no_process);

    struct Process p1[no_process];


    for (int i=0; i<no_process; i++)
    {
        printf("Enter the Arrival time and Burst time for process %d\t:",i);
        scanf("%d%d",&p1[i].arrival,&p1[i].bursttime);
        p1[i].pid = i;
    }

    FirstCFS(p1,no_process);
    displayProcess(p1,no_process);
}