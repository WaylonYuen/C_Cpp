// 編號：Intro_20-1119N1v0_Judgment_三元運算.c

// 程式類別：C語言

#include<stdio.h>

int main(void){

    int A, B;
    int max;

    scanf("%d%d", &A, &B);

    //三元運算定義: (A>B) ? true : false
    //當 A>B 成立時 max = true;
    //當 A>B 不成立時 max = false;
    //等同於:
    // if(A > B) {
    //     max = A;
    // } else {
    //     max = B;
    // }
    max = (A > B) ? A : B;
    printf("max1: %d\n", max);

    //巢狀三元運算
    //等同於: 
    // if(A > B) {
    //     if(A == B) {
    //         max = 1;
    //     } else {
    //         max = 0;
    //     }
    // } else {
    //     max = B;
    // }
    max = (A > B) ? ((A == B) ? 1 : 0) : B;
    printf("max2: %d\n", max);

    return 0;
}