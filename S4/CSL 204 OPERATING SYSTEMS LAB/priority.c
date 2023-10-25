#include <stdio.h>
int n;
struct process{
    int at, bt, wt, tat, comp, priority;
};

void priority(struct process p[]) {
   int completed = 0, currentTime =0;

   while(completed < n){
    int highest = -1;
    for(int i=0; i<n; i++){
        if(p[i].at <= currentTime && !p[i].comp){
            if(highest==-1 || p[i].priority < p[highest].priority){
                highest = i;
            }
        }
    }

    if(highest==-1){
        currentTime++;
        continue;
    }

    p[highest].comp = 1;
    currentTime += p[highest].bt;
    p[highest].wt = currentTime - p[highest].at - p[highest].bt;
    p[highest].tat = p[highest].wt + p[highest].bt;
    completed++;
   }
}


int main(){
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0; i<n; i++){
        scanf("%d%d%d",&p[i].priority,&p[i].at,&p[i].bt);
        p[i].comp=0;
    }
    priority(p);
    int twt=0, ttat=0;

    for(int i=0; i<n; i++){
        twt+=p[i].wt;
        ttat+=p[i].tat;
    }

    printf("\nAWT: %.2f\tATAT: %.2f", (float)twt/n, (float)ttat/n);
    return 0;
}