#include <stdio.h>


int main(void){

    int i, num;
    int counter = 0;

    for(i = 0; i < 5; i++) {

        int j = 0;                  //Initial
        char Hold[20] = {};         //Initial

        scanf("%d", &num);          //input
        sprintf(Hold, "%d", num);   //transform
        
        while(Hold[j] != '\0') j++; //calculus

        printf("%c", Hold[j--]);    //Testing output

        switch (Hold[j--]) {
            case '0': counter--; break;
            case '1': counter++; break;
            case '2': counter--; break;
            case '3': counter++; break;
            case '4': counter--; break;
            case '5': counter++; break;
            case '6': counter--; break;
            case '7': counter++; break;
            case '8': counter--; break;
            case '9': counter++; break;
            default: break;
        }
    }
    
    printf("%d", counter);  //output Ans

    return 0;
}