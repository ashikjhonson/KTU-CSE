/**
 * Program for implementing page replacement algorithms (FIFO, LRU, LFU) in C
 * Ashik Jhonson
 * 22/06/2023
*/

#include <stdio.h>
#include <limits.h>
int frameSize, n_pages, n_frames, frameLength;

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
    frameLength = 0;
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
    int hit=0, miss=0, lruIndex=0;
    int framesArray[frameSize], recent[frameSize];
    frameLength = 0;
    for(int i=0; i<n_pages; i++){
        if(found(framesArray, pagesArray[i])){
            hit++;
            printf("Hit");
        }
        else{
            miss++;
            printf("Miss");
            if(frameLength<frameSize){
                framesArray[frameLength++] = pagesArray[i];                
            }
            else{

            }
        }
    }
    printf("\nMiss=%d\tHit=%d", miss, hit);
}

void lfu(int pagesArray[]){
    int miss=0, hit=0, lfuIndex = 0, lfuValue = INT_MAX;
    frameLength = 0;

    int framesArray[frameSize], frequency[n_pages];
    for(int i=0; i<n_pages; i++){
        frequency[i] = 0;
    }

    for(int i=0; i<n_pages; i++){
        printf("\n[%d] Frames: ", pagesArray[i]);
        if(found(framesArray, pagesArray[i])){
            hit++;
            printf("Hit");
        }
        else{
            miss++;
            printf("Miss");
            if(frameLength<frameSize){
                framesArray[lfuIndex] = pagesArray[i];
                lfuIndex++;
                frequency[i]++;
                frameLength++;
            }
            else{
                for(int j=i-1; j>=0; j--){
                    if(frequency[j]<=lfuValue){
                        lfuValue = frequency[j];
                        lfuIndex = j;
                    }
                }
                printf("LFUINDEX: %d", lfuIndex);
                framesArray[lfuIndex] = pagesArray[i];                
                frequency[lfuIndex]++;
            }
            for(int j=0; j<n_pages; j++){
                printf("%d  ", frequency[j]);
            }
        }
    }
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
    lfu(pagesArray);
    return 0;
}