#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int bursttime;
};

void RoundRobin(struct Process p1[], int no_process, int time)
{
    int wait[no_process], remain[no_process], turn[no_process];
    int flag = 0, count = 0, cur_time = 0;

    //Initializing the arrays

    for (int i=0; i<no_process; i++)
    {
        remain[i] = p1[i].bursttime;
        wait[i] = 0;
        turn[i] = 0;
    }

    //Iterating through the array
    while (count<no_process)
    {
        flag = 0;
        for (int i=0; i<no_process; i++)
        {
            if (remain[i]>0)
            {
                flag = 1;
                if (remain[i]<= time )           //Process can be fully allocated and is completed.
                {
                    cur_time+=remain[i];
                    remain[i] = 0;
                    turn[i] = cur_time;
                    wait[i] = turn[i] - p1[i].bursttime;
                    count++;
                }
                else                        //Time required is more than time quantum
                {
                    cur_time+=time;
                    remain[i]-=time;

                }
            }
        }
        if (flag==0)
        break;
    }

    float awt=0;
    float atat=0;
    for(int i=0;i<no_process;i++)
    {
        awt=awt+wait[i];
        atat=atat+turn[i];
    }
    printf("Average WT=%f Average TAT=%f",awt/no_process,atat/no_process);
    
    
    
}

void main()
{
    int no_process;
    printf("Enter the number of processes\t:");
    scanf("%d",&no_process);

    struct Process p1[no_process];

    printf("Enter the pid and burst time for the processes\n");
    for (int i=0 ; i<no_process; i++)
    {
        scanf("%d%d",&p1[i].pid, &p1[i].bursttime);
    }
    printf("Enter the time quantum for the algorithm\t:");
    int time;
    scanf("%d",&time);
    RoundRobin(p1,no_process,time);
    
}