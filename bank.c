#include <stdio.h>

#define MAX_PROC 10
#define MAX_RES 10

int n, m; // Number of processes and resources
int max[MAX_PROC][MAX_RES]; // Maximum resource needs of processes
int alloc[MAX_PROC][MAX_RES]; // Resources currently allocated to processes
int avail[MAX_RES]; // Available resources
int finish[MAX_PROC]; // Array to track if a process is finished

// Function to perform safety check using Banker's Algorithm
int isSafe() {
    int work[MAX_RES], temp_finish[MAX_PROC];
    int i, j;

    // Initialize work[] with available resources
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    // Initialize temp_finish[] to track finished processes
    for (i = 0; i < n; i++) {
        temp_finish[i] = finish[i];
    }

    int count = 0;
    while (count < n) 
    {
        int found = 0;                          // Flag to check if a process can be allocated resources
        for (i = 0; i < n; i++) 
        {
            if (temp_finish[i] == 0) 
            {
                                                // Check if process i can be allocated resources
                int flag=1;
                for (int j = 0; j < m; j++) 
                {
                    if (max[i][j] - alloc[i][j] > work[j]) 
                    {
                        flag=0;
                        break;                  // Not enough resources available for process i
                    }
                }
                if (flag==1) 
                {                           // If all resources can be allocated to process i Mark process i as finished and update work[]
                    for (int k = 0; k < m; k++) 
                    {
                        work[k] += alloc[i][k];
                    }
                    temp_finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0) 
        {
            // If no process can be allocated resources, it's an unsafe state
            return 0;
        }
    }
    // If all processes can be allocated resources safely, it's a safe state
    return 1;
}

// Main function
int main() {
    int i, j;

    // Input number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    // Input maximum resource needs of processes
    printf("Enter maximum resource needs for each process:\n");
    for (i = 0; i < n; i++) {
        printf("For process P%d: ", i);
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input resources currently allocated to processes
    printf("Enter resources currently allocated to each process:\n");
    for (i = 0; i < n; i++) {
        printf("For process P%d: ", i);
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input available resources
    printf("Enter available resources: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Initialize finish[] array
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Perform safety check
    if (isSafe()) {
        printf("System is in safe state. No deadlock detected.\n");
    } else {
        printf("System is in unsafe state. Deadlock detected.\n");
    }

    return 0;
}