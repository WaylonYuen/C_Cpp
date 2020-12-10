#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int RandomNum;

    int *Link;
    srand(time(NULL));

    Link = (int *)malloc(sizeof(400));

    int i, j;
    for(i = 0; i< 100; i++){
        RandomNum = rand() % 1000 + 1;
        *(Link + i) = RandomNum;     
    }

    
    int temp;
    /*冒泡排序法_Bubble Sort*/
    // for(i=0; i<100-1; i++){  
    //     for(j=0; j<100-i-1; j++) { 
    //         if(*(Link + j) > *(Link + j+1)) {
    //             /*交換_SWAP*/
    //             temp = *(Link + j);
    //             *(Link + j) = *(Link + j+1);
    //             *(Link + j+1) = temp;
    //         }
    //     }
    // }

    /*插入排序法_Straight Insertion Sort*/
    for (i=1; i<100; i++) {
        j = i;
        while(j>0 && *(Link + j) < *(Link + j-1)){
            /*交換_SWAP*/
            temp = *(Link + j);
                *(Link + j) = *(Link + j-1);
                *(Link + j-1) = temp;

            j--;
        }
    }

    puts("Testing::");
    for(i = 0; i< 100; i++){
        printf("%d\t%p\t\t%d\n", i, (Link + i), *(Link + i));   
    }

    free(Link);

    return 0;
}