#include <stdio.h>
struct Process {
    int id;
    int arrival;
    int burst;
    int start;
    int waiting;
    int turnaround;
};
int main() {
    int n;
    struct Process p[10];
    int total_wait = 0, total_turnaround = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    // Input
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }
    // Sort by arrival time
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    // Calculate times
    int current_time = 0;
    for(int i = 0; i < n; i++) {
        if(current_time < p[i].arrival)
            current_time = p[i].arrival;

        p[i].start = current_time;
        p[i].waiting = p[i].start - p[i].arrival;
        p[i].turnaround = p[i].waiting + p[i].burst;
        current_time += p[i].burst;
        printf("\nP %d|",p[i].id);
        total_wait += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }
    // Output table
    printf("\nPID\tArrival\tBurst\tStart\tWaiting\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival, p[i].burst,
               p[i].start, p[i].waiting, p[i].turnaround);
    }
    // Gantt chart
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < n; i++) {
        printf(" P%d |", p[i].id);
    }
    printf("\n0");
    for(int i = 0; i < n; i++) {
        printf("   %d", p[i].start + p[i].burst);
    }
    printf("\n\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);
    return 0;
}
