#include<stdio.h>
#define pi 3.14159

int main(int argc, char const *argv[]){
    int radius;
    int area, primeter;

    scanf("%d", &radius);

    area = radius * radius * pi;
    primeter = (radius + radius)*pi;

    printf("area: %d\nprimeter: %d\n\n", area, primeter);

    return 0;
}