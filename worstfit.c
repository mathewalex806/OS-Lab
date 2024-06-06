#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Worstfit(int process[], int no_process , int block[], int no_block, int Allocation[])
{

    //Initial Config.
    for(int i = 0; i < no_process; i++)
    {
    Allocation[i] = -1;
    }

    //Finding the Worst Index.
    for(int i=0; i<no_process; i++)
    {
        int worstIndex = -1;
        for (int j=0; j<no_block; j++)
        {
            if (block[j]>= process[i])
            {
                if (worstIndex == -1 || block[worstIndex]<= block[j])
                {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex!=-1)
        {
            Allocation[i] = worstIndex;
            block[worstIndex]-= process[i];
        }
    }

    //Printing the values

    printf("No\t\tProcess Size\t\tBlock No:\n");
    for (int i=0; i<no_process; i++)
    {
        if (Allocation[i]!= -1)
        {
            printf("%d\t\t%d\t\t%d\t\n",(i+1),process[i],Allocation[i]+1);
        }
        
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\t\n",(i+1),process[i]);
        }
        
    }

    /*
    for(int i = 0; i < no_process; i++)
    {
        printf("%d ", Allocation[i]);
    }
    printf("\n");
    */

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

    Worstfit(process, no_process, blocks,no_block, allocation);
}