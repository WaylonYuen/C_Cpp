//
//	Lebal #002-FM03
//
//  FM03-中位數-Median.c
//	Version 1.2 
//	
//  Created by Waylon.Yuen on 18/10/2018.
//	Last modified by Waylon.Yuen on 19/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入整數，判斷其是否為中位數。
//	操作：輸入一整數，範圍是int標準。
//	優化：1、輸入類型由int改為float。
//
#include<stdio.h>

int A[128];
int BublleSort(int size);

int main(int argc, char const *argv[]){
    
    int i=0;
    float median;
    int number;

    while(scanf("%d", &number) != EOF){
        A[i] = number;
        i++;
    }

    number = i;
    BublleSort(i);
    
    /*Output the Array*/
    for(i=0; i<number; i++){
        printf("%d ", A[i]);
    }

    puts("\n\n");
    printf("number of enter: %d \n\n", number);

    /*Median*/
    int mid = number/2;

    if(number%2 == 0){
        median = (A[mid-1]+A[mid]);
        median/=2;
    }
    else{
        median = A[mid];
    }
    printf("Medain : %.2f \n", median);

    return 0;
}

int BublleSort(int size){

    int i,j;
    int temp;

    /*冒泡排序法_Bubble Sort*/
    for(i=0; i<size-1; i++){  
        for(j=0; j<size-i-1; j++){ 
            if(A[j] > A[j+1])
            {
                /*交換_SWAP*/
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return 0;
}
