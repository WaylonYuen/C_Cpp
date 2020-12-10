// 編號：19-0522N0v1L1_Array-Exercise_For.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 * )
// 題目：二維陣列練習

// 時間：NULL ( 不限 )	//最佳 1s內
// 內存大小：128MB

// 題目：
// 將一個10*10的陣列內容初始化為0，用戶輸入數字則將該ROW的 0 改寫為 1 輸出。

// 步驟：
//
// 1、全域宣告一個 10*10的整數型二維陣列。 e.g: int Array[10][10];
// 2、初始化Array陣列的內容（初始化為 0 ）
// 3、寫一個副程式輸出Array的內容，並且每輸出10個就換一行，每個輸出前空一格。
//      副程式： void Display(void){ ... }
//      e.g: Array[10][10]:
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//
// 4、寫一個帶有一個整數參數的副程式。
//      副程式： int SetLine(int Line){ ... }
//      該副程式功能：
//          1、限制參數範圍只允許 0～9範圍內（包括 0 和 9）。
//          2、讀取參數內容，將對應數值的 ROW 內容改成 1 並且輸出
//
//          e.g: SetLine(6); //參數為6的情況
//             line     Array[10][10]
//              0       0 0 0 0 0 0 0 0 0 0
//              1       0 0 0 0 0 0 0 0 0 0
//              2       0 0 0 0 0 0 0 0 0 0
//              3       0 0 0 0 0 0 0 0 0 0
//              4       0 0 0 0 0 0 0 0 0 0
//              5       0 0 0 0 0 0 0 0 0 0
//              6       1 1 1 1 1 1 1 1 1 1 
//              7       0 0 0 0 0 0 0 0 0 0
//              8       0 0 0 0 0 0 0 0 0 0
//              9       0 0 0 0 0 0 0 0 0 0   
//
//      提示：
//          for(0~9){   // 控制 Column 列
//              for(0~9){   //控制 Row 行
//                  contain...
//              }
//          }

/*Lirary引用*/
#include <stdio.h>

/*變量定義*/
#define arraySIZE 10
//#define _Debug_

/*全域宣告*/
int Array[arraySIZE][arraySIZE] = {0};  //初始化陣列為 0

/*副程式宣告*/
void display(void);
int SetLine(int Line);

/*主程式入口*/
int main(void){

    int Line;

    printf("Plz input the line number for 0~9\n");
    scanf("%d", &Line);

    /*範圍偵測*/
    if(Line > 9 || Line < 0){
        puts("data range Error! \n\n ......End of run");
        return 0;
    }else{
        /*副程式呼叫*/
        #ifdef _Debug_
            int TestLine = SetLine(Line);
            display();
            printf("\nLine: %d\n", Line);
            printf("Test Line: %d\n", TestLine);
        #else
            SetLine(Line);
            display();
        #endif
    }

    return 0;
}

/*副程式-結果輸出*/
void display(void){

    int i,j;

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            printf("%d ", Array[i][j]);
        }
        puts("");   //換行
    }
}

int SetLine(int Line){

    int i;

    for(i=0; i<10; i++){
        Array[Line][i] = 1;
    }

    return Line;
}

