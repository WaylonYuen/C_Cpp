#include<stdio.h>

int main(int argc, char const *argv[])
{
    int number;

    scanf("%d", &number);

    if(number%10 == 0){
        printf("The number is multiples of 10\n");
    }
    if(number%5 == 0){
        printf("The number is multiples of 5\n");
    }
    if(number%2==0){
        printf("The number is multiples of 2\n");
    }

    return 0;
}