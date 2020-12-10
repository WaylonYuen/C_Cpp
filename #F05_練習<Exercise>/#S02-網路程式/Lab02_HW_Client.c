//
//  Lab02_HW_Client.c
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
    fd_set rfds;//宣告一個描述文件 字fd的集合叫 rfds
    struct sockaddr_in server, client;
    struct timeval tv;//建立時間變數
    int sock, readSize, addressSize, retval;
    char strA[128], strB[128], strC[256]; //字串宣告
    int flag;//判斷 strB的行為：0為EOF、1為未收到StrB資料、2為收到StrB資料

    /*網絡層：建立IP通訊閘*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5678);

    /*抽象層：建立通訊協定*/
    sock = socket(PF_INET, SOCK_DGRAM, 0);

    while(1){
        FD_ZERO(&rfds);   //將rfds集合中所有位元設為0
        FD_SET(0, &rfds); //加入0進入rfds集合

        /*Wait up to five seconds*/
        tv.tv_sec = 3;  //題目要求：3秒等待 String B
        tv.tv_usec = 0; //微秒速
        
    /*輸入strA 並將資料送給server*/
        /*判斷strA內容是否為EOF*/
        if(scanf("%s", strA) != EOF){
            sendto(sock, &strA, sizeof(strA), 0, (struct sockaddr*)&server, sizeof(server));
        }
        else{
            /*傳送StrA 和 StrB 空資料，以回應Server端的strA 和 strB 的接收器*/
            sendto(sock, &strA, sizeof(strA), 0, (struct sockaddr*)&server, sizeof(server));
            sendto(sock, &strB, sizeof(strB), 0, (struct sockaddr*)&server, sizeof(server));
            
            /*傳送flag信號，0為EOF*/
            flag = 0;
            sendto(sock, &flag, sizeof(flag), 0, (struct sockaddr*)&server, sizeof(server));    
            exit(1);//結束程式
        }

        /*判斷響應時間*/
        retval = select(1, &rfds, NULL, NULL, &tv);//retval會衝右邊這些參數取值
        /*Don't rely on the value of tv now!*/

        /*響應時間*/
        if(retval == -1){//負數：錯誤
            perror("sellect()"); //錯誤
        }

        /*偵測strB是否有輸入內容——只等待3秒*/
        else if(retval){

        /*輸入strB 並將資料送給server*/
            /*判斷strB內容是否為EOF*/
            if(scanf("%s", strB) != EOF){
                /*偵測到strB輸入了內容*/
                sendto(sock, &strB, sizeof(strB), 0, (struct sockaddr*)&server, sizeof(server));
                flag = 2;//flag信號，2為strB輸入了內容
            }
            else{
                /*傳送 StrB 空資料，以回應Server端的strB 的接收器*/
                sendto(sock, &strB, sizeof(strB), 0, (struct sockaddr*)&server, sizeof(server));
                
                /*傳送flag信號，0為EOF*/
                flag = 0;
                sendto(sock, &flag, sizeof(flag), 0, (struct sockaddr*)&server, sizeof(server));
                exit(1);//結束程式
            }
        }

        /*等待strB 但未響應*/
        else{
            /*傳送 StrB 空資料，以回應Server端的strB 的接收器*/
            sendto(sock, &strB, sizeof(strB), 0, (struct sockaddr*)&server, sizeof(server));
            flag = 1;//flag信號，1為strB輸入資料超時（3秒）
        }


        /*傳送flag 以響應Server端 flag接收器*/
        sendto(sock, &flag, sizeof(flag), 0, (struct sockaddr*)&server, sizeof(server));

        /*接收Server端傳回的處理後字串（strC=“strA”&“strB”）*/
        addressSize = sizeof(server);
        readSize = recvfrom(sock, &strC, sizeof(strC), 0, (struct sockaddr*)&server, &addressSize);

        /*輸出&檢查strC的內容*/ 
        printf("read message: %s\n", strC);

    }

}