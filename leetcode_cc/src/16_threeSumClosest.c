/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-19 22:44
author		:	xingllchn
Description	: 
			For example, given array S = {-1 2 1 -4}, and target = 1.
			The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
知识点	:
			
分析	:
			1)对数据进行排序
			2)找到和与目标值相差最小的三个值
*/
#include <stdio.h>
#include <stdint.h>
/*---取绝对值---*/
static inline int abs(int tar)
{  
	return tar>0?tar:-tar;  
} 
/*---快速排序---*/
void quickSort(int* nums,int start,int end)
{  
	int l=start,r=end;  
	if(start>=end)
		return;  
	int temp=nums[l];  
	while(l<r)
	{  
		while(l<r && nums[r]>=temp)
			r--;  
		if(l<r)
			nums[l]=nums[r];  
		while(l<r && nums[l]<=temp)
			l++;  
		if(l<r)
			nums[r]=nums[l];  
	}  
	nums[l]=temp;  
	quickSort(nums,start,l-1);  
	quickSort(nums,l+1,end);  
}  
int threeSumClosest(int* nums, int numsSize, int target) 
{  
	int i,j,k;
	int sum=0,Min =INT32_MAX;
	quickSort(nums,0,numsSize-1);
	for(i=0;i<numsSize-2;i++)
	{  
		if(i>0 && nums[i]==nums[i-1])
			continue;  
		j=i+1;
		k=numsSize-1;  
		while(j<k)
		{  
		    sum=nums[i]+nums[j]+nums[k];  
		    if(abs(sum-target)<abs(Min))
				Min=sum-target;  
		    if(sum==target)
				return target;  
		    else if(sum>target)
				k--;  
		    else
				j++;  
		}  
	}  
	return Min+target;  
} 
int main(int argc,char **argv)
{
	int nums[4] = {-1,2,1,-4};
	int target=1;
	int results;
	results=threeSumClosest(nums,sizeof(nums)/sizeof(int),target);
	printf("results =%d\n",results);

	return 0;
}