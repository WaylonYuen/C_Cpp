#include<stdio.h>

int Container[3];

int main(int argc, char const *argv[]){
    
    int i,j;
    int temp;

    /*輸入*/
    for(i=0; i<3; i++){
        scanf("%d",&Container[i]);
    }

    /*冒泡排序法_Bubble Sort*/
    for(i=0; i<3-1; i++){  
        for(j=0; j<3-i-1; j++){ 
            if(Container[j] < Container[j+1])
            {
                /*交換_SWAP*/
                temp = Container[j];
                Container[j] = Container[j+1];
                Container[j+1] = temp;
            }
        }
    }
    
    /*輸出顯示*/
    for(i=0; i<3; i++){
        printf("%d ",Container[i]);
    }
    puts("\n");
    
    return 0;
}