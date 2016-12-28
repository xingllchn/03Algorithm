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
void getLetterCom1(char** res,char* digits,char* tmp,int index,char map[10][5],int *top)
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
		getLetterCom1(res,digits,tmp,index+1,map,top);
	}
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations1(char* digits, int* returnSize)
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
	 getLetterCom1(res,digits,tmp,0,map,&top);
	 *returnSize=top;
	 return res;
}
//test2

void SubCombination2(char* digits, char map[][5], char* output, char** ret, int* returnSize, int k) 
{    //k表示递归到当前字母的下标    
	int i = 0;    
	if(digits[k]=='\0')
	{     //基准情况；递归到字符串结束处，将当前输        
		output[k]= '\0';
		if(k)strcpy(ret[(*returnSize)++], output);//复制字符串到输出数组        
		return;    
	} 
	while(map[digits[k] -  '0'][i]) 
	{ //当前数字对应的每一个字母进行递归        
		output[k] = map[digits[k] - '0'][i];        
		SubCombination2(digits, map, output, ret, returnSize, k + 1);        
		++i;    
	}
}
char** letterCombinations2(char* digits, int* returnSize) 
{
	int i = 0;
	*returnSize = 0;    
	char map[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};    
	char output[20] = {};       
	//输出字符串    
	char **ret = (char **)malloc(sizeof(char *) * 1000);    
	for(i = 0; i < 1000; ++i)        
		ret[i] = (char *)malloc(sizeof(char) * 20);    
	SubCombination2(digits, map, output, ret, returnSize, 0);    
	//从第一个字母开始递归保存每一个数字对应字母，到结尾处保存对应字符串    
	return ret;
}

int main(int argc,char **argv)
{
	char* digits ={"23"};//char* digits ={"234"};
	int returnSize=0;
	int i=0,j=0;
	char ** results;
	results = letterCombinations1(digits, &returnSize);
	for(i=0;i<returnSize;i++)
	{
		for(j=0;results[i][j]!='\0';j++)
			printf("%c ",results[i][j]);
		printf("\n");
	}
	printf("returnSize =%d\n",returnSize);
	return 0;
}
