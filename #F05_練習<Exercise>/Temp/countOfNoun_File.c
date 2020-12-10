#include <stdio.h>
#include <string.h>

#define NumberOfNoun 5  //有多少個單詞需要比較？
#define SizeOfSpell 40  //每個單詞長度有多少？

int Counter[NumberOfNoun] = {0};    //統計結果存放
char Noun[NumberOfNoun][SizeOfSpell] = {"Orange", "Banana", "Mango", "Apple", "Straberry"};  //比較內容
char Name[SizeOfSpell]; //File讀取單字暫存

int main(void){

    int i = 0, j = 0;
    int isEqual = -1;

    FILE *fptr;
    if((fptr = fopen("fruit.txt","r")) == NULL){    //打開文件：位置 & 名稱，讀取模式
        printf("File open fail\nEnd of run...\n"); //找不到文件
        return 0;
    }else{
        /*打開File*/
        printf("File open success...\n");
        while(fscanf(fptr, "%s", &Name[i]) != EOF){
            for(j=0; j<NumberOfNoun; j++){
                isEqual = strcmp(Name, Noun[j]);    //比較內容是否相同
                if(isEqual == 0){
                    Counter[j]++;
                }
            }
        }
        fclose(fptr);

        /*輸出結果*/
        for(i=0; i<NumberOfNoun; i++){
            printf("%15s = %d\n", Noun[i], Counter[i]);
        }
    }
    return 0;
}
