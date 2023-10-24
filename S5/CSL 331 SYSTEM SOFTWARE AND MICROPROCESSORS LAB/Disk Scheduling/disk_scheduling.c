#include <stdio.h>
#include <stdlib.h>

int n, initial, thm =0;

int main(){
    printf("Enter total no. of req: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter requests\n");
    for(int i=0; i<n; i++){
        scanf("%d",&req[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d",&initial);

    // Uncomment the required scheduling

    /* FCFS
    for(int i=0; i<n; i++){
        thm += abs(req[i]-initial);
        initial = req[i];
        printf("%d\t", req[i]);
    }
    printf("\nTotal head movement: %d", thm);
    */

    /* SCAN
    int cylinders, temp, pos;
    printf("Enter no. of cylinders: ");
    scanf("%d",&cylinders);
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(req[j]>req[j+1]){
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(req[i]>=initial){
            pos = i;
            break;
        }
    }

    for(int i=pos; i<n; i++){
        printf("%d\t", req[i]);
        thm+= abs(req[i]-initial);
        initial = req[i];
    }
    thm+= abs((cylinders-1)-req[n-1]);
    initial = cylinders-1;
    for(int i=pos-1; i>=0; i--){
        printf("%d\t", req[i]);
        thm+= abs(req[i]-initial);
        initial = req[i];
    }
    printf("\nTotal head movement: %d", thm);
    */

   /*CSCAN
    int cylinders, pos, temp;
    printf("Enter no. of cylinders: ");
    scanf("%d",&cylinders);
    for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(req[j]>req[j+1]){
                    temp = req[j];
                    req[j] = req[j+1];
                    req[j+1] = temp;
                }
            }
    }
    for(int i=0; i<n; i++){
        if(req[i]>=initial){
            pos = i;
            break;
        }
    }

    for(int i=pos; i<n; i++){
        printf("%d\t",req[i]);
        thm += abs(initial-req[i]);
        initial = req[i];
    }
    thm+= (abs((cylinders-1)-req[n-1])+cylinders-1);
    initial = 0;
    for(int i=0; i<pos; i++){
        printf("%d\t",req[i]);
        thm += abs(initial-req[i]);
        initial = req[i];
    }
    printf("\nTotal head movement: %d", thm);
    */
    return 0;
}