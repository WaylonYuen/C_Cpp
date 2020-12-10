/*lirary-index*/
#include<sys/socket.h>
#include<netinet/in.h>
#include<pthread.h> //thread 這行必定要加請同學要注意
#include<arpa/inet.h>
#include<ctype.h>
#include<string.h>
#include <stdio.h>
#include <unistd.h>

/*define-index*/
#define chatMemberSIZE 4

/*Functions-index*/
void *connection_handler(void*);
void show(int List[], int top);
int push(int List[], int top, int addID);
int pop(int List[], int top, int LeaveID);

int top=-1;
int memberID[chatMemberSIZE]={0};
int intMsg[64];
char charMsg[64];
int a[100]={0};
int working =0;

int main(void){

	struct sockaddr_in server,client;
	int sock,csock,readSize,addressSize,c;
	pthread_t sniffer_thread;
	
	bzero(&server,sizeof(server));
	server.sin_family = PF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(6789);
	sock = socket(PF_INET,SOCK_STREAM,0);
	bind(sock,(struct sockaddr *)&server,sizeof(server));

	listen(sock,5); //可連線socket最多五個
	addressSize = sizeof(client);
	//當有新的連線建立時
	while(csock =accept(sock,(struct sockaddr *)&server,(socklen_t*)&addressSize)){

		working ++; //紀錄連線數+1

		if(working <= chatMemberSIZE){

			/*傳送連接資訊*/
			strcat(charMsg,"\n\nYou join in server successfully!");
			send(csock, &charMsg, sizeof(charMsg), 0);
			memset(charMsg,'\0',sizeof(charMsg)-1);//清空charMsg字元陣列

			/*本地顯示連接資訊*/
			printf("Online connect: %d \n",working);

			/*建立Tread*/
			if(pthread_create(&sniffer_thread,0,connection_handler,(void *)&csock) < 0){
				return 1; //建立Thread 同時判斷是否建立成功，若成功回傳1，失敗回傳-1
			}	
			pthread_detach(sniffer_thread);//執行結束後釋放執行緒
			if(csock < 0) return 1;

		}else{

			working--;//銷掉一開始到working++;
			/*傳送連接資訊*/
			strcat(charMsg,"\n\nServer is full!");
			send(csock, &charMsg, sizeof(charMsg), 0);
			memset(charMsg,'\0',sizeof(charMsg)-1);//清空charMsg字元陣列
		}
	}
	return 0;
}

//執行緒執行的功能
void *connection_handler(void* sock){	
	int csock = *(int *) sock;
	int readSize;		
	char buf[256],temp[256];
	int number;
	int i ;
	number = working-1;	

	/*添加List成員*/
	top = push(memberID, top, csock);

	printf("top: %d",top);//test
	send(csock, &top, sizeof(top), 0);
	/*傳送List資訊*/
	for(i=0; i<=top; i++){
		send(csock, &memberID[i], sizeof(memberID[i]), 0);
		printf("memeberID[%d]: %d",i,memberID[i]);//test
	}
	memset(charMsg,'\0',sizeof(charMsg)-1);//清空charMsg字元陣列


	//迴圈讀取訊息時	
	while(readSize = read(csock,buf,sizeof(buf))){

		/*本地顯示資訊*/
		if(a[number]==0) a[number] =csock;//將Socket ID加入陣列中		
		printf("\nCsocked ID: %d \n",csock);	
		buf[readSize]='\0';
		printf("Read Message: %s \n",buf);
		show(memberID, top);//展示List所有成員列隊順序

	/*當有關閉連線請求訊息*/			
		if(strcmp(buf,"quit")==0){
			top = pop(memberID, top, csock);
			int del;
			working--;
			//將Socket ID 在陣列中的位置調整
			for(i=0;i<100;i++){
				if(a[i]=csock)
					del=i;			
			}
			//將順序往前，關閉Socket ID移到最後初始為0
			for(i=del;i<100;i++){
				a[i] =a[i+1];
				a[99] = 0;			
			}
			break;
		}

	/*傳送訊息*/
		for(i=0;i<100;i++){//傳送訊息於每一個用戶
			if(a[i]!=0)//當有Socket連線存在時
				write(a[i],buf,sizeof(buf));//傳送訊息
				//Fuction: write(int fd, const void*buf,size_t nbytes);
		}		
	}

	/*Client關閉*/
	if(readSize == 0){
		puts("\n\nClient Disconnected!");

		top = pop(memberID, top, csock);//成員離開&重新整理List列隊

		printf("CSock ID: %d \n",csock); //顯示關閉的Socket ID
		int delete;

		//將Socket ID在陣列中位置調整
		for(i=0;i<100;i++){
			if(a[i]==csock)
			delete =i;//該Socket ID在陣列中的順序
		}
		printf("SD; %d\n",delete);
			
		fflush(stdout);//清空暫存區
		working--;

		//將Socket ID作為調整		
		for(i=delete;i<100;i++){
			a[i] =a[i+1];
			a[99] = 0;					
		}	

	}
	pthread_exit(0);//關閉thread
}

void show(int List[], int top){
	int i;
	printf("\nList ID: ");
	for(i=0; i<=top; i++){
		printf("%d ", List[i]);
	}
	printf(	"\n--------------------------\n");
}
int push(int List[], int top, int addID){
	top++;
	if(top > chatMemberSIZE){
		top--;
		show(List, top);
		printf("List is full\n");
	}else{
		List[top] = addID;
		show(List, top);
	}
	return top;
}
int pop(int List[], int top, int LeaveID){
	int i;
	int Leave;
	if(top < 0){
		printf("List is empty\n");
	}else{
		for(i=0; i<top; i++){
			if(List[i] == LeaveID){
				Leave = i;
				break;
			}
		}
		for(i=Leave; i<top; i++){
			List[i] = List[i+1];
		}
		List[top] = 0;
		top--;
		show(List, top);
	}
	return top;
}