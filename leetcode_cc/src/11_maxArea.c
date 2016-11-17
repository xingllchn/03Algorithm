/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-17 22:49
Description	: 
			Given n non-negative integers a1, a2, ..., an, 
			where each represents a point at coordinate (i, ai). 
			n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
			Find two lines, which together with x-axis forms a container, such that the container contains the most water.
			Note: You may not slant the container.
			在X轴上给定一些竖线，竖线有长度，求两条竖线与X轴构成的一个容器能容纳最多的水的面积.
知识点	:
			1)
核心思想	:
			1)
*/
#include<stdio.h>

int maxArea(int* height, int heightSize)
{  
	int Max=-1,area,l=0,k;
	int r=heightSize-1;
	while(l<r)
	{  
		area=(height[l]<height[r]?height[l]:height[r])*(r-l);  
		Max=Max<area?area:Max;  
		if(height[l]<height[r])
		{  
			k=l;  
			while(l<r && height[l]<=height[k])
				l++;  
		}
		else
		{  
			k=r;  
			while(l<r && height[r]<=height[k])
				r--;  
		}  
	}  
	printf("max = %d\n",Max);
	return Max;  
} 
int main(int argc,char ** argv)
{
	int height[5]={5,2,3,4,5};//4//4*5,output 20
	int area=0;
	area = maxArea(height,sizeof(height)/sizeof(int));
	printf("max area = %d\n",area);
	return 0;
}