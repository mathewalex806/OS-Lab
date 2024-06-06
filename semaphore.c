#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int mutex = 1, full = 0, empty = 5, x = 0;
//Mutex = 1 => lock is available.
void producer()
{
    mutex--;
    x++;
    printf("Process produced : %d",x);
    full++;
    empty--;
    mutex++;
}

void consumer()
{
    mutex--;
    printf("Process consumed : %d",x);
    x--;
    empty++;
    full--;
    mutex++;
}

void main()
{
    int choice;
    bool loop = true;
    while(loop)
    {
        printf("Enter your choice \n1.Producer Process\n2.Consumer Process\n3.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
                if (mutex == 1 && empty!=0){
                    producer();
                    break;
                }
                else{
                    printf("Buffer is full.\n");
                    break;
                }
                
            case 2:
                if (mutex == 1&& full!=0){
                    consumer();
                    break;
                }
                else{
                    printf("Buffer is empty");
                    break;
                }
                
            default:
                loop = false;
                break;
        }
    }
}

