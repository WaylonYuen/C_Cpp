#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>

int intMsg;

int main(void){
	struct sockaddr_in server;
	int sock, readSize;
	char buf[256],temp[256],shake[]="Hello";
	char ip[] ="127.0.0.1";//設定ip
	int port = 6789;//設定port	
	pid_t pid; //將pid_t 宣告成pid
	
	
	bzero(&server,sizeof(server));
	server.sin_family = PF_INET;
	server.sin_addr.s_addr = inet_addr(ip);
	server.sin_port = htons(port);
	sock = socket(PF_INET,SOCK_STREAM,0);
	connect(sock,(struct sockaddr *)&server,sizeof(server));
	
	write(sock,shake,sizeof(shake)); //Fuction: write(int fd, const void*buf,size_t nbytes);

	pid = fork(); //建立出一個child process

	/*接收connection information*/
		char getMsg[64];
		readSize = recv(sock, getMsg, sizeof(getMsg), 0);
		printf("%s\n\n", getMsg);


	int i;
	int top;

	readSize = recv(sock, &top, sizeof(top), 0);
	printf("top: %d\n", top);	//test
	printf("Member List: ");
	for(i=0; i<=top; i++){
		readSize = recv(sock, &intMsg, sizeof(intMsg), 0);
		printf("%d ", intMsg);
	}
	printf("\n\n");


	//迴圈執行
	while(1){

		if(pid == -1){
			//表示有錯誤發生，並且離開迴圈
			perror("Fork Failed!");
			exit(EXIT_FAILURE);	
		}else if(pid ==0){

			//進入child process執行
			readSize = read(sock,temp,sizeof(temp)); //接收Server訊息
			//Fuction: read(int fd,void *buf,size_t nbyte)
			printf("Rsock ID: %d \n", sock); //顯示Child Sock ID
			temp[readSize]='\0';
			printf("Read Message: %s \n",temp);//顯示接收訊息
				
		}else{
			if(scanf("%27[^\n]%*c",buf) !=EOF && strcmp(buf,"quit")!=0){
				//判斷輸入是否EOF和檢查是否有輸入quit字串
				write(sock,buf,sizeof(buf));
				printf("Wsocked ID: %d\n", sock);//顯示Parent Sock ID			
			}else{
				//離開程式
				_exit(EXIT_SUCCESS);
				break;			
			}
		}
	}
}
