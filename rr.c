#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
};

void fcfs(struct Process processes[], int n) {
    int current_time = 0;
    float total_waiting_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += current_time - processes[i].arrival_time;
        current_time = (current_time > processes[i].arrival_time) ? 
                        current_time + processes[i].burst_time : 
                        processes[i].arrival_time + processes[i].burst_time;
    }

    float average_waiting_time = total_waiting_time / n;
    printf("FCFS Average Waiting Time: %.2f\n", average_waiting_time);
}

void sjf(struct Process processes[], int n) {
    int current_time = 0;
    float total_waiting_time = 0;

    // Sort processes based on arrival time and burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time == processes[j + 1].arrival_time) {
                if (processes[j].burst_time > processes[j + 1].burst_time) {
                    struct Process temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            } else if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        total_waiting_time += current_time - processes[i].arrival_time;
        current_time = (current_time > processes[i].arrival_time) ? 
                        current_time + processes[i].burst_time : 
                        processes[i].arrival_time + processes[i].burst_time;
    }

    float average_waiting_time = total_waiting_time / n;
    printf("SJF Average Waiting Time: %.2f\n", average_waiting_time);
}

void non_preemptive_priority(struct Process processes[], int n) {
    int current_time = 0;
    float total_waiting_time = 0;

    // Sort processes based on arrival time and priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time == processes[j + 1].arrival_time) {
                if (processes[j].priority > processes[j + 1].priority) {
                    struct Process temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            } else if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        total_waiting_time += current_time - processes[i].arrival_time;
        current_time = (current_time > processes[i].arrival_time) ? 
                        current_time + processes[i].burst_time : 
                        processes[i].arrival_time + processes[i].burst_time;
    }

    float average_waiting_time = total_waiting_time / n;
    printf("Non-preemptive Priority Average Waiting Time: %.2f\n", average_waiting_time);
}

void round_robin(struct Process processes[], int n, int time_quantum) {
    int current_time = 0;
    float total_waiting_time = 0;

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;
                if (processes[i].remaining_time > time_quantum) {
                    total_waiting_time += current_time - processes[i].arrival_time;
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    total_waiting_time += current_time - processes[i].arrival_time;
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    float average_waiting_time = total_waiting_time / n;
    printf("Round Robin Average Waiting Time: %.2f\n", average_waiting_time);
}

int main() {
    struct Process processes[] = {
        {1, 0, 5, 5, 3},
        {2, 1, 3, 3, 1},
        {3, 2, 8, 8, 2},
        {4, 3, 6, 6, 4}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    int time_quantum = 3;

    fcfs(processes, n);
    sjf(processes, n);
    non_preemptive_priority(processes, n);
    round_robin(processes, n, time_quantum);

    return 0;
}
