/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-14
Description	: 
			Palindrome Number
知识点	:
			1)C99中加入stdbool.h
核心思想	:
			1)取该值的反向值，比较大小即可
*/
#include <stdio.h>
#include <stdbool.h>
//形式一
bool isPalindrome1(int x) 
{
	if (x < 0) return false;

	int t = x;
	int mask = 1;
	while (t >= 10) 
	{
		mask *= 10;
		t /= 10;
	}

	int l, r;
	while (x) 
	{
		r = x % 10;
		l = x / mask;
		if (l != r) return false;
		x = (x % mask) / 10;
		mask /= 100;
	}

	return true;
}
//形式二
bool isPalindrome2(int x)
{
	int t=0,m=x;
	while(m)
	{
		t*=10;
		t+=m%10;
		m/=10;
	}
	return t==x;
}
int main()
{
	int a = 1234321;
	printf("%d\n", isPalindrome1(a));
	printf("%d\n", isPalindrome2(a));
	return 0;
}