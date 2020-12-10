#include<stdio.h> 
#include<stdlib.h>

int Coordinate_Lock(int Lock[]){
	
	int start = 0;			//The coordinate of central
	int   Top = -1;  		//The First row is the top of Matrix
	int  Left = 0;  		//Difference of left's value
	int Right = 0;  		//Difference of Right's value
	int Y_Coordinate = 0;	//The Y-coordinate of Matrix's value
	int X_Coordinate = 0;  	//The X-coordinate of Matrix's value

	scanf("%d",&start);			//Input the value of '0~80'

	
//Mark Y_Coordinate to be '1'====================================================	
	for(Y_Coordinate=start;  Y_Coordinate<=80;  Y_Coordinate+=9){					//Y›S ﬂf‘ˆ÷¡max £®µ◊≤ø£©
		Lock[Y_Coordinate]=1;	
	} 
	for(Y_Coordinate=start;  Y_Coordinate>=0;  Y_Coordinate-=9){					//Y›S ﬂfúp÷¡min £®Ìî≤ø£©
		Lock[Y_Coordinate]=1;
		Top = Y_Coordinate;
	}
				
//Mark X_Coordinate to be '1'====================================================	
	Right = (8 - Top);			// ◊¯òÀ ÷¡ Õ¨“ª––◊Ó”“µƒ≤Ó÷µ 
	Left  = (8 - Right);		// ◊¯òÀ ÷¡ Õ¨“ª––◊Ó◊Ûµƒ≤Ó÷µ 
	
	for(X_Coordinate=start;  X_Coordinate<=(start+Right);  X_Coordinate++){			//X›S ﬂf‘ˆ÷¡max £®◊Ó”“£©
		Lock[X_Coordinate] = 1;		
	}
	for(X_Coordinate=start;  X_Coordinate>=(start-Left);  X_Coordinate--){			//X›S ﬂfúp÷¡min £®◊Ó◊Û£© 
		Lock[X_Coordinate] = 1;
	}
	
//Testing of Lock[81] Value : printf====================================================
	
/*	puts("\n\n\n\n");
*			
*	for(i=0;i<=80;i++){
*		printf("%3d",Lock[i]);
*		j+=1;
*		if(j>=9){
*			printf("\n");
*			j=0;
*		}
*	}//Output Lock[] ==> 9*9	
*/

//END==========================================================================================


	
} 
	
int main(){
	
	int Lock[81] = {0};				//The Lock Matrix's start value ==> 0
	int i = 0, j = 0;					//'i' and 'j' is ordinal number of for()
	
	Coordinate_Lock(Lock);
	
// Testging :Lock[81] Value : printf====================================================	
	
	puts("\n\n\n\n");
			
	for(i=0;i<=80;i++){					
		printf("%3d",Lock[i]);
		j+=1;
		if(j>=9){
			printf("\n");
			j=0;
		}
	}
	
//END==========================================================================================	


	return 0;
}









