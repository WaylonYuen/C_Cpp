#include<stdio.h>

int main(){

    int A, B;
    int ans;

    scanf("%d%d", &A, &B);

    /*加法_Addtion*/
    ans = A + B;
    printf("A + B = %d\n", ans);

    /*減法_Subtract*/
    ans = A - B;
    printf("A - B = %d\n", ans);

    /*乘法_Multiply*/
    ans = A * B;
    printf("A * B = %d\n", ans);

    /*除法_Divide*/
    ans = A / B;
    printf("A / B = %d\n", ans);

    return 0;
}