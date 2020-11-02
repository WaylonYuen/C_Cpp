//
//  #190226-00 F ( 實作 ) 樂透開獎 %動態記憶體空間.c
//  Version 1.0
//	
//  Created by Waylon.Yuen
//  Copyright Oracragron.Waylon.Yuen all rights reserved.
//
//  說明： 1、用動態陣列儲存是否抽過該數字
//        2、輸入3個整數：A、B、C， A～B範圍（ 包括AB兩數本身 ）中抽取C個數字出來
//        3、初始化動態陣列
//        4、由小到大的順序輸出抽到的數字
//        5、歸還動態陣列所使用的記憶體
//        6、完成整個抽籤程序
//  操作：輸入：A、B、C 三個正整數，Example：10、100、8，Explain：從10到100間隨機抽取8個數。
//  原理：利用rand()來產生隨機數 並存入動態記憶體link list中，存入的同時比較是否重複 & 比較大小（將較大的數Hold住直到小於or最後放下）
//  優化：加速link list 的 比較算法、資料循序比較的次數、隨機數產生次數
//

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

/*Functions*/
Node *create();
int Push(Node *head, int data);
void List(Node *head);
void LuckyNumber(int A, int B, int C);

/* Variable */
int SameNum_Flag = 0;

/*Randam Number*/
void LuckyNumber(int A, int B, int C){
    
	Node *head = create();
    int i;
    int LuckyNum;
    srand(time(NULL));

    for(i=1; i<=C; i++){

        /*Get Luck*/
        LuckyNum = ( rand()%(B-A+1) ) + A;   // ( rand() % (最大值-最小值+1) ) + 最小值

        /*Save to List*/
        SameNum_Flag = Push(head, LuckyNum);

        if(SameNum_Flag == 1){
            i--;
            SameNum_Flag = 0;   //ReSetting
        }
    }

    List(head); //輸出
    free(head); //釋放空間
}

/*get the memory*/
Node *create(){  
    Node *tmpNode;
    tmpNode = (Node *)malloc(sizeof(Node));	 
    if(tmpNode == NULL){
        printf("Not enough space!");
        exit(1);
    }
    tmpNode->next = NULL;
    return tmpNode;
}

/*create the Note*/
int Push(Node *head, int data){

    int temp;

    Node *tmp = create();
    tmp->next = NULL;
    tmp->data = data;

    /*add the new node in to linked lists*/ 
    Node *ptr = head;
    while(ptr->next != NULL){

        /* Same Data? */
        if(ptr->data == data){//相同比較
            printf("abandon Same Number: %d\n", data);
            free(tmp);
            return SameNum_Flag = 1;
        }

        /* Compare the Data */
        if(ptr->data > tmp->data){ //大小比較
            //插入
            //資料交換
            temp = ptr->data;
            ptr->data = tmp->data;
            tmp->data = temp;
        }

        ptr = ptr->next; //walk to next.
 
    }
    //最後一筆資料的判斷

    /* Same Data? */
    if(ptr->data == data){//相同比較
        printf("abandon Same Number: %d\n", data);
        free(tmp);
        return SameNum_Flag = 1;
    }

    /* Compare the Data */
    if(ptr->data > tmp->data){ //大小比較
        temp = ptr->data;
        ptr->data = tmp->data;
        tmp->data = temp;
    }

    ptr->next = tmp;
    return 0;
}

/*Print the List*/
void List(Node *head){
	int i=0;
    Node *ptr = head;
    while(ptr->next != NULL){
        i++;
        ptr=ptr->next;
        printf(" %d:\t%d\n", i, ptr->data);
    }
}

int main(){

    int A, B, C; 
    printf("\nPlz input the Lower Bound、Upper Bound & Number of Lucky Numbers!!!\n"
           "-------------------------------------------------------------------------\n");
    printf("Lower Bound: ");
    scanf("%d", &A); printf("\n");

    printf("Upper Bound: ");
    scanf("%d", &B); printf("\n");
    
    printf("Number of Lucky Numbers: ");
    scanf("%d", &C); printf("\n");
    
    if(C < A-B){
        printf("Error input!!!\nCheck the range of A、B、C、\n");
    }else{
        LuckyNumber(A, B, C);
    }

    printf("\n\n========================\n"
           "End of run...\n\n\n");

	return 0;
} 