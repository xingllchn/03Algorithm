/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-14
Description		: 
			Palindrome Number
<<<<<<< HEAD
知识点	:
			1)C99中加入stdbool.h
核心思想	:
			1)取该值的反向值，比较大小即可
=======
鐭ヨ瘑鐐�	:
			1)
鏍稿績鎬濇兂	:
			1)鍙栬鍊肩殑鍙嶅悜鍊硷紝姣旇緝澶у皬鍗冲彲
>>>>>>> 0de8b234f6af1d940e99538c4a75d1d78cbe2cee
*/
#include <stdio.h>
#include <stdbool.h>
//褰㈠紡涓�
bool isPalindrome1(int x) {
    if (x < 0) return false;

    int t = x;
    int mask = 1;
    while (t >= 10) {
        mask *= 10;
        t /= 10;
    }

    int l, r;
    while (x) {
        r = x % 10;
        l = x / mask;
        if (l != r) return false;
        x = (x % mask) / 10;
        mask /= 100;
    }

    return true;
}
//褰㈠紡浜�
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
