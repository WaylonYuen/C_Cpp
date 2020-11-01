#include<stdio.h>

int output();
int Container[10] = {9,8,7,6,5,4,3,2,1,0};

int main(){

    int i,j;
    int temp;

    /*選擇排序法_Simple Selection Sort*/
    int min;

    for (i=0; i<10-1; i++) {
        min = i;
        for (j=i+1; j<10; j++) {
            if(Container[j]<Container[min]){
                min = j;
            }
        }
        if(min != i){
            /*交換_SWAP*/
                temp = Container[min];
                Container[min] = Container[i];
                Container[i] = temp;

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