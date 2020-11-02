#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Buff[50];
char BuffList[50][500];
char Te[1];

void List();
int main(void){
    
    FILE* fp_r = fopen("input.txt", "r");

    if(fp_r == NULL) {
        printf("檔案開啟 失敗！\n");
        return -1;
    } else {
        printf("檔案開啟 成功！\n");
        while(fscanf(fp_r, "%s", Buff) != EOF) { 
            printf(" %s", Buff);
            //List(); 
        }
        fclose(fp_r);
        printf("\ncheck %c\n", Buff[0]);

        Te[0] = 'A';
        printf("testing %c", Te[0]);

        printf("\nEnd of run!...\n");
    }


    return 0;
}

void List(){

    int counter = 0;
    int Vcounter = 0;

    while(Buff[counter] != ' '){
        BuffList[counter][Vcounter] = Buff[counter];
        printf(" %c", BuffList[counter][Vcounter]);
    }

    Vcounter++;
    counter++;
}

void str_read(char str[], int n){

    int i;

    /*超出上限n則停止輸入，截斷內容*/
    for(i=0; i<n; i++){

        /*字元輸入*/
        scanf("%c", &str[i]);//等待 stdin 內的資料
        /* %c 為字元定義，此時輸入字串，由於外部有while循環，所以一樣會讀取stdin字串內容。
            不會因為 是字元輸入而無法讀取字串。
            #stdin：
                定義： 標準輸入儲存格
                原理： scanf 會等待用戶輸入內容，當用戶按下 enter，
                      用戶所輸入的內容則會儲存到 stdin 內，
                      此時 scnaf 就可以去 stdin 內讀取內容。
            */
        if(str[i] == '\n'){
            break;
        }
    }
    /* 結尾處把‘\n’替換成’\0‘，將字元陣列 替換成 字串陣列*/
    str[i] = '\0';
}