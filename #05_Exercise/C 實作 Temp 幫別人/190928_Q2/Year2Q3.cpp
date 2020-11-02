// 編號：19-0928N0v4_Bin-Subtraction_File.c

// 程式類別：C語言
// 概念題：遞迴練習 ( 難度 **** )

/* 題目：二進制減法 -> 從檔案 hw2.txt 讀入兩個二進制的數字
（8個 bits），讀入的第一個值為被減數，讀入的第二個值為減數，
試輸出其相減結果至 result.txt*/

// 時間：NULL ( 不限 ) //最佳 1s內
// 內存大小：8MB

// 輸入格式： Null
// 1011         -> File
// 1110000      -> File

// 輸出格式：
// e.g: 00001011 - 01110000 = 10011011 (11 - 112 = -101)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

//Declaration of Boolean type
//#define bool    _Bool   //定義布爾型態
//#define true    1       //常量定義
//#define false   0       //常量定義

#pragma region 宣告
//Declaration of Constant
#define SIZE 8 + 1              //Size of Bin[] ( +1 : Save -> End of string '\0')
#define _DEBUG_                 //Debug Mode (if define then open debug mode)
#define SrcPath_r "hw2.txt"     //定義 文件讀取路徑
#define SrcPath_w "result.txt"  //定義 文件保存路徑

//Data Struct
struct Data {
    char Bin[SIZE];     //文件讀取到的二進位資料保存陣列
    int LengthOfBin;    /*Bin陣列中的實際內容長度 ( 即：實際讀取到的二進位長度，並非陣列最大資料保存長度 SIZE )*/
    bool isPositive;    //正負數 (為解決輸出文件時,需以字串輸出,因此要保留符號位進行判斷)
    int Dec;            //保存十進位資料
} Data[3];

//Declaration of Functions
void LengthOfCharArrUse(int Num);               //計算&保存結構中Bin所使用到的空間長度
void AlignToRight(int Num);                     //向右對齊
void BinToDec(int Num);                         //2進位 -> 10進位
void DecToBin(int AnswerNum);                   //10進位 -> 2進位
void OneComplement(int Num);                    //一補數 ( 轉置 )
void TwoComplement(int Num);                    //二補數 ( 加一 )
void EmptyArr(char *Data, char Set);            //初始化字元陣列
void Answer(int Num, int minuend, int Sub);     //計算 減法結果
int Power(int Base, int Power);                 //計算 整數次方
void Format(char *Data);                        //輸出 題目所要求的格式
#pragma endregion

//Program Entry
int main(){

    //Declaration of Values
    char input[SIZE];   //File Read Buffer
    char output[100];   //File Write Buffer

    //Declaration of File pointer ( Read pointer & Write pointer )
    FILE* fp_r = fopen(SrcPath_r,"r");  //獲取文件讀取指標
    FILE* fp_w = fopen(SrcPath_w,"w");  //獲取文件保存指標
    
    //Check the File pointer and it's exist
    if(fp_r == NULL || fp_w == NULL) {
        printf("@ <Warning> Main() ::= FILE Pointer = Null -> Cannot found the file\n");    //Msg : 文件打開失敗
        printf("# <Debug Mode> Main() -> Output File Pointer { %p , %p }\n", fp_r, fp_w);
    } else {

        int NumberOfData = 0;   //讀取的資料筆數

        //Scanf hw2.txt & Save to Data
        while(fscanf(fp_r," %s", input) != EOF) {
            strcpy( Data[NumberOfData].Bin , input);    //複製讀取到的內容到指定結構中保存

            #ifdef _DEBUG_
            printf("#%d\t<Debug Mode> Main() -> get File Data[%d] = %s\n", NumberOfData, NumberOfData, Data[NumberOfData].Bin);
            #endif

            NumberOfData++; //資料筆數加一
        }

        #ifdef _DEBUG_ 
        puts("--------------------------------------------------------------------- Total"); 
        printf(">> <Read File> Main() \t\t\t\t\t-> Total number of Data : %d\n\n", NumberOfData);
        #endif

        //初始化( 資料 )
        for(int i = 0; i < NumberOfData; i++){
            
            #ifdef _DEBUG_
            printf("\n\n$ <Get Data> Main() \t\t\t\t\t-> Data[%d]\n", i);
            puts("--------------------------------------------------------------------- Struct"); 
            #endif

            LengthOfCharArrUse(i);  //計算資料所使用到的陣列長度
            AlignToRight(i);        //資料向右對齊
            BinToDec(i);            //將資料由字元二進位轉換成整數十進位
        }

        #ifdef _DEBUG_
        printf("\n\n$ <Get Data> Main() \t\t\t\t\t-> Data[%d]\n", NumberOfData);
        puts("--------------------------------------------------------------------- Struct"); 
        #endif

        Answer(NumberOfData, 0, 1); //計算(減法)：參數 -> (需保存到的結構參數, 被減數, 減數)
        Format(output);             //格式化(題目要求)

        fprintf(fp_w,"%s", output); //保存到文件中
        printf("\n\nSave to %s ... Done!\n", SrcPath_r);
    }

    //Close File pointer
    fclose(fp_r);
    fclose(fp_w);

    return 0;
}

