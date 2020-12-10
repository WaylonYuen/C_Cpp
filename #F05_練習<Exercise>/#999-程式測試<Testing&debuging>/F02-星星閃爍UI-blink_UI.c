//
//未完成-unfinished
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	int time_now = time (NULL); 
	int Countdown=100;  //倒計時，單位:秒
    int DelateTime; //時間延遲變數

	int Futuretime = time(NULL)+Countdown;

	while(Futuretime != time(NULL)){ //程式停止時間	
        			
		int Difftime = Futuretime - time(NULL);	
		//printf("Last  %d s\n",Difftime); //測試程式運行所剩時間
        printf("*\n");  //輸出*
		DelateTime = time(NULL)+1;	//延遲1秒 
		while(DelateTime != time(NULL)){//在1秒內所做的事
			//nothing		
		}
        system("clear");//清除屏幕
        //printf("clear\n"); //輸出測試
        DelateTime = time(NULL)+1;	//延遲1秒 
		while(DelateTime != time(NULL)){//在1秒內所做的事
			//nothing			
		}
	}
}