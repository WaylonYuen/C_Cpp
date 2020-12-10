#include<stdio.h>
#define pi 3.14159

int main(int argc, char const *argv[]){
    int radius;
    int area;

    scanf("%d", &radius);

    area = radius * radius * pi;
    //primeter = (radius + radius) * pi;

    printf("The circle area is %d\n", area);

    return 0;
}
