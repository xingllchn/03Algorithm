/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-17
author		:	xingllchn
Description	: 
		Example1: x = 123, return 321
		Example2: x = -123, return -321
			
֪ʶ��	:
			1)stdint.h��c99��������һ����׼C����ļ�,��Ч����stdint.hͷ�ļ��еĺ궨��
����˼��	:
			1)�������ݷ�ת����ܵ����
*/

#include <stdio.h>
#include <stdint.h>

// ����������,��Ϊ��ֵ��תΪ��ֵ���ñ�־λ1�����Դ�ַ���
int check(int a, int *p) {
    int64_t ret = (int64_t)a;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}
//ȡ���������ⲿretֵΪ��׼�������ۼ�
int check_add(int a, int b, int *p) {
    int64_t ret = (int64_t)a + (int64_t)b;
    *p = (int)ret;
    return ret >= INT32_MAX || ret <= INT32_MIN;
}
//ȡ����������10��ʹ��ֵʮ��������һλ
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
	//�����һλ
	if (check_add(ret, x, &ret)) return 0;
	//�����־λsignΪ�����Է�ת���ֵȡ��
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
