/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-18 07:00
author		:	xingllchn
Description	: 
			Given a roman numeral, convert it to an integer.
			Input is guaranteed to be within the range from 1 to 3999.
知识点	:
			1)罗马数字:
			1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
			10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
			100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
			1000~3000: {"M", "MM", "MMM"}.
分析	:
			1)
*/
#include <stdio.h>
#include <string.h>

int romanToInt(char *s) 
{
	int len = strlen(s);
	int ans = 0;
	int i = 0;
	while (i < len) 
	{
		switch (s[i]) 
		{
			case 'M':
				ans += 1000;
				break;
			case 'D':
				ans += 500;
				break;
			case 'C':
				if (s[i + 1] == 'D' || s[i + 1] == 'M')
				{
				    ans -= 100;
				}
				else {
				    ans += 100;
				}
				break;
			case 'L':
				ans += 50;
				break;
			case 'X':
			   	 if (s[i + 1] == 'L' || s[i + 1] == 'C')
				{
			       	 ans -= 10;
			    	}
			    	else 
				{
			       	 ans += 10;
			    	}
			    	break;
			case 'V':
			    	ans += 5;
			    	break;
			case 'I':
			   	 if (s[i + 1] == 'V' || s[i + 1] == 'X')
				 {
			        	ans -= 1;
			    	}
			    	else 
				{
			       	ans += 1;
			    	}
			    	break;
			default:
			    	break;
		}
		i++;
	}
	return ans;
}

int main() {
    char s1[] = "MMXVI";
    char s2[] = "MMXVII";
    /* 2016*/
    printf("%d\n", romanToInt(s1));
    /* 2017*/
    printf("%d\n", romanToInt(s2));
    return 0;
}
