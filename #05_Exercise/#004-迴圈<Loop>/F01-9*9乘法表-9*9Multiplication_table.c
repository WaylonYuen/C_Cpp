#include<stdio.h>

int main(){

    int i,j;
    int ans;

    for(i=1; i<=9; i++){
        for(j=1; j<=i; j++){ // 下三角(Triange Up):(j=1; j<=i; j++) / 上三角(Triange Down):(j=i; j<=9; j++)
            ans = i * j;
            printf("%d * %d = %d\t", j, i, ans);
        }
        puts("\n");
    }

    return 0;
}