#include<stdio.h>

int main(void){

    int A, B;
    int max;

    scanf("%d%d", &A, &B);

    max = A > B ? A : B;  //三目運算比較： A>B ？Ture：Fale

    printf("max: %d\n", max);

    return 0;
}