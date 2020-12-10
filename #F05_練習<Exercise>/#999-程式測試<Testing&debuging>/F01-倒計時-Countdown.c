//
//未完成-unfinished
//      BUG：時間會有誤差
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	int time_now = time (NULL); 
	int Countdown=100;  //倒計時剩餘秒數，單位:秒
    int DelateTime; //時間延遲變數
    int Futuretime;//判斷將來n秒後停止的布爾變數
    int Difftime;//時差變數
	
    Futuretime = time(NULL)+Countdown;//設定未來的時間參數，在未來某個時間。

	while(Futuretime != time(NULL)){ //程式停止時間，判斷現在的時間是否符合未來的時間
        /*不符合*/			
		Difftime = Futuretime - time(NULL);	//Difftime為：將來的時間與目前時間相差多少
		printf("Last  %d s\n",Difftime); //output剩餘時間
		DelateTime = time(NULL)+1;	//建立延遲1秒 的時差
		while(DelateTime != time(NULL)){//判斷是否1秒
            /*在這1秒時差內所執行的事*/
			//nothing		
		}
	}
}