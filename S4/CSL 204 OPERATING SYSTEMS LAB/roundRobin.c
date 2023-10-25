#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int burst_time;
    int remaining_bt;
};

void roundRobin(struct Process p[], int n, int quantum) {
    int total_time = 0;
    int completed = 0; 
    
    // Initialize remaining burst time for all processes
    for (int i = 0; i < n; i++) {
        p[i].remaining_bt = p[i].burst_time;
    }
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_bt > 0) {
                int execution_time = (p[i].remaining_bt < quantum) ? p[i].remaining_bt : quantum;                                
                p[i].remaining_bt -= execution_time;
                total_time += execution_time;
                printf("Executing process %d for %d units of time. Remaining burst time: %d\n",
                       p[i].pid, execution_time, p[i].remaining_bt);
                
                if (p[i].remaining_bt == 0) {
                    completed++;
                }
            }
        }
    }
    
    printf("Total execution time: %d\n", total_time);
}

int main() {
    int n;  
    struct Process p[MAX_PROCESSES];
    int quantum;
    
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

