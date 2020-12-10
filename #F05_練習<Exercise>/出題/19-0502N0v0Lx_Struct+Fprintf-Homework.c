//  編號：19-0502N0v0Lx_Struct+Fprintf-Homework.c
//  Copyright: Oracragron.Waylon.Yuen
//

/*標頭文件*/
    #include <stdio.h>
    #include <string.h>

/*定義*/
    #define MemberSIZE 5    //資料筆數
    #define FILE_PATH "save.txt"    //文件路徑

    /*定義 結構 & 名稱為account*/
    typedef struct account{
        int account_number;  // 帳戶編號
        char firstname[50];  // 姓
        char lastname[50];   // 名
        double balance;      // 帳戶餘額
    }account;

/*副程式宣告*/
    void acount_sort(struct account *p);

int main(void){

    struct account Member[MemberSIZE], *p;    //宣告 結構型 Member陣列 & 指標p
    p = Member;   //將指標p指向Member陣列開頭位置

    int i;

    printf("請分別輸入 帳戶編號、 姓、 名、 帳戶餘額\n");
    for(i=0; i<MemberSIZE; i++){
        /*輸入結構資料*/
        scanf(
            "%d%s%s%lf", // lf: double

            &(p+i)->account_number, 
            (p+i)->firstname, 
            (p+i)->lastname, 
            &(p+i)->balance
        );
    }

    /*以帳戶排序-副程式*/
    acount_sort(p); //呼叫副程式 並傳遞 p指標參數於副程式

    puts("\n");

    /*輸出並保存至外部文件*/
    FILE *fptr; //文件指標宣告
    if( (fptr = fopen("save.txt", "w")) != NULL){  //判斷路徑是否存在文件
        //成功讀取文件
        puts("File open Success！");
        puts("**************************");
        
        /*逐筆資料保存至外部文件*/
        for(i=1; i<MemberSIZE+1; i++){
            fprintf(
                fptr,"%d\t%s\t%s\t%lf\n", 
                (p+i)->account_number,
                (p+i)->firstname, 
                (p+i)->lastname, 
                (p+i)->balance
            );
        }

        fflush(fptr);   //刷新緩衝區, 將緩衝區內容寫入文件
        rewind(fptr);   //重置文件內部指標位置，讓指標位置指向文件開頭

        fclose(fptr);   //關閉文件
        printf("......File Save Success!\n");
    }else{
        //文件打開失敗
        printf("File open Fail！ Plz check the file!\n");   //錯誤提示語
        puts("......End of run");
        return 0;
    }

    /*在cmd中顯示結果*/
    printf("\n輸出結構內容：\n帳戶編號\t姓\t名\t帳戶餘額\n");

    /*逐筆資料輸出至螢幕*/
    for(i=1; i<=MemberSIZE; i++){
        printf(
            "%d\t\t%s\t%s\t%lf\n",

            (p+i)->account_number,
            (p+i)->firstname,
            (p+i)->lastname,
            (p+i)->balance
        );
    }

    return 0;
}

/*帳戶排序-副程式*/
void acount_sort(struct account *p){

    int i, j;
    struct account temp;    //宣告結構型 的account名稱為 temp：用途為交換次序所必要第三個保存位置

    /*泡沫排序法*/
    for(i=0; i<MemberSIZE; i++){
        for(j=0; j<MemberSIZE-i; j++){
            if( (p+j)->account_number  >  (p+j+1)->account_number ){    //決定排序：由小到大 or 有大到小
                /*交換*/
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}