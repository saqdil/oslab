#include <stdio.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_completed; // New field to track if the process is completed
} Process;

void SJF(Process process[], int size) {
    int total_waiting_time = 0, total_turnaround_time = 0, current_time = 0, completed = 0;

    // Initialize all processes as not completed
    for (int i = 0; i < size; i++) {
        process[i].is_completed = 0;
    }

    while (completed < size) {
        int shortest_job_index = -1;
        int shortest_burst_time = __INT_MAX__;

        // Find the shortest job that has arrived and is not completed
        for (int i = 0; i < size; i++) {
            if (process[i].arrival_time <= current_time && !process[i].is_completed) {
                if (process[i].burst_time < shortest_burst_time) {
                    shortest_burst_time = process[i].burst_time;
                    shortest_job_index = i;
                }
            }
        }

        if (shortest_job_index == -1) {
            // No process has arrived yet, move current_time to the next arrival time
            current_time++;
        } else {
            // Process the shortest job
            int i = shortest_job_index;
            process[i].completion_time = current_time + process[i].burst_time;
            process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
            process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;

            // Update current time and mark the process as completed
            current_time = process[i].completion_time;
            process[i].is_completed = 1;
            completed++;

            // Accumulate total turnaround and waiting times
            total_turnaround_time += process[i].turnaround_time;
            total_waiting_time += process[i].waiting_time;
        }
    }

    // Print process details
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < size; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               process[i].process_id, process[i].arrival_time, process[i].burst_time,
               process[i].completion_time, process[i].turnaround_time, process[i].waiting_time);
    }

    // Print average turnaround time and waiting time
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / size);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / size);
}

int main() {
    int size;
    printf("Enter the number of processes: ");
    scanf("%d", &size);

    Process process[size];
    for (int i = 0; i < size; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        process[i].process_id = i + 1;
        scanf("%d %d", &process[i].arrival_time, &process[i].burst_time);
        process[i].completion_time = process[i].turnaround_time = process[i].waiting_time = 0;
    }

    SJF(process, size);
    return 0;
}