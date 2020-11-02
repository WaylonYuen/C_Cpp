#include <stdio.h>
#include <stdlib.h>

int Bin[100] = {2};

int ToBin(int N){

    int counter=0;

    /*Dem to Bin*/
    while( N>=1 ){
        Bin[counter] = N%2;
        N = (int)(N/2);

        counter++;
    }

    /*SWAP*/
    // int i, j=0, temp;
    // for(i=counter-1; i>=counter/2; i--){
    //     temp = Bin[i];
    //     Bin[i] = Bin[j];
    //     Bin[j] = temp;
    //     j++;
    // }

    return counter;
}

int main(){

    int i,j;
    unsigned int Number = 50;

    scanf("%u", &Number);
    scanf("%d", &i);

    int LenghtCounter = ToBin(Number);

    /*Testing*/
    // for(j=0; j<LenghtCounter; j++){
    //     printf("%d", Bin[j]);
    // }

    printf("%d ", Bin[i+2-1]);
    printf("%d ", Bin[i+4-1]);
    printf("%d ", Bin[i+6-1]);
    printf("%u\n", Number);

    return 0;
}