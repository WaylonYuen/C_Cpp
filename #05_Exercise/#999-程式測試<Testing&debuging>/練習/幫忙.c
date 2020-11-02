
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(){
    int getNumber;
    int i,y;
    while(scanf("%d",&getNumber) != EOF){
        y=0;

        for(i=2; i<sqrt(getNumber); i++){
            if(getNumber%i == 0){
                printf("NOT prime\n");
                y++;
                break;
            }
        }
        if(y==0) printf("Prime\n");
    }

return 0;
}