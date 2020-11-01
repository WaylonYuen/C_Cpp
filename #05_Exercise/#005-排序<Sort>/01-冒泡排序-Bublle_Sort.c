#include<stdio.h>

int output();
int Container[10] = {9,8,7,6,5,4,3,2,1,0};

int main(){

    int i,j;
    int temp;

    /*冒泡排序法_Bubble Sort*/
    for(i=0; i<10-1; i++){  
        for(j=0; j<10-i-1; j++){ 
            if(Container[j] > Container[j+1])
            {
                /*交換_SWAP*/
                temp = Container[j];
                Container[j] = Container[j+1];
                Container[j+1] = temp;
            }
        }
    }
    output();//排序結果

    return 0;
}

/*輸出顯示*/
int output(){
    int i;
    for(i=0; i<10; i++){
        printf("%d ",Container[i]);
    }
    puts("\n");
    
    return 0;
}