#pragma region 格式 Function
//Format
void Format(char *data){

    int i;
    int Position = 0;
    char Buff[SIZE];

    EmptyArr(data, '0');    //初始化字元陣列

    #pragma region Bin

    //寫入 : 被減數 (二進位)
    for(i = 0; i< SIZE - 1; i++){
        data[Position] = Data[0].Bin[i];
        Position++;
    }

    data[Position] = ' ';   Position++;
    data[Position] = '-';   Position++;
    data[Position] = ' ';   Position++;

    //寫入 : 減數 (二進位)
    for(i = 0; i< SIZE - 1; i++){
        data[Position] = Data[1].Bin[i];
        Position++;
    }

    data[Position] = ' ';   Position++;
    data[Position] = '=';   Position++;
    data[Position] = ' ';   Position++;

    //寫入 : 結果 (二進位)
    for(i = 0; i< SIZE - 1; i++){
        data[Position] = Data[2].Bin[i];
        Position++;
    }
    #pragma endregion

    #pragma region Dec
    data[Position] = ' ';   Position++;
    data[Position] = '(';   Position++;
    data[Position] = ' ';   Position++;

    //寫入 : 被減數 (十進位)
    i = 0;
    sprintf(Buff, "%d", Data[0].Dec);
    while(Buff[i] != '\0'){
        data[Position] = Buff[i];
        i++;
        Position++;
    }

    data[Position] = ' ';   Position++;
    data[Position] = '-';   Position++;
    data[Position] = ' ';   Position++;

    //寫入 : 減數 (十進位)
    i = 0;
    sprintf(Buff, "%d", Data[1].Dec);
    while(Buff[i] != '\0'){
        data[Position] = Buff[i];
        i++;
        Position++;
    }

    data[Position] = ' ';   Position++;
    data[Position] = '=';   Position++;
    data[Position] = ' ';   Position++;

    //由於結果默認為正數,符號位另外保存.因此需要讀取符號位來確認正負數及 寫入 : 符號位
    if(Data[2].isPositive == false) {
        data[Position] = '-';   
        Position++;
    }

    //寫入 : 結果 (十進位)
    i = 0;
    sprintf(Buff, "%d", Data[2].Dec);
    while(Buff[i] != '\0'){
        data[Position] = Buff[i];
        i++;
        Position++;
    }

    data[Position] = ' ';   Position++;
    data[Position] = ')';   Position++;
    data[Position] = ' ';   Position++;
    data[Position] = '\0';
    #pragma endregion

    i = 0;
    while(data[i] != '\0') i++;

    #ifdef _DEBUG_
    printf("\n\n$ <Output> Format()\n");
    puts("--------------------------------------------------------------------- Format"); 
    printf(">> <Debug Mode> Format() \t\t\t\t-> Output      : %s   Length : %d\n", data, i);
    #endif
}

// Align to the right
void AlignToRight(int Num){

    char Buff[SIZE];    //Buffer
    int counter;

    counter = SIZE - 1;     // 陣列 由 0開始計算, 因此 -1
    EmptyArr(Buff, '0');    //Initial Buff[]

    //由陣列最後開始往前擺放資料
    for(int i = Data[Num].LengthOfBin; i >= 0; i--){
        Buff[counter] = Data[Num].Bin[i];
        counter--;        
    }

    Buff[SIZE-1] = '\0';            //(Label) End of String
    strcpy(Data[Num].Bin, Buff);    //Save
    
    #pragma region Checking (Positive or Negative)
    /*Check the Binary number( is Positive or Negative)
	->檢查最高位(最高位為符號位,確認正負數)*/
    if(Data[Num].Bin[0] == '1') Data[Num].isPositive = false;
    if(Data[Num].Bin[0] == '0') Data[Num].isPositive = true;

    if(Data[Num].isPositive == false) TwoComplement(Num); //非正數需要進行二補數轉換

    #ifdef _DEBUG_
    //Bin Checking( Posi or Nega )
    printf("# <Debug Mode> AlignToRight() \t\t\t-> isPositive  : %s\n", (Data[Num].isPositive == true) ? "True" : "False");
    #endif
    #pragma endregion

    #ifdef _DEBUG_
    //Debug Mode : Check Data of Align to the right
    printf("# <Debug Mode> AlignToRight() \t\t\t-> Data.Bin    : %s\n", Data[Num].Bin);
    #endif
}
#pragma endregion

