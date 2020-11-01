#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int lenght,width;
    int area;

    scanf("%d%d", &lenght, &width);

    area = lenght * width;

    printf("The ractangle area is %d\n", area);

    return 0;
}
