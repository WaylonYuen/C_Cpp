// 編號：L1_20-1106N2v0_Func_計算機.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ★☆☆☆☆ ) -> (tmp: ★ ☆)
// 題目：計算機

// 時間：NULL ( 不限 ) //最佳 3s內
// 內存大小：128MB

// 題目內容：
// 輸入兩筆整數及運算符編號, 再利用副程式計算整數加減乘除(每個副程式負責一個運算)並回傳結果.

// 輸入：
// 兩筆整數 及 運算符編號

// 輸出：
// 運算結果

// Sample input :
// 13
// 2
// 3

// Sample output： 
// 26

#include <stdio.h>

//副程式宣告
void Menu(void);
int Calculator(void);
int Add(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);

//主程式
int main(void) {

    int result = Calculator();
    printf("計算結果: %d\n", result);

    return 0;
}

//計算機副程式
int Calculator(void) {

    int a, b, request;
    int ans = 0;

    printf("請輸入第一個數值:\n");
    scanf("%d", &a);

    printf("請輸入第二個數值:\n");
    scanf("%d", &b);

    Menu();
    scanf("%d", &request);

    switch (request) {

        case 1: ans = Add(a, b); break;
        case 2: ans = Sub(a, b); break;
        case 3: ans = Mul(a, b); break;
        case 4: ans = Div(a, b); break;
        
        default:
            printf("沒有 %d 功能選項.\n", request);
            break;
    }

    return ans;
}

//菜單副程式
void Menu(void) { 
    printf("Menu 請輸入功能編號:\n");
    printf("================\n");
    printf(" - 1 - 加法\n");
    printf(" - 2 - 減法\n");
    printf(" - 3 - 乘法\n");
    printf(" - 4 - 除法\n");
    printf("================End\n");
}

//加法副程式
int Add(int a, int b) {
    return a + b;
}
//減法副程式
int Sub(int a, int b) {
    return a - b;
}
//乘法副程式
int Mul(int a, int b) {
    return a * b;
}
//除法副程式
int Div(int a, int b) {
    return a / b;
}