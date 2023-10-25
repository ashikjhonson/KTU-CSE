/*
 * Program to implement memory allocation algorithms in C
 *
 * Ashik Jhonson
 * 14-06-2023 
*/

#include <stdio.h>
#include <limits.h>
int n_partition, n_process;

void firstFit(int process[], int partitionsArray[]){
    // making a copy
    int partitions[n_partition];
    for(int i=0; i<n_partition; i++){
        partitions[i] = partitionsArray[i];
    }

    for(int i=0; i<n_process; i++){
        for(int j=0; j<n_partition; j++){
            if(process[i]<=partitions[j]){
                printf("%d KB is put in %d KB partition\n", process[i], partitions[j]);
                partitions[j] -= process[i];
                break;
            }   
            if(j==n_partition-1){
                printf("%d KB has to wait\n", process[i]);
            }
        }        
    }
}

void bestFit(int process[], int partitionsArray[]){    
    // making a copy
    int partitions[n_partition];
    for(int i=0; i<n_partition; i++){
        partitions[i] = partitionsArray[i];
    }    

    // finding best fit
    int bestFitPartition, index;
    for(int i=0; i<n_process; i++){     
        bestFitPartition = INT_MAX;           
        for(int j=0; j<n_partition; j++){
            if(process[i]<=partitions[j] && partitions[j]<bestFitPartition){
                bestFitPartition =  partitions[j];
                index = j;
            }                
        }
        if(bestFitPartition && bestFitPartition!=INT_MAX){
            printf("%d KB is put in %d KB partition\n", process[i], partitions[index]);
            partitions[index] -= process[i];
        }
        else{
            printf("%d KB has to wait\n", process[i]);
        }
    }
}

void worstFit(int process[], int partitionsArray[]){    
    // making a copy
    int partitions[n_partition];
    for(int i=0; i<n_partition; i++){
        partitions[i] = partitionsArray[i];
    }    
    for(int i=0; i<n_process; i++){
        int worstFitPartition = 0, index;
        // finding worst fit
        for(int j=0; j<n_partition; j++){
            if(process[i]<=partitions[j] && partitions[j]>worstFitPartition){                
                worstFitPartition =  partitions[j];
                index = j;                           
            }                
        }
        if(worstFitPartition){
            printf("%d KB is put in %d KB partition\n", process[i], partitions[index]);
            partitions[index] -= process[i];
        }
        else{
            printf("%d KB has to wait\n", process[i]);
        }
    }
}

int main(){
    printf("Enter no. of partitions: ");
    scanf("%d",&n_partition);
    
    int partitionsArray[n_partition];
    
    printf("Enter available partitions below (size in kb):\n");
    for(int i=0; i<n_partition; i++){
        scanf("%d",&partitionsArray[i]);
    }
    
    printf("\nEnter no. of processes: ");
    scanf("%d",&n_process);
    
    int processArray[n_process];
    
    printf("Enter processes below (size in kb):\n");
    for(int i=0; i<n_process; i++){
        scanf("%d",&processArray[i]);
    }    

    printf("\nAvailable partitions --> ");
    for(int i=0; i<n_partition; i++){
        printf("%d\t",partitionsArray[i]);
    }  

    printf("\nProcesses --> \t");
    for(int i=0; i<n_process; i++){
        printf("%d\t",processArray[i]);
    }
    
    printf("\n\nFirst Fit allocation\n");
    firstFit(processArray, partitionsArray);

    printf("\nBest Fit allocation\n");
    bestFit(processArray, partitionsArray);
    
    printf("\nWorst Fit allocation\n");
    worstFit(processArray, partitionsArray);

    return 0;
}