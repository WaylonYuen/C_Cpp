// 編號 : L3_20-1117N1v0_Func-Recursion_二進位排列組合.c

// 程式類別 : C語言
// 基礎題 : 陣列練習 ( 難度 ★★★☆☆ )
// 題目 : 二進位排列組合(遞迴方式)

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小 : 128MB

// 題目內容 :
// 利用遞迴方式輸出二進位所有的排列組合，需手動輸入位寬(元素數目), 位寬最大不超過 100項

// 輸入 : 
// 手動輸入想要排列組合的位寬

// 輸出 :
// 所有的排列組合

// Sample input :
// 3

// Sample output : 
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111


// Sample input :
// 4

// Sample output : 
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// ...
// ...
// 1111

#include <stdio.h> 

//預定義
#define SIZE 100	//預先定義一個全域變數 int SIZE = 100

//副程式宣告
void Comb(int index, int n, char *buf);

//主程式
int main(int argc, char **argv) { 

	/*宣告*/
	int n; 			//n位組合
	char buf[SIZE];	//每個組合的最大長度上限 

	/*輸入組合長度*/
	printf("Input a number: "); 
	scanf("%d", &n); 

	//安全性檢查(針對輸入數值的範圍進行檢查: 0 <= n <= 100)
	if(n <= 0 || SIZE < n) {
		printf("Error: Out of range -> %d, (0 <= n <= 100)\n", n);
		printf("End of run...\n");
		return 0;	//停止程式
	}

	//呼叫副程式
	Comb(0, n, buf); 	// 起始值為 0，即：buf[0] // buf會回傳陣列第一個元素的地址,等同於 &buf[0]

	return 0; 
} 

//副程式: 二進位排列組合(遞迴)
//參數 index-> 起始值,
//參數 n-> 位寬
//參數 *buf-> 字串陣列指標
void Comb(int index, int n, char *buf) { 

	//if判斷該回合是否繼續遞迴
	if(index >= n)  { 			//條件成立: 輸出該組合結果
		buf[index]='\0'; 		//字串必須以 '\0' 結尾, 因此要在buf字串的結尾補上結束符號
		printf("%s\n", buf); 	//輸出字串結果(*注意: 輸出後該副程式調用完畢,返回到前一次呼叫此副程式的地方)

	} else { 

		//組合 ‘0’ 的遞迴
		buf[index]='0';	//保存當前數值
		Comb(index+1, n, buf);	//index索引加1後再呼叫自己, 遞迴呼叫後會執行到#78行針對index進行判斷

		//組合 ‘1’ 的遞迴
		buf[index]='1'; //保存當前數值
		Comb(index+1, n, buf); 	//index索引加1後再呼叫自己, 遞迴呼叫後會執行到#78行針對index進行判斷

		//buf[index]='此處可繼續添加組合項目';	// *注：請注意長度上限
		//Comb(index+1, n, buf);
	} 

	return;
} 