#include <stdio.h>
#include <limits.h>
int n, twt=0, ttat=0;

struct process{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    int rt;
    int completed;
};

void srtf(struct process processes[]){
    int currentTime=0;
    int completedProcess = 0;
    int sjIndex, sjBurstTime;

    while(completedProcess<n){
        sjIndex=-1;
        sjBurstTime=INT_MAX;

        for(int i=0; i<n; i++){
            if(processes[i].at < currentTime && processes[i].rt > 0){
                if(processes[i].rt < sjBurstTime){
                    sjIndex=i;
                    sjBurstTime=processes[i].rt;
                }
            }
        }

        if(sjIndex==-1){
            currentTime++;
            continue;
        }

        processes[sjIndex].rt--;    

        if(processes[sjIndex].rt==0){
            processes[sjIndex].wt = currentTime-processes[sjIndex].bt-processes[sjIndex].at;
            processes[sjIndex].tat = processes[sjIndex].wt + processes[sjIndex].bt;
            completedProcess++;
            printf("%d\t", currentTime);
        }
        currentTime++;
    }
    printf("\nGantt: \n");

    for(int i=0; i<n; i++){
        printf("%d\t%d\n", processes[i].wt, processes[i].tat);
        twt+=processes[i].wt;
        ttat+=processes[i].tat;
    }
    printf("TWT: %d\tTTAT%d", twt, ttat);
}

int main(){
    printf("Enter no. of processes: ");
    scanf("%d",&n);

    struct process processes[n];

    for(int i=0; i<n; i++){
        scanf("%d%d",&processes[i].at,&processes[i].bt);        
        processes[i].completed = 0;
        processes[i].rt = processes[i].bt;
    }

    srtf(processes);
    return 0;
}