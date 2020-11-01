#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define  MAX 100

struct  polynomial{
    int coef;       //係數
    int expon;      //指數 
};

struct MyPoly{
    
    polynomial terms[MAX];      //多項式陣列
    int size;                   //多項式大小

    MyPoly();                   //建構子 初始化size=0
    MyPoly(const char*);        //建構子 讀入檔案

    void ShowPoly();            //印出多項式內容
    MyPoly Add(MyPoly);         //多項式相加
    void SingleMult(int);       //將多項式乘上一係數
    int Lead_Exp();             //回傳多項式中最大指數的係數
    void Attach(int,int);       //新增一項至多項式中
    void Remove(int);           //刪除多項式中的某一指數
    //MyPoly Mult(MyPoly);        //多項式相乘
};

int main(){

    MyPoly A("a.txt");          //A多項式
    A.ShowPoly();               
    
    //int a;
    //scanf("%d", &a);

    MyPoly B("b.txt");          //B多項式
    B.ShowPoly();

    MyPoly C;                   
    C = A.Add(B);
    C.ShowPoly();

    MyPoly D;
    //D = A.Mult(B);
    D.ShowPoly();

   /* void ShowPoly();            //印出多項式內容
    MyPoly Add(MyPoly);         //多項式相加
    void SingleMult(int);       //將多項式乘上一係數
    int Lead_Exp();             //回傳多項式中最大指數的係數
    void Attach(float,int);     //新增一項至多項式中
    void Remove(int);           //刪除多項式一項
    void Mult(MyPoly);          //多項式相乘
    */
    return 0;
}

MyPoly::MyPoly(){
    size = 0;
}

MyPoly::MyPoly(const char* filename){
    
    FILE *fptr = fopen(filename,"r");

    if(fptr == NULL){
        printf("Error: Pointer -> %p\n", fptr);
        return;
    } else {
        printf("Open File: Pointer -> %p\n", fptr);
    }

    size = 0;
    while(!feof(fptr)){
        fscanf(fptr, "%d %d", &terms[size].coef,&terms[size].expon);
        size++;
    }
    fclose(fptr);
}

void MyPoly::ShowPoly(){
    
    int i;
    for(i=0;i<size-1;i++){
        printf("%dx^%d ",terms[i].coef, terms[i].expon);
    }
    printf("%dx^%d \n",terms[i].coef,terms[i].expon);
}

void MyPoly::SingleMult(int num){

    int i;
    for(i=0; i<size; i++){
        terms[i].coef *= num;
    }
}

MyPoly MyPoly::Add(MyPoly B){
    //MyPoly這個函數回傳值是MyPoly型態，Add函式需要MyPoly B作為參數
    MyPoly Temp;
    int sum;
    int indexA = 0, indexB = 0;
    while(indexA<size && indexB<B.size){
        //怎麼知道size是誰，不是用A.size
        if(terms[indexA].expon > terms[indexB].expon){  // A > B 
            Temp.Attach(terms[indexA].coef, terms[indexA].expon);   //把A排在B前面
            indexA++;
        } else if(terms[indexB].expon > terms[indexA].expon){   //B > A 
            Temp.Attach(terms[indexB].coef, terms[indexB].expon);   //把B排在A前面
            indexB++;
        } else { //(terms[indexA].expon=terms[indexB].expon)    //B = A 則相加
            sum = terms[indexA].coef + terms[indexB].coef;
            if(sum != 0) Temp.Attach(sum, terms[indexA].expon);
            indexA++;
            indexB++;           
        }
        Temp.ShowPoly();
    }
    //不需要起始值，從現在的index印到做完為止，已做完的程式會自動跳過
    for(; indexA<size; indexA++) Temp.Attach(terms[indexA].coef,terms[indexA].expon);   
    for(; indexB<B.size; indexB++) Temp.Attach(terms[indexB].coef,terms[indexB].expon);

    return Temp;
}

//不懂這個怎麼叫印出3(印出領導係數)
int MyPoly::Lead_Exp(){
    if(size == 0) return 0; 
    else return terms[0].coef; //老師寫return terms[0].expon;
}

//input coefection
void MyPoly::Attach(int coef, int expon){
    polynomial temp;
    int pos = 0, i;
    temp.coef = coef;
    temp.expon = expon;
    //為什麼不用寫A.size==0
    if(size == 0){
        size++;
        terms[0] = temp;
    } else {
        //不懂這個在幹嘛
        while(terms[pos].expon > temp.expon && pos < size) pos++;      
        for(i=size;i>pos;i--) terms[i] = terms[i-1];
        
        terms[i] = temp;
        size++;
    }
}

//num是要移除那項的指數之值
void MyPoly::Remove(int num){
    int pos = 0, i;

    //一直判斷直到要刪除的那項
    while(terms[pos].expon>num) pos++;
    
    //後面的資料全部往前覆蓋
    for(i=pos; i<size-1; i++) terms[i] = terms[i+1];
    
    size--;
}

//相乘
/*甚麼時候用MyPoly Temp
  甚麼時候用polynomial temp*/
/*
MyPoly MyPoly::Mult(MyPoly B){
    MyPoly Temp;
    int indexA = 0,indexB = 0;

    while(indexA<size&& indexB<B.size){

    }

    return Temp;
}*/