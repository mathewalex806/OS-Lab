#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void firstfit(int Process[], int no_process, int Block[], int no_block, int Allocation[])
{
    memset(Allocation, -1, no_process);
    for (int i=0; i<no_process; i++)
    {
        for (int j=0; j<no_block; j++)
        {
            if (Block[j]>=Process[i])
            {
                Allocation[i] = j;                            //Allocation of the ith Process has been done with the jth block
                Block[j] = Block[j]-  Process[i];
                break;
            }
        }
    }

    //Printing the values 
    printf("No\t\tProcess Size\t\tBlock No:\n");
    for (int i=0; i<no_process; i++)
    {
        if (Allocation[i]!= -1)
        printf("%d\t\t%d\t\t%d\t\n",(i+1),Process[i],Allocation[i]+1);
        else
        printf("%d\t\t%d\t\tNot Allocated\t\n",(i+1),Process[i]);
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

    firstfit(process, no_process, blocks,no_block, allocation);

}