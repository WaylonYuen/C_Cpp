//
//  Lebal X
//
//  Quiz1_Servr.c
//  Version 2.0
//	
//  Created by Waylon.Yuen on 24/9/2018.
//  Last modified by Waylon.Yuen on 24/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：
//  操作：X
//  原理：X
//  優化：功能項除法給予float值(目前：int)
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

void swap(int *A, int *B);
void BubbleSort(int Data[], int size, int compare);
void BubbleSortBtS(int Data[], int size);
void BubbleSortStB(int Data[], int size);
int SumOfNumber(int Data[], int size);
int SubOfNumber(int Data[], int size);
int MultOfNumber(int Data[], int size);
int DivOfNumber(int Data[], int size);
int Max(int Data[], int size);
int Min(int Data[], int size);
int Median(int Data[], int size);
int Average(int Data[], int size);
int Func(int Data[], int size, int funcFlag);

int main(void) {
    
    struct sockaddr_in server, client;
    int sock, csock, readSize, addressSize;
    char buf[256];
    
    /*通訊設定——建立通訊協定*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5678);
    
    sock = socket(PF_INET, SOCK_STREAM, 0);
    bind(sock, (struct sockaddr*)&server, sizeof(server));
    listen(sock,5);
    
    int i,j;
    int getData[256];

    /*接收-功能選項*/
    int funcFlag;
    addressSize = sizeof(client);
    csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
    readSize = recv(csock, &funcFlag, sizeof(funcFlag), 0);
    printf("\n\nRead data funcFlag: %d \n\n", funcFlag);

    /*接收-資料總數*/
    int size;
    addressSize = sizeof(client);
    csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
    readSize = recv(csock, &size, sizeof(size), 0);
    printf("\n\nRead data Size: %d \n\n", size);

    /*接收-資料內容*/
    printf("Get Data\n"
           "----------------------------\n");
    for(i=0; i<size; i++){
        addressSize = sizeof(client);
        csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
        readSize = recv(csock, &getData[i], sizeof(getData[i]), 0);
        printf("Read Message: %d \n", getData[i]);
    }puts("End\n\n");

//Functions:server功能----------------------------------------------

    // 0: Big to small; 1:small to Big

    BubbleSort(getData, size, 0);
    BubbleSortBtS(getData, size);
    /*Sort Array 回傳 大到小*/
    printf("Send Data\n"
           "----------------------------\n");
    for(i=0; i<size; i++){
        send(csock, &getData[i], sizeof(getData[i]), 0);
        printf("sendBack Msg %d \n", getData[i]);
    }puts("End\n\n");


    BubbleSort(getData, size, 1);
    BubbleSortStB(getData, size);
    /*Sort Array 回傳 小到大*/
    printf("Send Data\n"
           "----------------------------\n");
    for(i=0; i<size; i++){
        send(csock, &getData[i], sizeof(getData[i]), 0);
        printf("sendBack Msg %d \n", getData[i]);
    }puts("End\n\n");

    //平均
    int AverageNum = Average(getData, size);
    printf("Send Average of number\n"
           "----------------------------\n");
    send(csock, &AverageNum, sizeof(AverageNum), 0);
    printf("sendBack AverageNum: %d\n", AverageNum);
    puts("End\n\n");

    //功能項目
    int Ans = Func(getData, size, funcFlag);
    printf("Send Func of number\n"
           "----------------------------\n");
    send(csock, &Ans, sizeof(Ans), 0);
    printf("sendBack AverageNum: %d\n", Ans);
    puts("End\n\n");

//End of Functions--------------------------------------------------

    close(csock);
    close(sock);
}

/* function：交換 */
void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

/*冒泡排序法*/
void BubbleSortBtS(int Data[], int size){
    /*冒泡排序法_Bubble Sort*/
    int i,j;
    for(i=0; i<size-1; i++){  
        for(j=0; j<size-i-1; j++){ 
            if(Data[j] < Data[j+1]){// "<" 和 ">" 決定排序是：由大到小"<" or 由小到到大">"
                /*交換_SWAP*/
                swap(&Data[j], &Data[j+1]);
            }
        }
    }
}

/*冒泡排序法*/
void BubbleSortStB(int Data[], int size){
    /*冒泡排序法_Bubble Sort*/
    int i,j;
    for(i=0; i<size-1; i++){  
        for(j=0; j<size-i-1; j++){ 
            if(Data[j] > Data[j+1]){// "<" 和 ">" 決定排序是：由大到小"<" or 由小到到大">"
                /*交換_SWAP*/
                swap(&Data[j], &Data[j+1]);
            }
        }
    }
}

void BubbleSort(int Data[], int size, int Compare){

    int i,j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(Compare == 1){
                if(Data[j] > Data[j+1]){
                    swap(&Data[j],&Data[j+1]);
                }
            }else{
                if(Data[j] < Data[j+1]){
                    swap(&Data[j],&Data[j+1]);
                }
            }
        }

    }
}


/*累加 Data[]資料*/
int SumOfNumber(int Data[], int size){

    int i;
    int ans = 0;
    for(i=0; i<size; i++){
        ans = ans + Data[i];
    }

    return ans;
}

int SubOfNumber(int Data[], int size){
    int i;
    int ans;
    ans = Data[0];
    for(i=1; i<size; i++){
        ans = ans - Data[i];
    }

    return ans;
}
int MultOfNumber(int Data[], int size){
    int i;
    int ans = 1;
    for(i=0; i<size; i++){
        ans = ans * Data[i];
    }

    return ans;
}
int DivOfNumber(int Data[], int size){
    int i;
    int ans;
    BubbleSortBtS(Data, size);

    ans = Data[0];
    for(i=1; i<size; i++){
        ans = ans / Data[i];
        printf("Div ans: %d", ans);
    }

    return ans;
}

/*最大值*/
int Max(int Data[], int size){

    int i;
    int ans = 0;

    for(i=0; i<size; i++){
        if(Data[i] > ans){
            ans = Data[i];
        }
    }
    return ans;
}

/*最小值*/
int Min(int Data[], int size){

    int i;
    int ans;

    ans = Data[0];
    for(i=0; i<size; i++){
        if(Data[i] < ans){
            ans = Data[i];
        }
    }
    return ans;
}

/*中位數*/
int Median(int Data[], int size){

    int mid;
    float median;
    BubbleSortBtS(Data, size);

    mid = size/2;

    if(size%2 == 0){
        median = (Data[mid-1] + Data[mid]);
        median/=2;
    }
    else{
        median = Data[mid];
    }

    return median;
}

/* 平均值 */
int Average(int Data[], int size){
    
    int ans = SumOfNumber(Data, size);

    ans = ans/size;

    return ans;
}

int Func(int Data[], int size, int funcFlag){
    /*功能區*/
    int funcAns;    //float
    switch(funcFlag){
        case 1: 
            funcAns = SumOfNumber(Data, size);
            break;
        case 2: 
            funcAns = SubOfNumber(Data, size);
            break;
        case 3: 
            funcAns = MultOfNumber(Data, size);
            break;
        case 4: 
            funcAns = DivOfNumber(Data, size);
            break;
        default:
            printf("Error\n");
            return 0;
            break;
    }
    return funcAns;
}
