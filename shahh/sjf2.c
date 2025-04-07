#include <stdio.h>

int main() {
    int n, arrival[10], burst[10], waiting[10], turnaround[10], pid[10];
    int completed = 0, current_time = 0, i, j, min_index;
    int done[10] = {0}; // Marks completed processes

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d Arrival & Burst Time: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    while (completed < n) {
        int min_burst = 9999;
        min_index = -1;

        for (i = 0; i < n; i++) {
            if (!done[i] && arrival[i] <= current_time && burst[i] < min_burst) {
                min_burst = burst[i];
                min_index = i;
            }
        }

        if (min_index != -1) {
            waiting[min_index] = current_time - arrival[min_index];
            current_time += burst[min_index];
            turnaround[min_index] = waiting[min_index] + burst[min_index];
            done[min_index] = 1;
            completed++;
        } else {
            current_time++;
        }
    }

    // Output
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    return 0;
}
