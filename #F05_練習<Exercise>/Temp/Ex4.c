#include <stdio.h>

#include <stdlib.h>
#include <time.h>


int main(){
    int Ans;
    int i , j , k , l , m , n;

    int container[10]={0} ,container2[10]={0};
    srand(time(NULL));

    for(i=0;i<1000;i++){
        Ans= rand() % 10;
        switch (Ans)
        {
        case 0 :
            container [0]++;/* code */
            break;
        case 1 :
        container [1]++;
        break;
        case 2 :
        container [2]++;
        break;
        case 3 :
        container [3]++;
        break;
        case 4 :
        container [4]++;
        break;
        case 5 :
        container [5]++;
        break;
        case 6 :
        container [6]++;
        break;
        case 7 :
        container [7]++;
        break;
        case 8 :
        container [8]++;
        break;
        case 9 :
        container [9]++;
        break;
        default:
            break;
        }
    }
    for(j=0 ; j<=9 ; j++){
        printf("%d = %d/1000\n", j , container[j]);
    }
    for(k=0 ; k<=9 ; k++){
        for(l=0 ; l<=9 ; l++){
            if(container[k]>container[l]){
              container2[k]++;
            }
       }
    }
    for(n=0 ; n<=9 ; n++){
        printf(" '%d' win %d times \n", n , container2[n]);
    }
    return 0;
}