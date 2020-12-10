#include<stdio.h>
#include<stdlib.h>

/*定義宣告*/
//#define SWAP(x,y,t) = ((t)=(x),(x)=(y),(y)=(t))
//#define SIZE 7

/*副程式宣告*/
char* create_Arr(int, int);
void delete_Arr(char*);
void SWAP(char* Arr, int Num);
void ExChangeEvenOddNumber(char* Arr, int SIZEMAX);
void InputData(char* Arr, int SIZE);
void OutputData(char* Arr, int SIZE);

/*全域變量宣告*/
//NULL

/*陣列內容交換*/
void SWAP(char* Arr, int Num){
    char temp;
    temp = Arr[Num];
    Arr[Num] = Arr[Num+1];
    Arr[Num+1] = temp;

    puts("SWAP ------------");  //FormSet
}

/*奇偶位交換*/
void ExChangeEvenOddNumber(char* Arr, int SIZEMAX){
    int i;
    char temp;

    printf("\n\nTesting: \n");  //Testing-T1
    for(i=0; i<SIZEMAX; i+=2){
        SWAP(Arr, i);
        printf("Arr[%d] = %c\n", i, Arr[i]);    //Testing-T2
        printf("Arr[%d] = %c\n", i+1, Arr[i+1]);//Testing-T3
    }
}

/*資料輸入*/
void InputData(char* Arr, int SIZE){
    int i;
    for(i=0; i<SIZE; i++){
        scanf("%c", &Arr[i]);
    }
}

/*資料輸出*/
void OutputData(char* Arr, int SIZE){
    int i;
    for(i=0; i<SIZE; i++){
        printf("%c", Arr[i]);
    }
}

/*回傳建立的陣列地址*/
char* create_Arr(int size, int init){

    char *arr = malloc(size *sizeof(char));

    for(int i=0; i<size; i++){
        arr[i] = init;
    }

    return arr;
}

/*釋放arr空間*/
void delete_Arr(char* arr){
    free(arr);
}

/*主程式*/
int main(void){

    /*變量宣告*/
    int SIZE;
    int SIZEMAX;

    printf("Plz input the SIZE of Arr: ");
    scanf("%d", &SIZE);

    if(SIZE%2 != 0){
        /*奇數*/
        SIZEMAX = SIZE-1;
    }

    
    /*建立大小為SIZE的陣列空間*/
    char *arr = create_Arr(SIZE, 0);

    /*輸入陣列的內容*/
    InputData(arr, SIZE);

    /* Ori-Arr_Data */
    printf("\nOriginal:\t");
    OutputData(arr, SIZE); //陣列輸出

    /*Exchanged*/
    ExChangeEvenOddNumber(arr, SIZEMAX);
    printf("Exchanged:\t");
    OutputData(arr, SIZE);
    printf("\n\n"); //FormSet

    /*釋放空間*/
    delete_Arr(arr);

    return 0;
}