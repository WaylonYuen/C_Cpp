#include <stdio.h>
#include <stdlib.h>

/*定義宣告*/
#define SIZE 100

/*全域變量宣告*/
int Data[SIZE]={0};//預設Data SIZE 100
int DataArrSIZE;

/* A、B交換 */
void swap(int *A, int *B){
    int temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

void insert(){
    int newData;

    printf("Plz input new data: ");
    scanf("%d", &newData);

    Data[DataArrSIZE] = newData;
    Data[DataArrSIZE+1] = -1;
    DataArrSIZE++;
}

void delete(){
    int i;
    int deleteData;

    printf("Plz input delete data: ");
    scanf("%d", &deleteData);

    /*循序查找要刪除的Data*/
    for(i=0; i<=DataArrSIZE; i++){
        if(Data[i] == deleteData){
            Data[i] = Data[DataArrSIZE-1];
            Data[DataArrSIZE-1] = -1;
            break;
        }
    }
}

void printTree(){
    int i,j,k;
    int BT[] = {0,1,2,4,8,16,32,64,128,256,512,1024};
    int counter = 0;
    int breakFlag = 0;

    printf("Heap tree: \n");

    /*打印出 二元樹 格式*/
    for(i=1; i<12; i++){
        for(k=i*3; k<10; k++){
            printf(" ");
        }
        for(j=1; j<=BT[i]; j++){
            if(Data[counter] == -1){
                breakFlag = 1;
                break;
            }
            printf("  %d", Data[counter]);
            counter++;
        }
        if(breakFlag == 1){
            break;
        }
        puts("\n");
    }
    printf("\n\n");
}

void buildHeapTree(){
    
    int i;
    int c, heapRoot;

    for (i=1; i<DataArrSIZE; i++){
        c = i;
        do{
            heapRoot = (c-1)/2;
            /* to create MAX Data  Arr */
            if(Data[heapRoot] < Data[c]){
                swap(&Data[heapRoot], &Data[c]);
            }
            c = heapRoot;
        } while(c != 0);
    }
}

int main(){

    /*變數宣告*/
    int i,j,k;//循環參數

    DataArrSIZE = 0;
    printf("Plz input Data Elment: \n");
    while(scanf("%d", &Data[DataArrSIZE]) != EOF){//辨識為 EOF 則直接運行到結尾結束程式
        if(Data[DataArrSIZE] == -1234){break;}//辨識為 -1234則表示輸入完畢
        DataArrSIZE++;
    }
    
    Data[DataArrSIZE] = -1;//陣列最後一筆資料為-1（以-1來識別陣列最後一筆資料）

    /*呼叫副程式*/
    buildHeapTree();//建立heap tree
    printTree();//打印出heap tree

    /*陣列儲存格式 的列印*/
    // for (i=0; i<=DataArrSIZE; i++){
    //     printf("%d ", Data[i]);
    // }

    char request;
    while(request != '0'){

        /*功能鍵Menu*/
        printf(" press 1        insert data\n"
            " press 2        Delete data\n"
            " press 0        End of run\n"
            "--------------------------------\n");
        scanf("%s", &request);//輸入功能選項
        switch(request){
            case '1':
                insert();//Data添加功能
                buildHeapTree();//重新建立Heap Tree
                break;
            case '2':
                delete();//Data刪除功能
                buildHeapTree();//重新建立Heap Tree
                break;
            case '0':
                delete();//Data刪除功能
                buildHeapTree();//重新建立Heap Tree
                break;
            default:
                puts("Plz input Corr Key to select function");//錯誤訊息
                break;
        }
        printTree();

    }

    /*結束運行提示語*/
    printf( "End of run... ...\n"
            "-------------------------\n\n");

    return 0;
}
