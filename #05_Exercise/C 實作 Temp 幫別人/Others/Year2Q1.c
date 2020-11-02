//
//  Created by Waylon.Yuen on 09/24/2019.
//  Copyright © 2019年 Oracragron. All rights reserved.
//

#include <stdio.h> 
#include <stdlib.h>

/*副程式宣告*/
void perm(char ch[], int begin, int end, char *Output);
 
/*全域變量宣告*/
const int NumberOfValue = 2;

int main() {

	int len;
	char Output[100];
	char Comb[NumberOfValue] = {'0', '1'};	//組合基底

	printf("Input a number: "); 
	scanf("%d", &len); 

	perm(Comb, 0, len, Output); 

	return 0;
}

void perm(char ch[], int begin, int end, char *Output) {

	int i;

	if(begin >= end) {	
		for(i = 0; i < end; i++){
			printf("%c ", Output[i]);
		}
		puts("");
	} else {
		for(i = 0; i < NumberOfValue; i++){
			Output[begin] = ch[i];
			perm(ch, begin+1, end, Output);
		}
	}
}

