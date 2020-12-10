#include<stdio.h>

int main(){
    int i=1;
    int base, number, times;
    int ans;

    scanf("%d %d %d", &base, &number, &times);

    if(base <= times){
        ans = number * times;
    }
    else{
        while(base%times != 0){
            base++;
        }//直到是倍數關係

        number--;
        ans = base + (number*times); 
    }

    printf("%d", ans);

    return 0;
}