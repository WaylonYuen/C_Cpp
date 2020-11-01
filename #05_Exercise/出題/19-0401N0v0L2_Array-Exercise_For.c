// 編號：19-0401N0v0L2_Array-Exercise_For.c

// 程式類別：C語言
// 基礎題：陣列 ( 難度 ** )
// 題目：陣列重組

// 時間：NULL ( 不限 )	//最佳 1s內
// 內存大小：128MB

// 創建一個SIZE為10的Arr字元陣列，
// 並初始化Arr陣列內容：A～J；
// 隨機輸入0～9範圍內10個編號，
// 輸出根據編號所輸入的英文順序。
// ( 請參考 Input 和 Output 格式 )

// 輸出格式：
// printf(“Arr[%d] = %d\n”, ??);  //問號為自定變數

// *注意：
// 1、不可以使用printf直接表達，必須將內容存入到Arr中，
// 再將整個Arr輸出。
// 2、請不要重複輸入0～9的編號
// 3、編號1～9 表示 A～I
// 4、編號 0 表示 J

// *提示：
// 將輸入的編號存入Key陣列中，再用for循環挨個讀取
// 並輸出 //注意：需使用到雙重for循環。

// Input： 
// 	5438791206	//隨機輸入10筆0～9的資料
// Output： 
// 	Arr[0] = E		//Arr0號中根據Key內容為5，所以是E
// 	Arr[1] = D
// 	Arr[2] = C
// 	Arr[3] = H
// 	Arr[4] = G
// 	Arr[5] = I
// 	Arr[6] = A
// 	Arr[7] = B
// 	Arr[8] = J
// 	Arr[9] = F

#include<stdio.h>
#define SIZE 10

int main(void){

    /*變量宣告*/
    int i,j;    //循環用參數
    int Keyi;   //保存Key編號
    int Key[SIZE];  //保存編號
    char Arr[SIZE] = {'A','B','C','D','E','F','G','H','I','J'}; //初始化內容
    char Arr2[SIZE]; //暫存 Key編號中所對應的Arr內容
    

    /*輸入Key編號*/
    for(i=0; i<SIZE; i++){
        scanf("%d", &Key[i]);
    }

    /*將Key編號對應的Arr內容取出並存入Arr2中*/
    for(i=0; i<SIZE; i++){
        Keyi = Key[i];  //取出Key陣列中所保存的編號 並存入Keyi中
        Arr2[i] = Arr[Keyi];    //將Arr所對應的Keyi編號內容存入 Arr2中
    }

    /*將Arr2中的內容覆蓋\轉存 回Arr中*/
    for(i=0; i<SIZE; i++){
        Arr[i] = Arr2[i];
    }

    /*輸出Arr*/
    for(i=0; i<SIZE; i++){
        printf("Arr[%d] = %c\n", i, Arr[i]);
    }

    return 0;
}
		
