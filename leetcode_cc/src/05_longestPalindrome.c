/*
From			:	https://leetcode.com/problemset/algorithms/
to			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Description	: 
			Example:
				Input: "babad"
				Output: "bab"
			Example:
				Input: "cbbd"
				Output: "bb"
知识点:
	calloc在动态分配完内存后，自动初始化该内存空间为零，而malloc不初始化，里边数据是随机的垃圾数据。
核心思想:
	1)回文分奇偶情况
	2)沿着基准i左右搜索，查找是否有相等的两个字符
	3)若有相等，则更新start和maxLen的值，最终将字符数组的第start开始，长度为maxLen的子字符串输出。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *s1;
char * longestPalindrome(char *  s)
{
	int n = strlen(s);
	char *s2;
	int start = 0, maxLen = 1; 
	int i, j, k ;
	s1 =(char *)calloc(n,sizeof(char));
	if(!s1)
		return NULL;
	s2 =s1;
	for (i = 0; i < n; i++) 
	{
		//情况1:回文为偶数
	    	j = i, k = i + 1; 
	    	while (j >= 0 && k < n) 
		{
		        if (s[j] != s[k]) 
					break;
		        if (k - j + 1 > maxLen) 
			{
		            start = j;
		            maxLen = k - j + 1;
		        }
		        j--;
		        k++;
	    	}
		//情况2:回文为奇数
	    	j = i - 1, k = i + 1; 
	    	while(j >= 0 && k <= n - 1) 
		{
		        if (s[j] != s[k]) 
					break;
		        if (k - j + 1 > maxLen) {
		            start = j;
		            maxLen = k - j + 1;
		        }
		        j--;
		        k++;
	    	}
	}
	while(maxLen--)
	{
		*s1++=s[start];
		start++;
	}
	return s2;
}
int main() {
	char * str0 = {"aabac"};
	char * str1 = {"abcb"};
	char *s;
	s=longestPalindrome(str0);
	free(s1);
	printf("%s\n",s);
	s=longestPalindrome(str1);
	free(s1);
	printf("%s\n",s);
	return 0;
}
