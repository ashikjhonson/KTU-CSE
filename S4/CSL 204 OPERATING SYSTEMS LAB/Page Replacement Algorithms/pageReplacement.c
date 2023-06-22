/**
 * Program for implementing page replacement algorithms (FIFO, LRU, LFU) in C
 * Ashik Jhonson
 * 22/06/2023
*/

#include <stdio.h>
int frameSize, n_pages, n_frames;
int frameLength = 0;

int found(int framesArray[], int page){
    for(int i=0; i<frameLength; i++){
        printf("%d  ", framesArray[i]);
    }
    for(int i=0; i<frameLength; i++){
        if(framesArray[i]==page){
            return 1;
        }
    }
    return 0;
}

void fifo(int pagesArray[]){
    printf("\nFIFO\n");
    int miss=0, hit=0, firstIndex = 0;    
    int framesArray[frameSize];
    for(int i=0; i<n_pages; i++){
        printf("\n[%d] Frames: ", pagesArray[i]);
        if(found(framesArray, pagesArray[i])){
            hit++;
            printf("Hit");
        }
        else{
            miss++;
            printf("Miss");
            framesArray[firstIndex] = pagesArray[i];
            frameLength += frameLength<frameSize?1:0;
            firstIndex = (firstIndex+1)%frameSize;
        }
    }
    printf("\nMiss=%d\tHit=%d", miss, hit);
}

void lru(int pagesArray[]){
    /*Complete LRU*/
}

int main(){
    // printf("Enter frame size: ");
    // scanf("%d",&frameSize);
    // printf("Enter no. of pages: ");
    // scanf("%d",&n_pages);
    // int pagesArray[n_pages];
    // printf("Enter Pages:\n");
    // for(int i=0; i<n_pages; i++){
    //     scanf("%d", &pagesArray[i]);
    // }
    int pagesArray[]={1,2,3,4,5,1,3,1,6,3,2,3};
    frameSize = 4, n_pages=12;
    printf("Frame Size: %d\nPages reference: ", frameSize);
    for(int i=0; i<n_pages; i++){
        printf("%d  ", pagesArray[i]);
    }
    // fifo(pagesArray);
    lru(pagesArray);
    return 0;
}