#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int bursttime;
    int arrivaltime;
    int waittime;
    int turnaround;
};

void main()
{
    int no_of_process;
    printf("Enter the number of processes for SJF\t :");
    scanf("%d",&no_of_process);
    struct Process p1[no_of_process];
    
    for (int i=0; i<no_of_process; i++)
    {
        printf("Enter the Burst time and Arrival time of process %d",(i+1));
        scanf("%d%d",&p1[i].bursttime,&p1[i].arrivaltime);
        p1[i].pid = i+1;
        p1[i].waittime = 0;
        p1[i].turnaround = 0;
    }

    //Sorting function

    for (int i=0; i<no_of_process-1; i++)
    {
        for (int j=0; j<no_of_process-1-i; j++)
        {
            if (p1[j].bursttime>p1[j+1].bursttime)
            {
                struct Process temp = p1[j];
                p1[j]= p1[j+1];
                p1[j+1] = temp;
            }
        }
    }

    // Calculating wait time and turnaround time.
    int totalwait =0;
    for (int i=0; i<no_of_process; i++)
    {
        p1[i].waittime = totalwait;
        totalwait += p1[i].bursttime;
        p1[i].turnaround = totalwait-p1[i].arrivaltime;
    }

    printf("\nPid\t\tArrival Time\t\t Burst Time\t\t  Turnaround time\t\tWaiting time\n");
    for (int i=0; i<no_of_process; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p1[i].pid,p1[i].arrivaltime,p1[i].bursttime,p1[i].turnaround,p1[i].waittime);
    }
  
}