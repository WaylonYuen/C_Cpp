#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student {
    char name[20];
    int Number;
    char sex;
    int CS;
    int Calculus;
    float Average;
}stu[50 + 1];

void SetData(FILE* fp_r){

    int Ran;
    char Gender[2] = {'M', 'F'};
    int i = 0;
    char input[20];

    srand(time(NULL));

    //資料設定
    while(fscanf(fp_r," %s",input) != EOF){
        
        strcpy( stu[i].name, input);
        stu[i].Number = i+1;

        Ran = rand() % 2;
        stu[i].sex = Gender[Ran];

        Ran =  ( rand() % (100-70+1) ) + 70;
        stu[i].CS = Ran;

        Ran = ( rand() % (100-70+1) ) + 70;
        stu[i].Calculus = Ran;

        stu[i].Average = (float)(stu[i].CS + stu[i].Calculus) / 2;

        printf("%s    %d    %c    %d    %d\n",stu[i].name, stu[i].Number, stu[i].sex, stu[i].CS, stu[i].Calculus);
        i++;
    }
}

void Format1(FILE* fp_w){

    int i;
    //導出格式一
    fprintf(fp_w,"學生姓名\t號碼\t性別\n");
    fprintf(fp_w,"---------------------\n");
    for(i = 0; i< 50; i++){
        fprintf(fp_w,"%s\t\t%d\t\t%c\n",stu[i].name, stu[i].Number, stu[i].sex);
    }
}

void SortAch(){
    //成績排序
    int i, j, temp;

    /*冒泡排序法_Bubble Sort*/
    for(i=0; i<50-1; i++){  
        for(j=0; j<50-i-1; j++) { 
            if(stu[j].Average < stu[j+1].Average) {
                /*交換_SWAP*/
                stu[50] = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = stu[50];
            }

            //如果平均分一樣，則參考計概分數
            if(stu[j].Average == stu[j+1].Average){
                if(stu[j].CS < stu[j+1].CS){
                    /*交換_SWAP*/
                    stu[50] = stu[j];
                    stu[j] = stu[j+1];
                    stu[j+1] = stu[50];
                }
            }
        }
    }

    puts("\n================================ 班級成績表 ================================\n");
    printf("學生姓名\t計概成績\t微積分成績\t平均成績\t名次\n");
    printf("---------------------------------------------------------------------------\n");
    for(i = 0; i< 50; i++){
        printf("%s\t\t%d\t\t%d\t\t%.1f\t\t%d\t\n",stu[i].name, stu[i].CS, stu[i].Calculus, stu[i].Average, i+1);
    }
    puts("---------------------------------------------------------------------------");
}


void Menu(){
    printf("(1) 原始資料產生\n");
    printf("(2) 輸出學生資料\n");
    printf("(3) 列印排序成績\n");
    printf("(4) 結束程式執行\n");
}

int main(void){
    puts("");

    //int Functions = 0;
    //scanf("%d", &Functions);

    //讀取資料, 外部Python腳本調取
    FILE* fp_r = fopen("name.txt","r");
    FILE* fp_w = fopen("student.txt","w");

    if(fp_r == NULL || fp_w == NULL){
        printf("Cannot found the file\n");
        printf("%p  %p\n", fp_r, fp_w);

    } else{
        printf("file open\n");
        Menu();
        printf("%p  %p\n", fp_r, fp_w);
        
        //printf("Func %d\n", Functions);
        //if(Functions == 1){
            SetData(fp_r);
            //puts("Get");
        //}
        Format1(fp_w);
        SortAch();

        fclose(fp_r);
        fclose(fp_w);
        puts("");
    }
    return 0;
}