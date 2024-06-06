#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Bestfit(int process[], int no_process, int block[], int no_block, int Allocation[])
{

    for(int i = 0; i < no_process; i++)
    {
    Allocation[i] = -1;
    }

    for(int i=0; i<no_process; i++)
    {
        int bestIndex = -1;
        for (int j=0; j<no_block; j++)
        {
            if (block[j]>=process[i])
            {
                if (bestIndex==-1 ||block[j]<block[bestIndex])
                {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex!=-1)
        {
            Allocation[i] = bestIndex;
            block[bestIndex]-=process[i];
        }
    }

    printf("No\t\tProcess Size\t\tBlock No:\n");
    for (int i=0; i<no_process; i++)
    {
        if (Allocation[i]!= 0)
        {
            printf("%d\t\t%d\t\t%d\t\n",(i+1),process[i],Allocation[i]+1);
        }
        
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\t\n",(i+1),process[i]);
        }
        
    }
}

void main()
{
    int no_process,no_block;
    printf("Enter the Number of Blocks\t:");
    scanf("%d",&no_block);
    printf("Enter the Number of Processes\t:");
    scanf("%d",&no_process);

    int blocks[no_block], process[no_process], allocation[no_process];

    printf("Enter the Block Sizes into the array\t:");
    for(int i=0; i<no_block; i++)
    {
        scanf("%d",&blocks[i]);
    }

    printf("Enter the Process Sizes into the array\t:");
    for(int i=0; i<no_process; i++)
    {
        scanf("%d",&process[i]);
    }
    
    //Initalizing allocation array to -1 
    memset(allocation, -1, no_process);

    Bestfit(process, no_process, blocks,no_block, allocation);
}
