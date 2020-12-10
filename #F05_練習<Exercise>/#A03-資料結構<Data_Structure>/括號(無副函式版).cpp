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
	scanf("%s", input); //�o��input���Υ[&�O�]��input�����N�N��ۦr���}�C���Ĥ@�Ӧ�}
	
	
	/* �q��J���@��A�� �Ĥ@�Ӧr���}�lŪ �@���@�Ӧr�� */
	/* ��1: ���]input�r�ꪺ���׬�4  �Y���Q����j�� �b�̫�i���|�[�@�ܦ�4 �ϰj���~����� i < strlen(input)������ �����j�� */
	for(i = 0 ; i < strlen(input) ; i++) 
	{
		if(input[i] == '(' || input[i] == '[' || input[i] == '{')
			stack[++top] = input[i]; //�J�쥪�A���s�Jstack
		else if(input[i] == ')') //�J�� ) �P�_stack���̤W�����O���O ( �p�G���O�N���X�j�� 
		{
			if(stack[top] == '(')
				stack[top--] = '\0'; //�Y���� ����stack��top   �M��top�|��@
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
	else if(i != strlen(input) ) //�ѦҤW�� ��1 
		printf("N, it breaks early due to mismatch of brackets.");
	else
		printf("Y");


} 
