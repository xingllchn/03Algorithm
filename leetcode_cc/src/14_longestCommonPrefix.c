/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-19 22:44
author		:	xingllchn
Description	: 
			Write a function to find the longest common prefix string amongst an array of strings.
知识点	:
			
分析	:
			1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
	char *ans;
	int i, j;
	if (strsSize == 0)
	{
		ans = "";
		return ans;
	}
	//保存数组第一个字符串到堆中的ans
	ans = malloc(strlen(strs[0]));
	strcpy(ans, strs[0]);

	for (j = 0; ans[j] != '\0'; j++) 
	{
		//以列为基础，进行比较，不相等则退出
		for (i = 1; i < strsSize; i++) 
		{
			if (strs[i][j] != ans[j]) 
			{
				ans[j] = '\0';
				return ans;
			}
		}
	}
	return ans;
}

int main() {
    char *strs[3] = {
        "abcde",
        "abceawsdffd",
        "abcsdas",
    };
    char *s = longestCommonPrefix(strs, 3);
    printf("%s\n", s);
    return 0;
}
