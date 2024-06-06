#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void main()
{
    int no_process, no_resource;
    printf("Enter the number of process and number of resources/t:");
    scanf("%d%d",&no_process,&no_resource);
    int Allocation[no_process][no_resource], Need[no_process][no_resource];
    int Max[no_process][no_resource], Work[no_resource], Finished[no_process], Available[no_resource];

    printf("Enter the Allocation Matrix\t:\n");

    for (int i=0; i<no_process; i++)
    {
        for (int j= 0 ; j<no_resource; j++)
        {
            scanf("%d",&Allocation[i][j]);
        }
    }

    printf("Enter the Max Matrix\t:\n");

    for (int i=0; i<no_process; i++)
    {
        for (int j= 0 ; j<no_resource; j++)
        {
            scanf("%d",&Max[i][j]);
        }
    }

    printf("Enter the Available Matrix");

    for (int i=0; i<no_resource; i++)
    {
        scanf("%d",Available[i]);
    }

    //Calculating Need Matrix

    for (int i=0; i<no_process; i++)
    {
        for (int j= 0 ; j<no_resource; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Safe Algorithm

    //Initializing Finished matrix to False (0) and Work matrix with available matrix

    for (int i=0; i<no_process; i++)
    {
        Finished[i] = 0;
    }

    for (int i=0; i<no_resource; i++)
    {
        Work[i] = Available[i];
    }

    int count =0; // Counter variable keeping track of the  number of processes completed.

    while(count <no_process)
    {
        int found =0;
        for (int i=0; i<no_process; i++)
        {
            int flag = 0;
            for (int j=0; j<no_resource; j++)
            {
                if (Need[i][j] > Work[j])   //Cannot allocate.
                {
                    flag = 1;
                    break;
                }
            }
            if (flag ==0)
            {
                for (int k=0; k<no_resource; k++)
                {
                    Work[k] += Allocation[i][k];
                }
                Finished[i] = 1;
                count ++;
                found =1;
            }
        }
        if (found ==0)
        {
            printf("Unsafe state");
        }
    }
    printf("Safe state");
    





}