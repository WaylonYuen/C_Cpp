//
//  Lab02_HW_Server.c
//  1: get two string A and string B, Then string C becomes “A & B” send back to Client
//  2: it waits for the second string (string B) for at most 3 seconds. Otherwise, only send string A to Client
//
//  Created by Waylon.Yuen on 8/10/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>

int main(void){

    /*變數宣告*/
    struct sockaddr_in server, client;
    int sock, readSize, addressSize;
    char strA[128], strB[128], strC[256];//字串宣告
    int flag;//判斷 strB的行為：0為EOF、1為未收到StrB資料、2為收到StrB資料

    /*網絡層：建立IP通訊閘*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5678);

    /*抽象層：建立通訊協定*/
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    bind(sock, (struct sockaddr*)&server, sizeof(server));
    addressSize = sizeof(client);

    while(1){
        /*接收strA資料並傳回資料長度*/
        readSize = recvfrom(sock, &strA, sizeof(strA), 0, (struct sockaddr*)&client, &addressSize);
        printf("read message strA: %s\n", strA);//輸出&檢查strA的內容

        /*接收strB資料並傳回資料長度*/
        readSize = recvfrom(sock, &strB, sizeof(strB), 0, (struct sockaddr*)&client, &addressSize);
        printf("read message strB: %s\n", strB);//輸出&檢查strB的內容

        /*接收strB的行為flag*/
        readSize = recvfrom(sock, &flag, sizeof(flag), 0, (struct sockaddr*)&client, &addressSize);
        printf("read message flag: %d\n\n", flag);//輸出&檢查flag的內容

    /*判斷strB的行為*/
        /*接收到strB的資料*/
        if(flag == 2){
            strcpy(strC,strA);//將strA 複製到 strC中
            strcat(strC,"&"); //將 & 複製到strC的字串尾
            strcat(strC,strB);//將字串2 複製到strC的字串尾 
            printf("strC: %s\n",strC);//輸出&檢查strC的內容
            sendto(sock, &strC, sizeof(strC), 0, (struct sockaddr*)&client, sizeof(client)); //傳送運算的結果
        }
        /*未收到strB的資料*/
        else if(flag == 1){
            strcpy(strC,strA);//將strA 複製到 strC中
            printf("strC: %s\n",strC);//輸出&檢查strC的內容
            sendto(sock, &strC, sizeof(strC), 0, (struct sockaddr*)&client, sizeof(client)); //傳送運算的結果
        }
        /*收到Client端strA 或 strB 為 EOF*/
        else if(flag == 0){
            exit(1);//結束程式
        }
        
    }
}