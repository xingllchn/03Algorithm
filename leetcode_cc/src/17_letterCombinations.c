/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-19 22:44
author		:	xingllchn
Description	: 
			A mapping of digit to letters (just like on the telephone buttons) is given below.
			Input:Digit string "23"
			Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
知识点	:
			
分析	:
			1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void getLetterCom(char** res,char* digits,char* tmp,int index,char map[10][5],int *top)
{
	int i,digit=digits[index]-'0';
	char* letters;
	if(digits[index]==0)
	{
		letters=(char*)malloc(sizeof(char)*index);
		tmp[index]=0;
		strcpy(letters,tmp);
		res[*top]=letters;
		(*top)++;
		return;
	}
	for(i=0;map[digit][i];i++)
	{
		tmp[index]=map[digit][i];
		getLetterCom(res,digits,tmp,index+1,map,top);
	}
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
	 char map[10][5]={" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};//注意7和9是四个字符
	 char** res,*tmp;
	 int num=1,length=0,top=0;
	 //计算可匹配的总数
	 while(digits[length])
	 {
		 if(digits[length]=='0' || digits[length]=='1')
		 	continue;
		 else if(digits[length]=='7' || digits[length]=='9')
		 	num*=4;
		 else 
		 	num*=3;
		 length++;
	 }
	 res=(char**)calloc(num,sizeof(char*));
	 if(length==0)
	 {
		 *returnSize=0;
		 return res;
	 }
	 tmp=(char*)malloc(sizeof(char)*length);
	 getLetterCom(res,digits,tmp,0,map,&top);
	 *returnSize=top;
	 return res;
}
int main(int argc,char **argv)
{
	char* digits ={"23"};//char* digits ={"234"};
	int returnSize=0;
	int i=0,j=0;
	char ** results;
	results = letterCombinations(digits, &returnSize);
	for(i=0;i<returnSize;i++)
	{
		for(j=0;results[i][j]!='\0';j++)
			printf("%c ",results[i][j]);
		printf("\n");
	}
	printf("returnSize =%d\n",returnSize);
	return 0;
}
