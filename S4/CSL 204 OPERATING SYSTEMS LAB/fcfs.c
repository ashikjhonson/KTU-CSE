#include <stdio.h>
int n, twt=0, ttat=0;

struct process{
    int pid;
    int at;
    int bt;
    int st;
    int wt;
    int tat;
};

void sort(struct process processes[]){
    int temp;
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(processes[j].at > processes[j+1].at){
                temp = processes[j].at;
                processes[j].at = processes[j+1].at;
                processes[j+1].at = temp;
                
                temp = processes[j].bt;
                processes[j].bt = processes[j+1].bt;
                processes[j+1].bt = temp;

                temp = processes[j].pid;
                processes[j].pid = processes[j+1].pid;
                processes[j+1].pid = temp;
            }
            else if(processes[j].at == processes[j+1].at){
                if(processes[j].bt > processes[j+1].bt){
                    temp = processes[j].bt;
                    processes[j].bt = processes[j+1].bt;
                    processes[j+1].bt = temp;

                    temp = processes[j].pid;
                    processes[j].pid = processes[j+1].pid;
                    processes[j+1].pid = temp;
                }
            }
        }
    }
}

void fcfs(struct process processes[]){
    int totalTime = 0;
    processes[0].wt = 0;
    printf("\n\nGantt chart: ");
    for(int i=0; i<n; i++){
        processes[i].st = totalTime;
        processes[i].wt = processes[i].st - processes[i].at;
        processes[i].tat = processes[i].wt + processes[i].bt;
        totalTime += processes[i].bt;
        
        twt+=processes[i].wt;
        ttat+=processes[i].tat;
        printf("[%d]", totalTime);   
    }
    float awt = (float)twt/n;
    float atat = (float)ttat/n;
    printf("\nAWT:%.2f\nATAT:%.2f", awt, atat);       
}


int main(){
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    struct process processes[n];
    for(int i=0; i<n; i++){
        printf("\nProcess %d: ", i+1);
        scanf("%d%d", &processes[i].at, &processes[i].bt);
        processes[i].pid = i+1;
        processes[i].wt=0;
        processes[i].tat=0;
    }
    sort(processes);
    for(int i=0; i<n; i++)
        printf("\nP%d: || AT:%d || BT:%d", processes[i].pid, processes[i].at, processes[i].bt);

    fcfs(processes);
    return 0;
}