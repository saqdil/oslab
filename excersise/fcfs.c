#include <stdio.h>

int main() {
    int n, arrival[10], burst[10], waiting[10], turnaround[10];

    // User Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival & Burst Time: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    // Calculate Waiting & Turnaround Time
    waiting[0] = 0; // First process has no wait time
    turnaround[0] = burst[0];

    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];  // Next waiting time = Previous waiting + Previous burst
        turnaround[i] = waiting[i] + burst[i];  // Turnaround = Waiting + Burst
    }

    // Print Results
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);

    return 0;
}
