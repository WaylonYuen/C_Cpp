#include<stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void bubbleSort(int Data[], int size);
void Append_Data(int Data[], int size, int information);
void Show_Data(int Data[], int size);
void Move_Data(int Data[], int Start_Number, int size);

int main(){

    int size=0;
    int information;
    int Data[256];
    
    /*input*/
    while(scanf("%d", &information) != EOF || size == 255){
        Data[size] = information;
        size++;
    }

    /*sort*/
    bubbleSort(Data, size);

    /*output*/
    Show_Data(Data, size);

    /*append*/
    scanf("%d", &information);
    size++;
    Append_Data(Data, size, information);

    /*output*/
    Show_Data(Data, size);

    return 0;
}

void bubbleSort(int Data[], int size){

    int temp;
    int i,j;

    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            SWAP(Data[j],Data[j+1],temp);
        }
    }

}

void Append_Data(int Data[], int size, int information){

    int front;
    int rear;

    /*Binary*/

}

void Move_Data(int Data[], int Start_Number, int size){

    int i;

    for(i=size; i<=Start_Number; i--){
        Data[size+1] = Data[size];
    }

}

void Show_Data(int Data[], int size){
    int i;

    for(i=0; i<size; i++){
        printf("%d ", Data[i]);
    }

    puts("\n");

}

