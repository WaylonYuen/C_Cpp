#include<stdio.h>

int main(){

    int i,j;
    int det2[2][2];
    int ans;

    /*input*/
    for(i=0; i<=1; i++){        //row
        for(j=0; j<=1; j++){    //column
            scanf("%d", &det2[i][j]);
        }
    }

    /*Output*/
    for(i=0; i<=1; i++){        //row
        printf(" |  ");
        for(j=0; j<=1; j++){    //column
            printf("\t%d", det2[i][j]);
        }
        printf("\t|\n");
    }

    /*det-Operation*/
    ans = det2[0][0] + det2[1][1] - (det2[0][1] + det2[1][0]);

    /*Output*/
    printf("det = %d \n", ans);

    return 0;
}