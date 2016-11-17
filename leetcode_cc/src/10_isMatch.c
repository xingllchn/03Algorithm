/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-14
Description	: 
			'.' Matches any single character.
			'*' Matches zero or more of the preceding element.
			Some examples:
				isMatch("aa","a") �� false
				isMatch("aa","aa") �� true
				isMatch("aaa","aa") �� false
				isMatch("aa", "a*") �� true
				isMatch("aa", ".*") �� true
				isMatch("ab", ".*") �� true
				isMatch("aab", "c*a*b") �� true
֪ʶ��	:
			1)C99�м���stdbool.h
����˼��	:
			1)
*/
#include <stdio.h>
#include <stdbool.h>
bool isMatch(const char *s, const char *p)
{
	//���*pΪ��,����*s�Ƿ�Ϊ�յ��ж�
	if(*p == '\0')
		return *s == '\0';  
	if(*(p+1) != '*')  
	{  
	    if(*s != '\0' && (*s == *p || *p == '.'))
			return isMatch(s+1,p+1);  
	}  
	else //���*p�ĵڶ���Ϊ*
	{  
	    //ƥ��*s�����ֵ
	    while(*s != '\0' && (*s == *p || *p == '.'))  
	    {  
	        if(isMatch(s,p+2))return true;  
	        ++s;  
	    }  
	    return isMatch(s,p+2);  
	}  
	return false;  
}  
int main(int argc,char **argv)
{
	bool flag=false;
	
	const char *s="aab";
	const char *p="c*a*b";
	
	flag =isMatch(s, p);
	printf("%d\n",flag);
	
	return 0;
}
