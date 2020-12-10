#include<stdio.h> 

int main(){

    int i,j,k;
    int level;	
    char request; 
    
    scanf("%d %c", &level, &request);

    switch(request){
        case 'A':
            /*triangle L\ */
            for(i=0; i<level; i++){		
                for(j=0; j<=i; j++){
                    printf("*");
                }	
                printf("\n");	
            }
            break;

        case 'B': 
            /*triangle 「/ */
            for(i=0;i<=level;i++){		
                for(j=i;j<level;j++){
                    printf("*");
                }	
                printf("\n");	
            }
            break;

        case 'C': 
            /*triangle \7 */
            for(i=0;i<level;i++){
                for(k=0;k<=i;k++){
                    printf(" ");	
                }	
                for(j=i;j<level;j++){
                    printf("*");		
                }
                printf("\n");
            }
            break;

        case 'D': 
            /*triangle /」 */
            for(i=0;i<level;i++){	
                for(k=i;k<level;k++){
                    printf(" ");	
                    }	
                for(j=0;j<=i;j++){		
                    printf("*");
                }	
                printf("\n");	
            }
            break;

        default: 
            printf("\nPlz input the correct options\n");
            break;    
    }

    puts("End...\n\n");

	return 0;			
}
		

	

