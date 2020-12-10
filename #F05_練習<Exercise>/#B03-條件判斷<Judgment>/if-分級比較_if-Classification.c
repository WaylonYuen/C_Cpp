//
//  A grade: 90~100
//  B grade: 80~89
//  C grade: 70~79
//  D grade: 60~69
//  E grade: 0~59
//
#include<stdio.h>

int main(){

    int score;

    scanf("%d", &score);

    if(score>=90 && score<=100){
        printf("A grade\n");
    }
    else if(score>=80 && score<=89){
        printf("B grade\n");
    }
    else if(score>=70 && score<=79){
        printf("C grade\n");
    }
    else if(score>=60 && score<=69){
        printf("D grade\n");
    }
    else if(score>=0 && score<=59){
        printf("E grade\n");
    }
    else{
        puts("Data Erorr!\n");
    }

    return 0;
}