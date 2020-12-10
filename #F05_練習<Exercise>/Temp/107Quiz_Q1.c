#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    int input;
    int counter=0;

    for(i=0; i<5; i++){
        scanf("%d", &input);
        counter = counter + input;
    }

    printf("average: %d\n\n", counter = counter/5);

    return 0;
}
