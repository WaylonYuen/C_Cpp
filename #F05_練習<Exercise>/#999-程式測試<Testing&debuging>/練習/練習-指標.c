#include<stdio.h>

#define SIZE 10

void print(int* Arr){
    int i;

    for(i=0; i<SIZE; i++){
        printf("%d ", Arr[i]);
    }

}

void inputData(int* Arr){
    int i;

    for(i=0; i<SIZE; i++){
        Arr[i] = i;
    }

}

int main(){

    int data[SIZE];

    inputData(&data[0]);
    print(&data[0]);
    

    return 0;
}