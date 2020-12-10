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
    score = score/10;

    switch(score){
        case 10:;
        case 9:
            printf("A grade\n");
            break;
        case 8:
            printf("B grade\n");
            break;
        case 7:
            printf("C grade\n");
            break;
        case 6:
            printf("D grade\n");
            break;
        default:
            printf("E grade\n");
            break;
    }

    return 0;
}