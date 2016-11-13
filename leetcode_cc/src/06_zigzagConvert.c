/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-13
Description	: 
		The string "PAYPALISHIRING" is written in a zigzag pattern
		【	P   A   H   N
			A P L S I I G
			Y   I   R		】
		convert("PAYPALISHIRING", 3) ,return "PAHNAPLSIIGYIR".

		input:	PAYPALISHIRING,3
		output:	PAHNAPLSIIGYIR
			
知识点	:
			1)Z型数据排列方式:
				i
				0	|		|		|
				1	|	/	|	\	|
				2	|		|		|
			2)
核心思想	:
			1)zigzag型数据主要是找到每下一个数据的下标值，依次存储到下标自增(+1)的数组中
			2)规律:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int nRows) 
{
	int len = strlen(s);
	char *ret = (char *)calloc(len + 1,sizeof(char));//在堆中开辟buffer，作为返回值
	int i, j=0;
	//情况1:zigzag转换为一行，直接copy输出
	if (nRows == 1) 
	{
	    	while (j < len)
		{
	       	 ret[j] = s[j];
	        	j++;
	    	}
		ret[len] = '\0';
		return ret;
	}
	//情况2:zigzag转换为多行
	int t = (nRows - 1) * 2;
	int shift, offset;
	for (i = 0; i < nRows; i++) 
	{
		offset = 0;
		/*shift:为当前数据与下一个同行数据的下标差值,对于不是0(最小)和nRows(最大)的行来说，shift的值是通过shift=t-shift不断变化的;
		t:为最大的相邻数据下标差,如下所示。
			|
			|	/
			|
		i+offset:为当前数据下标，根据当前shift，通过offset+=shift不断增加。
		*/
		shift = (nRows - i - 1) * 2;
		while (j < len && i + offset < len)
		{
			ret[j] = s[i + offset];
			j++;
			 if (shift == 0) 
			{
				shift = t;
			}
			offset += shift;
			if (shift != t) 
			{
				 shift = t - shift;
			}
		}
	}
	ret[len] = '\0';
	return ret;
}

int main(int argc,char ** argv)
{
    char str[] = "PAYPALISHIRING";
    printf("%s\n", convert(str, 3));//PAHNAPLSIIGYIR

    return 0;
}
