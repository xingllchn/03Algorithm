/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-13
Description	: 
		The string "PAYPALISHIRING" is written in a zigzag pattern
		��	P   A   H   N
			A P L S I I G
			Y   I   R		��
		convert("PAYPALISHIRING", 3) ,return "PAHNAPLSIIGYIR".

		input:	PAYPALISHIRING,3
		output:	PAHNAPLSIIGYIR
			
֪ʶ��	:
			1)Z���������з�ʽ:
				i
				0	|		|		|
				1	|	/	|	\	|
				2	|		|		|
			2)
����˼��	:
			1)zigzag��������Ҫ���ҵ�ÿ��һ�����ݵ��±�ֵ�����δ洢���±�����(+1)��������
			2)����:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int nRows) 
{
	int len = strlen(s);
	char *ret = (char *)calloc(len + 1,sizeof(char));//�ڶ��п���buffer����Ϊ����ֵ
	int i, j=0;
	//���1:zigzagת��Ϊһ�У�ֱ��copy���
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
	//���2:zigzagת��Ϊ����
	int t = (nRows - 1) * 2;
	int shift, offset;
	for (i = 0; i < nRows; i++) 
	{
		offset = 0;
		/*shift:Ϊ��ǰ��������һ��ͬ�����ݵ��±��ֵ,���ڲ���0(��С)��nRows(���)������˵��shift��ֵ��ͨ��shift=t-shift���ϱ仯��;
		t:Ϊ�������������±��,������ʾ��
			|
			|	/
			|
		i+offset:Ϊ��ǰ�����±꣬���ݵ�ǰshift��ͨ��offset+=shift�������ӡ�
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