#pragma region 方法 Function
//Binary exchange to Decimal
void BinToDec(int Num){

    int Dec = 0;
    Data[Num].Dec = 0;   //Empty

    //if(Data[Num].isPositive != true) TwoComplement(Num);

    for(int i = SIZE - 2; i >= 0; i--){
        if(Data[Num].Bin[i] == '0') continue;   // '0'可忽略不計, continue -> 略過此次循環
        else Dec += Power(2, (SIZE - 2) - i);   /*Power(基地, 次方) | 次方 : SIZE - 2 -> SIZE的定義 = 8+1,
                                         		陣列 : 0~7(8bits) | -i -> 反向由後往前(由右往左計算)*/
    }

    Data[Num].Dec = Dec;    //Save

    #ifdef _DEBUG_
    //Debug Mode : Check Data of Decimal
    printf("# <Debug Mode> BinToDec() \t\t\t\t-> Data.Dec    : %d\n", Data[Num].Dec);
    #endif
}

//Decimal exchange to Binary
void DecToBin(int AnswerNum){

    char Buff[SIZE];
    //EmptyArr(Buff, '0');

    int Dec = Data[AnswerNum].Dec;  //取出無符號整數(已經通過十進位減法計算獲取到答案)

    int i = SIZE - 2;   // SIZE定義 : 8 + 1, 8bits陣列 -> 0～7
    int Remainder;      //餘數

    while (Dec >= 1){

        Remainder = Dec % 2;
        Dec /= 2;

        sprintf(Buff, "%d", Remainder);   //Save to Bin[]
        Data[AnswerNum].Bin[i] = Buff[0];

        i--;    //Loop
    }

    Data[AnswerNum].Bin[SIZE - 1] = '\0';   //字串結尾符號
}

//One's Complement
void OneComplement(int Num){

    //反轉
    for(int i = 0; i < Data[Num].LengthOfBin; i++){
        if(Data[Num].Bin[i] == '0') Data[Num].Bin[i] = '1';
        else if(Data[Num].Bin[i] == '1') Data[Num].Bin[i] = '0';
    }

    #ifdef _DEBUG_
    printf("# <Debug Mode> OneComplement() \t\t\t-> Trun        : %s\n", Data[Num].Bin);
    #endif
}

//Two's Complement
void TwoComplement(int Num){

    OneComplement(Num);     //Turn Bin[]

    bool isCarry = false;   //進位判斷

    //加一
    for(int i = Data[Num].LengthOfBin - 1; i >= 0; i--){
        if(Data[Num].Bin[i] == '0') {
            Data[Num].Bin[i] = '1';
            break;
        } else {
            isCarry = true;
            Data[Num].Bin[i] = '0'; 
        }
    }

    #ifdef _DEBUG_
    printf("# <Debug Mode> TwoComplement() \t\t\t-> Plus One    : %s\n", Data[Num].Bin);
    #endif
}
#pragma endregion

#pragma region 功能 Function
// Initial Char[]
void EmptyArr(char *Data, char Set) {
    for(int i = 0; i < sizeof(Data); i++)
        Data[i] = Set;
}

//Save Length of Char Arr Use
void LengthOfCharArrUse(int Num){

    //Calculus ( Length of Arr use )
    for (int i = 0; i < SIZE; i++) {

        //Check the End of String by one data -> '\0'
        if(Data[Num].Bin[i] == '\0'){
            Data[Num].LengthOfBin = i--;    //save data ( Actual length of File Read )

            #ifdef _DEBUG_
            //Debug Mode : Check Data of Actual Length
            printf("# <Debug Mode> LengthOfCharArrUse() \t-> Data.Bin    : %s\t\tLength Of Data.Bin    : %d bits\n",
			        Data[Num].Bin, Data[Num].LengthOfBin); 
            #endif

            break;
        }
    }
    
}

//Calculate Power of Values
int Power(int Base, int Power){

    int Ans = 1;

    if(Power < 0) return -1;    //Error
    if(Power == 0) return 1;

    for(int i = 0; i < Power; i++) 
        Ans *= Base;

    return Ans;
}
#pragma endregion

//Get Answer
void Answer(int Num, int minuend, int Sub){

    int AnswerNum = Num;  //Answer Struct Data[2]

    //Initial
    EmptyArr(Data[AnswerNum].Bin, '0');     //清空

    //Calculate
    Data[AnswerNum].Dec = Data[minuend].Dec - Data[Sub].Dec;

    //Check : is negative ans
    if(Data[AnswerNum].Dec < 0) {
        Data[AnswerNum].isPositive = false;     //Set : Sign
        Data[AnswerNum].Dec *= -1;              //Change to positive Number
        DecToBin(AnswerNum);                    //Dec exchange to Bin
        LengthOfCharArrUse(AnswerNum);          //Calculus
        TwoComplement(AnswerNum);               //Two's Complement
    } else {
        Data[AnswerNum].isPositive = true;      //Set : Sign
        DecToBin(AnswerNum);                    //Dec exchange to Bin
        LengthOfCharArrUse(AnswerNum);          //Calculus
    }

    #ifdef _DEBUG_
    printf("# <Debug Mode> Answer() \t\t\t\t-> Answer Bin  : %s\n", Data[Num].Bin);
    printf("# <Debug Mode> Answer() \t\t\t\t-> Answer Dec  : %d\n", Data[Num].Dec);
    #endif
}



