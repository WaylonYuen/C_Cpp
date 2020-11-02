#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

void infixToPostfix(char* infix, char* postfix);
int getPriority(char symbol);
void printStatus();

int main(){
	char infix[SIZE] = {'\0'};
	char postfix[SIZE] = {'\0'};
	int i;
	
	printf("Please enter a formula:\n");
	scanf("%s", infix); //�]��infix�����N�O��} �ҥH�����[�W&
	
	infixToPostfix(infix, postfix);
	
	/* 
	for(i = 0; postfix[i] != '\0'; i++) {
        printf("%c", postfix[i]); 
    }
    */ 
	printf("Postfix: %s", postfix);
	return 0;
} 

void infixToPostfix(char* infix, char* postfix){
	int i, j, top;
	char stack[SIZE] = {'\0'}; 
	
	for(i=0, j=0, top=-1 ; infix[i] != '\0' ; i++){
		switch(infix[i]){
			case '(':
				stack[++top] = infix[i]; //�[�J���| 
				break;
				
			case ')':
				while(stack[top] != '('){ 
					postfix[j++] = stack[top--]; //�q���|���X�ÿ�X
				}
				top--; //����X ( 
				break;
				
			case '+':
			case '-':
			case '*':
			case '/':
				while(getPriority(stack[top]) >= getPriority(infix[i]) ){
					postfix[j++] = stack[top--];
				}
				stack[++top] = infix[i]; //�[�J���| 
				break;
				
			default:
				postfix[j++] = infix[i]; //�J��Ʀr������X 
				break;
		} // end of switch
	} //end of for
	while(top > -1){
			postfix[j++] = stack[top--];
	}
}

int getPriority(char symbol){
	if(symbol == '*' || symbol == '/'){ return 2; }
	if(symbol == '+' || symbol == '-'){ return 1; }
	return 0;
	
//	switch(symbol) { 
//        case '+': case '-': return 1;
//        case '*': case '/': return 2;
//        default:            return 0;
//    } 	
}
