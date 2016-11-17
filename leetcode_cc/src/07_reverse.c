/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-17
author		:	xingllchn
Description	: 
		Example1: x = 123, return 321
		Example2: x = -123, return -321
			
知识点	:
			1)stdint.h是c99中引进的一个标准C库的文件,有效利用stdint.h头文件中的宏定义
核心思想	:
			1)考虑数据反转后可能的溢出
*/

#include <stdio.h>
#include <stdint.h>

// 检查数据溢出,若为负值，转为正值，置标志位1，并以传址输出
int check(int a, int *p) {
    int64_t ret = (int64_t)a;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}
//取余数，以外部ret值为基准，进行累加
int check_add(int a, int b, int *p) {
    int64_t ret = (int64_t)a + (int64_t)b;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}
//取除数，乘以10，使该值十进制左移一位
int check_mul(int a, int b, int *p) {
    int64_t ret = (int64_t)a * (int64_t)b;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}

int reverse(int x) {
	int ret = 0;
	int sign = 0;
	if (x < 0) {
	    if (check(-x, &x)) return 0;
	    sign = 1;
	}
	while (x >= 10) {
	    if (check_add(ret, x % 10, &ret)) return 0; 
	    if (check_mul(ret, 10, &ret)) return 0;
	x /= 10;
	}
	//加最后一位
	if (check_add(ret, x, &ret)) return 0;
	//如果标志位sign为负，对反转后的值取反
	if (sign) 
	    if (check(-ret, &ret)) return 0;
	return ret;
}

int main() {
    	int x = 123;
    	printf("%d\n", reverse(x));
	x = -123;
    	printf("%d\n", reverse(x));
    	return 0;
}
