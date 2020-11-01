#include <stdio.h>
int i;  //宣告 ( 全域 )

int main(){

    //宣告陣列(內容)
    int container[10] = {1,2,3,4,5,6,7,8,9,10};

    //宣告陣列(答案)
    int Ans[10] = {};   //偶數奇數組
    int even[5] = {};   //偶數
    int odd[5] = {};    //基數

    //變數宣告
    int j = 0;
    int h = 0;
    int i;

    for(i=0; i<10; i++){
        if(container[i] % 2 == 0){
            even[j] = container[i]; //保存偶數
            j++;
        } else {
            odd[h] = container[i];  //保存奇數
            h++;
        }
    }

    for(j=0; j<5; j++) printf("%d ", even[j]); 
    for(h=0; h<5; h++) printf("%d ", odd[h]);
    
    return 0; 
}