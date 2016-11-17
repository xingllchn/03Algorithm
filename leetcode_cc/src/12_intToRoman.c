/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-18 07:00
author		:	xingllchn
Description	: 
			Given an integer, convert it to a roman numeral.
			Input is guaranteed to be within the range from 1 to 3999.
知识点	:
			1)罗马数字:
			1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
			10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
			100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
			1000~3000: {"M", "MM", "MMM"}.
分析	:
			1)尤其注意:V,L,D,C的左右
*/
#include <stdio.h>
#include <stdlib.h>
char *intToRoman(int num)
{
	//3999最多为MMMCMXCIX,即为9个字符,加入结尾福故申请10个字节空间
	char *s = (char *)calloc(10, sizeof(char));
	int i = 0;
	while (num > 0)
	{
		while (num >= 1000) {
		    s[i] = 'M';
		    num -= 1000;
		    i++;
		}
		if (num >= 900) {
		    s[i] = 'C'; s[i + 1] = 'M';
		    i += 2;
		    num -= 900;
		}
		while (num >= 500) {
		    s[i] = 'D';
		    num -= 500;
		    i++;
		}
		if (num >= 400) {
		    s[i] = 'C'; s[i + 1] = 'D';
		    i += 2;
		    num -= 400;
		}
		while (num >= 100) {
		    s[i] = 'C';
		    num -= 100;
		    i++;
		}
		if (num >= 90) {
		    s[i] = 'X'; s[i + 1] = 'C';
		    i += 2;
		    num -= 90;
		}
		while (num >= 50) {
		    s[i] = 'L';
		    num -= 50;
		    i++;
		}
		if (num >= 40) {
		    s[i] = 'X'; s[i + 1] = 'L';
		    i += 2;
		    num -= 40;
		}
		while (num >= 10) {
		    s[i] = 'X';
		    num -= 10;
		    i++;
		}
		if (num >= 9) {
		    s[i] = 'I'; s[i + 1] = 'X';
		    i += 2;
		    num -= 9;
		}
		while (num >= 5) {
		    s[i] = 'V';
		    num -= 5;
		    i++;
		}
		if (num >= 4) {
		    s[i] = 'I'; s[i + 1] = 'V';
		    i += 2;
		    num -= 4;
		}
		while (num >= 1) {
		    s[i] = 'I';
		    num -= 1;
		    i++;
		}
	}
	return s;
}

int main() {
    int a = 2014;
    int b = 2015;
    /* should be MMXIV */
    printf("%s\n", intToRoman(a));
    /* should be MMXV */
    printf("%s\n", intToRoman(b));
    return 0;
}
