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
֪ʶ��:
	calloc�ڶ�̬�������ڴ���Զ���ʼ�����ڴ�ռ�Ϊ�㣬��malloc����ʼ�������������������������ݡ�
����˼��:
	1)���ķ���ż���
	2)���Ż�׼i���������������Ƿ�����ȵ������ַ�
	3)������ȣ������start��maxLen��ֵ�����ս��ַ�����ĵ�start��ʼ������ΪmaxLen�����ַ��������
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
		//���1:����Ϊż��
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
		//���2:����Ϊ����
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
