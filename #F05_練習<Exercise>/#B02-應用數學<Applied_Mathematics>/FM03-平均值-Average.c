//
//操作：輸入n個整數， Linus：control+D Window：Control+Z 停止輸入，計算結果。
//
#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int i=0;
    int input;
    int counter=0;

    while(scanf("%d", &input) != EOF){
        counter += input;
        i++;
    }

    printf("average: %d\n\n", counter = counter/i);

    return 0;
}
