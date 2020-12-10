//用陣列 (A[]) 保存5個數字，並根據輸入的號碼輸出陣列相應的值
//e.g: A[] = { 1, 2, 3, 4, 5 };
//input: 3
//output: 4

//char 字元    %c     -> Hello : { 'H','e' ...... };
//string 字串  %s     -> Hello : { "Hello" };  // "Hello\0"

// char StrA[10] = { "Hello" };
// printf("%s", StrA);  //Hello
// printf("%c", StrA[4]);  //o


// { "Hello World, I'm here." }
// char A[] =  7 4 11 11
// A7A4B11

// int Key = 2;
// { "JGIIP Yptif, K'o igkg." } 


#include <stdio.h>
#include <math.h>
#include <string.h>

int Arrary[5] = {};
char Str[] = { "hello" };
int i=0;
void Input();
void Output();
void Sort1();
void Sort2();
void Menu();
char* Strcat2(char* Ans, char* Src);
char AphBig[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char AphSmall[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void Cal();
char a[30];
void Change();
void Cal2();
int j=0;
//程式入口
int main(){
    //Input();//input
    //Menu();
    //Output();
    Cal();//Small ->Big
    Change();// Back 2 seat and the answer(English)
    


    return 0;
}

char* Strcat2(char* Ans, char* Src){

    char A[20];
    char B[20];
    int j=0,k=0;

    while(A[i] != '\0'){
        Ans[j]=A[i];
        i++;
        j++;
    }
    while(B[k] != '\0'){
        Ans[j]=B[k];
        j++;
        k++;
    }
    Ans[j]='\0';

    return Ans;
}

void Input(){

    for (i=0;i<5;i++){
        scanf ("%d",&Arrary[i]);
    }
}
void Sort1(){
    int jump;
    int A;

    for (A=0;A<5;A++){
        for (i=0;i<5-1-A;i++){
            if(Arrary[i]< Arrary[i+1]){
                jump = Arrary[i];
                Arrary[i] = Arrary[i+1];
                Arrary[i+1]=jump;
            }
        } 
    }   
}
void Sort2(){
    int jump;
    int A;

    for (A=0;A<5;A++){
        for (i=0;i<5-1-A;i++){
            if(Arrary[i] > Arrary[i+1]){
                jump = Arrary[i];
                Arrary[i] = Arrary[i+1];
                Arrary[i+1]=jump;
            }
        } 
    }   
}

void Output(){
    
    for (i=0;i<5;i++){
        printf("%d ",Arrary[i]);
    }
}

void Menu(){

    int Request;
    printf("1 is Big toward Small.\n");
    printf("2 is Small toward Big.\n");
    printf("Please input 1 or 2\n");
    //scanf
    scanf("%d",&Request);
    switch (Request) {
    case 1:
        //執行
        Sort1();
        break;
    case 2:
        //執行
        Sort2();
        break;
    
    default:
        //沒有case
        printf("Error");
        break;
    }

}
void Cal(){
    scanf("%s",a);
    int j=0;
    for(j = 0 ; j<=30 ; j++){
        for(i = 0 ; i<=25 ; i++){
            if(a[j] == AphSmall[i]){
                a[j] = AphBig[i];
            }
        }
    }
    //printf("%s\n",a);
    //printf("A=0 B=1 ... Z=25\n");
    printf("Back 2 seat and the answer = \n");
}
void Change(){
    for(i=0 ; i<=30 ;i++){
        for(j=0 ; j<=25 ; j++){
            if (a[i] == AphBig[j]){
            j+=2;
            if(j>=25){
                j=j%25;
                printf("%c",AphBig[j]);
                }
            else printf("%c",AphBig[j]);
            }
        }
    }
}
