#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Data[10]={0,1,2,3,4,5,6,7,8,9};
char Msg[64];
char holdChar[2];


int main(){

    int i;

    for(i=0; i<10; i++){
        sprintf(holdChar,"%d",Data[i]);
        strcat(Msg," ");
        strcat(Msg,holdChar);
        
    }

    printf("%s",Msg);


    return 0;
}