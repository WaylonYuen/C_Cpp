#include<stdio.h>

int main(){

    int i;
    int num;
    int ans=0;

    scanf("%d", &num);

    for(i=0; i<=num; i++){
        ans+=i;
    }
    
    printf("ans: %d\n", ans);

    return 0;
}