//
//	Lebal #999-F01
//
//  F01-隨機資料順序-Random_Data_Sort.c
//	Version 1.2 
//	
//  Created by Waylon.Yuen on 17/10/2018.
//	Last modified by Waylon.Yuen on 19/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//	操作：input data 可改為手動輸入； 資料數目在Define改。默認內容為數字
//	優化：n個資料內容，以EOF結束
//
#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t)) 
#define size 9

int main(){
	
	int temp;
	int range;
    int data;
	int Array[size];
	int i, j=0;
	
	srand(time(NULL));

	/*Input Data*/
	for(i=0; i<size; i++){
		Array[i] = i;
        //scanf("%d", &data);
	}

    /*random sort*/
	for(i=size-1; i>=0; i--){
        /* '0' is not  exist. e.g: 8/0 = (not exist) .*/
		if(i!=0){
			range = rand()%i;
		}
        /*Interchange conditon*/	
		if(i!=range){									
			SWAP(Array[i],Array[range],temp);//Define SWAP
		}	
	} 

    printf("Random's Array. \n");

    /*Output Data*/ 	 	
	for(i=0;i<size;i++){
		printf("%3d",Array[i]);
	}					

    puts("\n\nEnd of run...");		
	
	return 0;
}
