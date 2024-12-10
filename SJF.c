#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

int compare_by_arrival(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    if (p1->arrival_time == p2->arrival_time)
        return p1->burst_time - p2->burst_time;
    return p1->arrival_time - p2->arrival_time;
}

void non_preemptive_sjf(Process *processes, int n) {
    qsort(processes, n, sizeof(Process), compare_by_arrival);
    int current_time = 0;
    printf("\nNon-Preemptive SJF Gantt Chart:\n");

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;

        printf("| %d P%d %d ", current_time, processes[i].pid, current_time + processes[i].burst_time);

        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    printf("\n\nProcess Table:\n");
    printf("| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    for (int i = 0; i < n; i++) {
        printf("|   P%d    |     %d       |     %d     |        %d       |        %d      |      %d     |\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

void preemptive_sjf(Process *processes, int n) {
    qsort(processes, n, sizeof(Process), compare_by_arrival);
    int current_time = 0, completed = 0;

    printf("\nPreemptive SJF Gantt Chart:\n");

    while (completed < n) {
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest == -1 || processes[i].remaining_time < processes[shortest].remaining_time)
                    shortest = i;
            }
        }

        if (shortest != -1) {
            printf("| %d P%d %d ", current_time, processes[shortest].pid, current_time + 1);
            processes[shortest].remaining_time--;
            current_time++;

            if (processes[shortest].remaining_time == 0) {
                processes[shortest].completion_time = current_time;
                processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
                processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
                completed++;
            }
        } else {
            current_time++;
        }
    }

    printf("\n\nProcess Table:\n");
    printf("| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    for (int i = 0; i < n; i++) {
        printf("|   P%d    |     %d       |     %d     |        %d       |        %d      |      %d     |\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    Process processes[] = {
        {1, 0, 8, 8, 0, 0, 0},
        {2, 1, 4, 4, 0, 0, 0},
        {3, 2, 9, 9, 0, 0, 0},
        {4, 3, 5, 5, 0, 0, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("Non-Preemptive SJF Scheduling\n");
    non_preemptive_sjf(processes, n);

    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time; // Reset remaining time for preemptive scheduling
    }

    printf("\n\nPreemptive SJF Scheduling\n");
    preemptive_sjf(processes, n);

    return 0;
}
