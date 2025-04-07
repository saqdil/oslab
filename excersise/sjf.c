#include <stdio.h>

int main() {
    int n, arrival[10], burst[10], waiting[10], turnaround[10], pid[10];

    // User Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1; // Assign Process ID
        printf("Process %d Arrival & Burst Time: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    // Sort processes by Burst Time (Simple Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst[j] > burst[j + 1]) { 
                // Swap Burst Time
                int temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
                // Swap Arrival Time
                temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;
                // Swap Process ID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Calculate Waiting & Turnaround Time
    waiting[0] = 0; 
    turnaround[0] = burst[0];

    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];  
        turnaround[i] = waiting[i] + burst[i];  
    }

    // Print Results
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], arrival[i], burst[i], waiting[i], turnaround[i]);

    return 0;
}
