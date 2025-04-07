#include <stdio.h>

int main() {
    int n, arrival[10], burst[10], priority[10], waiting[10], turnaround[10], pid[10];
    int i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d Arrival, Burst, Priority: ", i + 1);
        scanf("%d %d %d", &arrival[i], &burst[i], &priority[i]);
    }

    // Sort by priority (lower value = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp;
                temp = priority[j]; priority[j] = priority[j + 1]; priority[j + 1] = temp;
                temp = burst[j]; burst[j] = burst[j + 1]; burst[j + 1] = temp;
                temp = arrival[j]; arrival[j] = arrival[j + 1]; arrival[j + 1] = temp;
                temp = pid[j]; pid[j] = pid[j + 1]; pid[j + 1] = temp;
            }
        }
    }

    waiting[0] = 0;
    turnaround[0] = burst[0];

    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
        turnaround[i] = waiting[i] + burst[i];
    }

    printf("\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", pid[i], arrival[i], burst[i], priority[i], waiting[i], turnaround[i]);
    }

    return 0;
}
