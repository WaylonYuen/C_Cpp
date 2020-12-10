///input: char[] = {"4*3+32"}
///output: int 44
///improve: 添加運算優先級
#include <stdio.h>

//由於C語言沒有 Bool 所以要自行定義
#define bool int
#define true 1
#define false 0

int calculate(int a, int b, int symbolIndex);

enum Operator { Add, Sub, Mul, Div };   

int Check(char* List){

    char OperatorList[4] = {'+', '-', '*', '/'};
    char NumList[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int IntNumberIndex = 0;
    int IntNumberCounter = 0;
    int IntNumber[10][10];

    //保存答案
    int OperatorCounter = 0;
    int Number[10];
    int Operator[20];

    int IsNumber;
    int IsSymbol;

    int i = 0;
    int j = 0;
    int k = 0;

    while(List[i] != '\0') {    //如果沒有讀取到List字串最後,就持續執行,否則跳出while

        IsNumber = false;

        for(j = 0; j < 10; j++) {
            //True : 為數值; 
            if(List[i] == NumList[j]) {
                IntNumber[IntNumberIndex][IntNumberCounter] = j; 
                IsNumber = true;
                break;
            }
        }

        if(IsNumber) {
            IntNumberCounter++;         
        } else {
            IntNumber[IntNumberIndex][IntNumberCounter++] = -1;
            IntNumberIndex++;
            IntNumberCounter = 0;

            //符號判斷
            IsSymbol = false;
            for(j = 0; j < 4; j++){
                if(List[i] == OperatorList[j]) {
                    Operator[OperatorCounter] = j;  //保存符號索引
                    //printf("Symbol[%d] = %d\n", OperatorCounter, Operator[OperatorCounter]); //Testing
                    OperatorCounter++;
                    IsSymbol = true;
                    break;
                }
            }

            if(!IsSymbol){
                printf("Symbol Error!"); //Error
            }
        }

        i++;

        if(List[i] == '\0') {
           IntNumber[IntNumberIndex][IntNumberCounter] = -1; 
        }
    }

    //數值轉換

    int digits = 1; //位數控制
    int TempNumber = 0; //暫存該次所讀取到的數值答案
    int Length = 0;

    for(j = 0; j <= IntNumberIndex; j++) {
        digits = 1;
        TempNumber = 0;

        //長度計算
        Length = 0;
        for(k = 0; k < 10; k++) {
           if(IntNumber[j][k] == -1){
               Length = k;
               Length--;
               break;
           }
        }
        
        //數值轉換
        for(k = Length; k >=0; k--) {
            TempNumber += (IntNumber[j][k] * digits);  //每個位的數值加總
            digits *= 10;   //每個位都要乘10
        }
        Number[j] = TempNumber;
    }


    //呼叫運算器
    int result;

    //printf("Number %d, %d, %d \n", Number[0], Number[1], Operator[0]);
    result = calculate(Number[0], Number[1], Operator[0]); //算出第一個答案
    //printf("Result %d \n", result);


    if(IntNumberIndex >= 2 && OperatorCounter > 1){
        for(j = 2, k = 1; j <= IntNumberIndex; j++, k++) {
            result = calculate(result, Number[j], Operator[k]);
        }
    }

    return result;
}

//計算
int calculate(int a, int b, int symbolIndex){

    int result = 0;

    switch (symbolIndex) {

    case Add:   
        result = a + b;   
        break;

    case Sub:   
        result = a - b; 
        break;

    case Mul:
        result = a * b;
        break;

    case Div:
        result = a / b;
        break;
    
    default:
        printf("Symbol Error!\n");
        break;
    }

    return result;
}

int main(){

    //input
    char Testing[] = { "1+4*3+32" };

    int number = Check(Testing);
    printf("Ans: %d\n", number);
    return 0;
}