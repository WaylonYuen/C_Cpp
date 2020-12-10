#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define SIZE 30

int main()
{
	char input[SIZE] = {'\0'};
	char stack[SIZE] = {'\0'};
	int i, top = -1;
	
	printf("Please input '([{' or ')]}':\n");
	scanf("%s", input); //這裡input不用加&是因為input本身就代表著字元陣列的第一個位址
	
	
	/* 從輸入的一串括號 第一個字元開始讀 一次一個字元 */
	/* 註1: 假設input字串的長度為4  若順利執行迴圈 在最後i仍會加一變成4 使迴圈繼續條件 i < strlen(input)不成立 結束迴圈 */
	for(i = 0 ; i < strlen(input) ; i++) 
	{
		if(input[i] == '(' || input[i] == '[' || input[i] == '{')
			stack[++top] = input[i]; //遇到左括號存入stack
		else if(input[i] == ')') //遇到 ) 判斷stack內最上面的是不是 ( 如果不是就跳出迴圈 
		{
			if(stack[top] == '(')
				stack[top--] = '\0'; //若成對 拿掉stack的top   然後top會減一
			else
				break;
		}
		else if(input[i] == ']')
		{
			if(stack[top] == '[')
				stack[top--] = '\0'; 
			else
				break;
		}
		else if(input[i] == '}')
		{
			if(stack[top] == '{')
				stack[top--] = '\0';
			else
				break;
		}
	}
	
	if(top != -1)
		printf("N, stack is not empty.");
	else if(i != strlen(input) ) //參考上方 註1 
		printf("N, it breaks early due to mismatch of brackets.");
	else
		printf("Y");


} 
