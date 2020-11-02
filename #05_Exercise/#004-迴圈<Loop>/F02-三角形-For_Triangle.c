#include<stdio.h> 

int main(){

    int i,j,k;	

//triangle V:printf====================================================
    printf("1)\n\n");
	for(i=0;i<=9;i+=2){	
		for(j=i;j<=8;j++){
			printf("*");
			if(j==8){
				printf("\n");
				for(k=0;k<=i;k+=2){
					printf(" ");	
				}	
			}		
		}
	}
	
//triangle ^:printf====================================================
    printf("\n\n2)\n\n");
	for(i=0;i<=9;i+=2){		
		for(k=i;k<=6;k+=2){
			printf(" ");
		}	
		for(j=0;j<=i;j++){
			printf("*");
		}	
		printf("\n");	
	}
	
//triangle |>:printf====================================================
    printf("\n\n3)\n\n");
	for(i=0;i<=9;i+=2){		
		for(j=0;j<=i;j++){
			printf("*");
		}	
		printf("\n");	
	}
    
//triangle |>:printf====================================================
    printf("\n\n4)\n\n");
	for(i=0;i<=9;i+=2){		
		for(j=i;j<=8;j++){
			printf("*");
		}	
		printf("\n");	
	}
	
//triangle |>:printf====================================================
    printf("\n\n5)\n\n");
	for(i=0;i<=8;i+=2){
		for(k=0;k<=i;k++){
			printf(" ");	
		}	
		for(j=i;j<=8;j++){
			printf("*");		
		}
		printf("\n");
	}

//triangle |>:printf====================================================
    printf("\n\n6)\n\n");
	for(i=0;i<=9;i+=2){	
		for(k=i;k<=8;k++){
			printf(" ");	
			}	
		for(j=0;j<=i;j++){		
			printf("*");
		}	
		printf("\n");	
	}
		
	return 0;			
}
		

	

