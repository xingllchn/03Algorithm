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
知识点	:
			1)
分析	:
			1)考虑容器不能倾斜，需要选择两者最小值来计算水容器面积
			2)在X轴上给定一些竖线，竖线有长度，求两条竖线与X轴构成的一个容器能容纳最多的水的面积，容器不能切斜。
*/
#include<stdio.h>

int maxArea(int* height, int heightSize)
{  
	int Max=-1;//最大面积
	int area=0;//两者之间的面积
	int k=0;//基准坐标
	int l=0;//最小坐标
	int r=heightSize-1;//最大坐标
	int minHeight=0;//两者之间的最小值
	while(l<r)
	{
		//找出两者之间最小的值
		minHeight=height[l]<height[r]?height[l]:height[r];
		//使用两者最小值来计算水容器面积
		area=minHeight*(r-l);
		//循环找出最大面积
		Max=Max<area?area:Max; 
		//如果右边的值较大,则使左下标进行增加搜索
		if(height[l]<height[r])
		{  
			k=l;  
			while(l<r && height[l]<=height[k])
				l++;  
		}//如果左边的值较大,则使右下标进行减小搜索
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