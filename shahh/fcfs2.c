#include <stdio.h>

int main() {
    int n, arrival[10], burst[10], waiting[10], turnaround[10], completion[10];

    // User Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival & Burst Time: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    // FCFS Scheduling - Corrected Waiting Time Calculation
    completion[0] = arrival[0] + burst[0];  // First process completes at its arrival + burst time
    turnaround[0] = completion[0] - arrival[0];
    waiting[0] = turnaround[0] - burst[0];

    for (int i = 1; i < n; i++) {
        // Ensure CPU waits for process if it arrives later
        if (arrival[i] > completion[i - 1]) {
            completion[i] = arrival[i] + burst[i];
        } else {
            completion[i] = completion[i - 1] + burst[i];
        }
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    // Print Results
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);

    return 0;
}
