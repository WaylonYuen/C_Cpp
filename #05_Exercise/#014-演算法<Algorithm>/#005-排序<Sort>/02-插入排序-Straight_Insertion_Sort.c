#include<stdio.h>

int output();
int Container[10] = {9,8,7,6,5,4,3,2,1,0};

int main(){

    int i,j;
    int temp;

    /*插入排序法_Straight Insertion Sort*/
    for (i=1; i<10; i++) {
        j = i;
        while(j>0 && Container[j] < Container[j-1]){
            /*交換_SWAP*/
            temp = Container[j];
            Container[j] = Container[j-1];
            Container[j-1] = temp;

            j--;
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
