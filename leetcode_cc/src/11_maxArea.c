/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-17 22:49
author		:	xingllchn
Description	: 
			Given n non-negative integers a1, a2, ..., an, 
			where each represents a point at coordinate (i, ai). 
			n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
			Find two lines, which together with x-axis forms a container, such that the container contains the most water.
			Note: You may not slant the container.
֪ʶ��	:
			1)
����	:
			1)��������������б����Ҫѡ��������Сֵ������ˮ�������
			2)��X���ϸ���һЩ���ߣ������г��ȣ�������������X�ṹ�ɵ�һ����������������ˮ�����������������б��
*/
#include<stdio.h>

int maxArea(int* height, int heightSize)
{  
	int Max=-1;//������
	int area=0;//����֮������
	int k=0;//��׼����
	int l=0;//��С����
	int r=heightSize-1;//�������
	int minHeight=0;//����֮�����Сֵ
	while(l<r)
	{
		//�ҳ�����֮����С��ֵ
		minHeight=height[l]<height[r]?height[l]:height[r];
		//ʹ��������Сֵ������ˮ�������
		area=minHeight*(r-l);
		//ѭ���ҳ�������
		Max=Max<area?area:Max; 
		//����ұߵ�ֵ�ϴ�,��ʹ���±������������
		if(height[l]<height[r])
		{  
			k=l;  
			while(l<r && height[l]<=height[k])
				l++;  
		}//�����ߵ�ֵ�ϴ�,��ʹ���±���м�С����
		else
		{  
			k=r;  
			while(l<r && height[r]<=height[k])
				r--;  
		}  
	}  
	return Max;  
} 
int main(int argc,char ** argv)
{
	int area=0;
	int height1[5]={5,2,3,4,5};//4//4*5,output 20
	int height2[5]={2,5,3,4,5};//4//3*5,output 15
	area = maxArea(height1,sizeof(height1)/sizeof(int));
	printf("max area = %d\n",area);
	
	area = maxArea(height2,sizeof(height2)/sizeof(int));
	printf("max area = %d\n",area);
	return 0;
}