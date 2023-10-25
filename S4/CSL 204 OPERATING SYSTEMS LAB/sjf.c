#include <stdio.h>
#include <limits.h>

struct Process {
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int completed;
};

void calculateTimes(struct Process processes[], int n) {
        int currentTime = 0;
        int completedProcesses = 0;
        int sjIndex, sjBurstTime;

        while(completedProcesses<n){
            sjIndex = -1;
            sjBurstTime = INT_MAX;

            for(int i=0; i<n; i++){
                if(processes[i].arrivalTime <= currentTime && !processes[i].completed){
                    if(sjBurstTime > processes[i].burstTime){
                        sjIndex = i;
                        sjBurstTime = processes[i].burstTime;
                    }
                }
            }

            if(sjIndex==-1){
                currentTime++;
                continue;
            }

            processes[sjIndex].waitingTime = currentTime - processes[sjIndex].arrivalTime;
            processes[sjIndex].turnaroundTime = processes[sjIndex].burstTime + processes[sjIndex].waitingTime;
            currentTime+= processes[sjIndex].burstTime;
            printf("%d\t", currentTime);            
            completedProcesses++;
            processes[sjIndex].completed = 1;
        }

        int twt=0, ttat=0;
        printf("AWT=%.2f\nATAT=%.2f", (float)twt, (float)ttat);
}




int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    printf("Enter burst time and arrival time for each process:\n");
    
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
        processes[i].completed = 0;
    }
    
    calculateTimes(processes, n);

    int tt=0, wt=0, twt=0, ttt=0;

    printf("\nPROCESS BURST ARRIVAL WAITING TURNAROUND");
	for(int i=0;i<n;i++)
	{
		tt=processes[i].waitingTime + processes[i].burstTime;
		
		twt+=processes[i].waitingTime;
		ttt+=tt;
		printf("\n%d\t%d\t%d\t%d\t%d",i+1,processes[i].burstTime,processes[i].arrivalTime,processes[i].waitingTime,tt);
	}
    printf("\n%d\n%d", twt, ttt);
        
    return 0;
}
