/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-14
Description		: 
		Implement atoi to convert a string to an integer.
			
知识点	:
			1)
核心思想	:
			1)需考虑空格、正负号、负值极限、溢出
*/
#include <stdio.h>
#include <stdint.h>

int myAtoi(char *str) {
	int64_t ret = 0;
	int sign = 1;
	char *p = str;
	//一:考虑空格
	while (*p == ' ') p++;
	//二:考虑正负号
	if (*p == '-') {
	    sign = -1;
	    p++;
	}
	else if (*p == '+') {
	    sign = 1;
	    p++;
	}
	//正常范围
	while (*p >= '0' && *p <= '9') {
		ret = ret * 10 + (*p - '0');
		//负值极限
		if (ret - 1 > INT32_MAX) ret = (int64_t)INT32_MAX + 1;
		p++;
	}

	if (sign == -1) ret = -ret;
	//三:考虑溢出
	if (ret > INT32_MAX) ret = INT32_MAX;
	if (ret < INT32_MIN) ret = INT32_MIN;

	return (int)ret;
}

int main() {
	char *s[5];
	int i=0;
	s[0] = "  123 ";
	s[1] = "2147483647";
	s[2] = "2147483648";
	s[3] = "-2147483648";
	s[4] = "-2147483649";

	for (i = 0; i < 12; i++)
		printf("%d\n", myAtoi(s[i]));

    return 0;
}

