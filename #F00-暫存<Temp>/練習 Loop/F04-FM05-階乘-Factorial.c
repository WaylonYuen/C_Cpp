#include<stdio.h>

int main(){

    int i;
    int num; 
    int sum = 1;

    scanf("%d", &num);

    for(i=1; i<=num; i++){
        sum = sum * i;  //階乘運算 1*2*3* ⋯⋯ *n
    } 

    printf("%d! = %d\n", num, sum);

    return 0;
}