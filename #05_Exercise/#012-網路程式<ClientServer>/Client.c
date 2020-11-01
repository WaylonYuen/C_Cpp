//
//  Lebal X
//
//  Quiz1_Client.c
//  Version 2.0
//	
//  Created by Waylon.Yuen on 24/9/2018.
//  Last modified by Waylon.Yuen on 24/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：
//  操作：X
//  原理：X
//  優化：X
//


#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int i;

int main(void) {
    here:;
    struct sockaddr_in server;
    int sock,readSize;

    /*輸入ip 和 port*/
    char ipNum[15];
    int portNum;
    printf("\n\nGate of ip & prot\n"
           "----------------------------\n");
    printf("Plz enter the ip number:\n");
    scanf("%s",ipNum);
    printf("Plz enter the port number:\n");
    scanf("%d", &portNum);

    /*指定連接判斷*/
    char ServerIP[]="127.0.0.1";
    char reset;
    if(strcmp(ipNum,ServerIP) != 0 || portNum != 5678){
            printf("\n\nConnect fail!...\n"
                "ip or prot is incorrect!\n"
                "\nPress enter Key to input again...\n"
                "press '0' key to Shut Down!\n");
            scanf("%c", &reset);
            if((reset = getchar()) == '0'){
                return 0;
            }else{
                system("clear");
                goto here;
            }
    }

    /*通訊設定——建立通訊協定*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(ipNum);
    server.sin_port = htons(portNum);

    int counter = 0; 
    int buf[256];
    
    printf("\n\nPlz intput the data:\n"
           "----------------------------\n");
    int holding;
    while(scanf("%d", &holding) != EOF){        
        buf[counter] = holding;
        counter++;
    }   

    /*發送資料總數*/
    int size[1];
    size[0] = counter;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    send(sock, size, sizeof(size), 0);
    printf("\n\nSend Size: %d \n\n",size[0]);

    /*發送資料*/
    printf("\n\nSend Data\n"
           "----------------------------\n");
    for(i=0; i<size[0]; i++){
        sock = socket(PF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&server, sizeof(server));

        send(sock, &buf[i], sizeof(buf[i]), 0);
        printf("Send Message: %d \n", buf[i]);
    }puts("\n\n");


    /*發送選擇功能*/
    int Func[1];
    int funcFlag=0;
    printf("Plz select Functions:\n");
    scanf("%d", &funcFlag);

    sock = socket(PF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    send(sock, Func, sizeof(Func), 0);
    printf("Send Func: %d \n\n",Func[0]);

    
    /*收到server排序後的結果 輸出*/
    printf("\n\nGet Data:\n"
           "----------------------------\n");
    int getDate[256];
    printf("Sort BtS:");
    for(i=0; i<size[0]; i++){
        readSize = recv(sock, &getDate[i], sizeof(getDate[i]), 0);
        printf(" %d ", getDate[i]);
    }puts("\n\n");
    
    printf("Sort StB:");
    for(i=0; i<size[0]; i++){
        readSize = recv(sock, &getDate[i], sizeof(getDate[i]), 0);
        printf(" %d ", getDate[i]);
    }puts("\n\n");

    /*接收totalNum*/
    readSize = recv(sock, &getDate[0], sizeof(getDate[0]), 0);
    printf("Get Average of data: %d\n\n", getDate[0]);

}
