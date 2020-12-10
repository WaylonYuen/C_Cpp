// 編號：19-0924N0v3_Bin-Combination.c

// 程式類別：C語言
// 概念題：遞迴練習 ( 難度 *** )
// 題目：二進位遞迴排列組合

// 時間：NULL ( 不限 )	//最佳 1s內
// 內存大小：8MB

// 輸入格式：
// printf("Input a number: "); //需輸入組合長度(即 n 位)

// 輸出格式：
// e.g: 0000\n  0001\n  0010\n  0011\n  0100\n ......

#include <stdio.h> 

void Comb(int index, int n, char *buf)  { 

	/*判斷是否遞迴結束*/
	if(index >= n)  { 			// True: 表示需輸出
		buf[index]='\0'; 		//在buf字串的結尾補上結束符號
		printf("%s\n", buf); 	//輸出字串結果
	} else { 

		//組合 ‘0’ 的遞迴
		buf[index]='0'; 
		Comb(index+1, n, buf);

		//組合 ‘1’ 的遞迴
		buf[index]='1'; 
		Comb(index+1, n, buf); 

		//buf[index]='此處可繼續添加組合項目';	// *注：請注意長度上限
		//Comb(index+1, n, buf);

	} 
} 

int main(int argc, char **argv)  { 

	/*宣告*/
	int n; 			//n位組合
	char buf[100];	//每個組合的最大長度上限 

	/*輸入組合長度*/
	printf("Input a number: "); 
	scanf("%d", &n); 

	/*執行*/
	Comb(0, n, buf); 	// 起始值為 0，即：buf[0]

	return 0; 
} 