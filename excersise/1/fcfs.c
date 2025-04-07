#include <stdio.h>
typedef struct {
int process_id;
int arrival_time;
int burst_time;
int completion_time;
int turnaround_time;
int waiting_time;
} Process;
void FCFS(Process process[], int size) {
int current_time = 0, order[size];
float total_waiting_time = 0, total_turnaround_time = 0;
Process temp;
for (int i = 0; i < size - 1; i++) {
for (int j = i + 1; j < size; j++) {
if (process[i].arrival_time > process[j].arrival_time) {
temp = process[j];
process[j] = process[i];
process[i] = temp;
}
}
}
for (int i = 0; i < size; i++) {
    if (current_time < process[i].arrival_time) {
    current_time = process[i].arrival_time;
    }
    process[i].completion_time = current_time + process[i].burst_time;
    process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
    process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;
    current_time = process[i].completion_time;
    total_turnaround_time += process[i].turnaround_time;
    total_waiting_time += process[i].waiting_time;
    order[i] = process[i].process_id;
    }
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < size; i++) {
    printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
    process[i].process_id, process[i].arrival_time, process[i].burst_time,
    process[i].completion_time, process[i].turnaround_time, process[i].waiting_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / size);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / size);
    }
int main() {
int size;
printf("Enter the number of processes: ");
scanf("%d", &size);
Process process[size];
for (int i = 0; i < size; i++) {
printf("Enter arrival time and burst time for process P%d: ", i + 1);
process[i].process_id = i + 1;
scanf("%d %d", &process[i].arrival_time, &process[i].burst_time);
}
FCFS(process, size);
return 0;
}