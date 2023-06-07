#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;          // Process ID
    int burst_time;   // Burst time of the process
    int remaining_bt; // Remaining burst time of the process
};

void roundRobin(struct Process p[], int n, int quantum) {
    int total_time = 0; // Total execution time
    int completed = 0;  // Number of completed processes
    
    // Initialize remaining burst time for all processes
    for (int i = 0; i < n; i++) {
        p[i].remaining_bt = p[i].burst_time;
    }
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_bt > 0) {
                // Execute the process for the given quantum or its remaining burst time
                int execution_time = (p[i].remaining_bt < quantum) ? p[i].remaining_bt : quantum;
                
                // Update remaining burst time for the process
                p[i].remaining_bt -= execution_time;
                
                // Update total execution time
                total_time += execution_time;
                
                // Print the progress of the execution
                printf("Executing process %d for %d units of time. Remaining burst time: %d\n",
                       p[i].pid, execution_time, p[i].remaining_bt);
                
                if (p[i].remaining_bt == 0) {
                    // The process has completed execution
                    completed++;
                }
            }
        }
    }
    
    printf("Total execution time: %d\n", total_time);
}

int main() {
    int n;             // Number of processes
    struct Process p[MAX_PROCESSES];
    int quantum;       // Quantum time for Round Robin
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i + 1;
    }
    
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);
    
    roundRobin(p, n, quantum);
    
    return 0;
}

