#include <stdio.h>

#define SIZE 50
#define Empty 97

//副程式宣告
void EmptyASCII();
void Initial();
void ToNum();
void Initial();
void Output();
void ToA();

//全域宣告
char Key[SIZE];
int KeyNum[SIZE];
char Data[SIZE] = {};       //保存輸入的明文
int DataNum[SIZE] = {};     //保存明文轉換為數字的結果
int Encryption[SIZE] = {};
char Encry[SIZE] = {};

int Length;

int main(){

    printf("Please input the plaintext:");
    scanf("%s", Data);  //輸入資料
    
    printf("Please input the key:");
    scanf("%s", Key);

    EmptyASCII();
    ToNum();
    Initial();
    ToA();
    Output();

    return 0;
}

//ASCII歸零
void EmptyASCII(){
    int i = 0;
    while(Data[i] != '\0'){
        printf(" %c 的ASCII為 %3d -> %3d\n", Data[i], Data[i], Data[i] - Empty);
        i++;
    }
}

void ToNum(){

    int i = 0;
    while(Data[i] != '\0'){
        DataNum[i] = Data[i] - Empty;
        i++;
    }

    i = 0;
    while(Key[i] != '\0'){
        KeyNum[i] = Key[i] - Empty;
        i++;
    }
}

void ToA(){
    char Array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int i, j;
    for(i = 0; i < Length; i++){
        Encry[i] = Array[Encryption[i]];
    }

}

void Initial(){
    int i = 0;
    Length = 0;
    while(Data[i] != '\0'){
        Encryption[i] = (KeyNum[i%3] + DataNum[i]) % 26;
        Length++;
        i++;
    }
}

void Output(){
    int i;
    for(i = 0; i < Length; i++)
        printf("%c ", Encry[i]);

}