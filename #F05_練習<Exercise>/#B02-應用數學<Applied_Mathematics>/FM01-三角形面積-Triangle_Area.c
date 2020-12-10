#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int base,height;
    float area;

    scanf("%d%d", &base, &height);

    area = (base * height)/2;

    printf("The ractangle area is %.2f\n", area);

    return 0;
}
