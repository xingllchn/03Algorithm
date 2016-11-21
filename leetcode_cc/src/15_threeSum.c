/*
From			:	https://leetcode.com/problemset/algorithms/
To			:	https://github.com/xingllchn/03algorithm/tree/master/leetcode_cc/src
Data			:	2016-11-17 22:49
author		:	xingllchn
Description	: 
				Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
				For example, given array S = [-1, 0, 1, 2, -1, -4],
					A solution set is:
					[
					  [-1, 0, 1],
					  [-1, -1, 2]
					]
知识点	:
			1)
分析	:
			1)
*/

#include <stdio.h>
#include <stdlib.h>
/*---归并排序非递归方式实现---*/
void mergeSort(int *data,int n)
{
	int *tmp = (int *)calloc(n,sizeof(int));
	int lBegin,lEnd,rBegin,rEnd;
	int i,j,k;	
	int len = 1;
	while (len < n) 
	{		
		lBegin = 0;		
		lEnd = len - 1;		
		rBegin = len;		
		while (rBegin < n) 
		{			
			rEnd = lEnd + len < n - 1 ? lEnd + len : n - 1;
			i = lBegin,j = rBegin,k = lBegin;			
			while (i <= lEnd && j <= rEnd) 
			{				
				if (data[i] <= data[j])					
					tmp[k++] = data[i++];				
				else					
					tmp[k++] = data[j++];			
			}			
			while (i <= lEnd)				
				tmp[k++] = data[i++];			
			while (j <= rEnd)				
				tmp[k++] = data[j++];			
			for (i = lBegin; i <= rEnd; ++i)				
				data[i] = tmp[i];			
			lBegin += 2 * len;			
			lEnd += 2 * len;			
			rBegin += 2 * len;		
		}		
		len *= 2;	
	}	
	free(tmp);
}
/*
 * Return an array of arrays of size *returnSize.
 */
int** threeSum(int* nums,int numsSize,int* returnSize) 
{	
	int i,j,k;
	//最多排numsSize行的3维列数组
	int **ret = (int **)calloc(numsSize,sizeof(int *));
	//每一行申请3个int空间
	for (i = 0; i < numsSize; i++)		
		ret[i] = (int *)calloc(3,sizeof(int));
	*returnSize = 0;
	//输入数据从小到大排序
	mergeSort(nums,numsSize);
	for (i = 0; i < numsSize; i++) 
	{
		//如有重合,直接跳过
		if(i > 0 && nums[i] == nums[i - 1])	        
			continue;
		/*---以i为基值,另两个值分别从第i+1和第numsSize-1个值向中间搜索---*/  
		j = i + 1;
		k = numsSize - 1;	
		while (j < k) 
		{
			//若三个值的和小于0,则j的值增加(即使和也增加),继续搜索找和为0;反之,则k值减小
			if (nums[i] + nums[j] + nums[k] < 0)				
				j++;			
			else if (nums[i] + nums[j] + nums[k] > 0)				
				k--;			
			else 
			{
				//仅不重复时,保存当前值到ret[*returnSize]行,*returnSize值加1
				if (   *returnSize == 0 
					|| ret[*returnSize - 1][0] != nums[i] 
					|| ret[*returnSize - 1][1] != nums[j] 
					|| ret[*returnSize - 1][2] != nums[k]
				   )
				{
					//取出重复解。 因为数组排过序，重复解只可能与上一个解相同，只需要比较上一次所求解				
					ret[*returnSize][0] = nums[i];					
					ret[*returnSize][1] = nums[j];					
					ret[*returnSize][2] = nums[k];					
					(*returnSize)++;				
				}
				//找到和为0，但不满足上述if判断,说明重复,继续找基值i下的其他0
				j++;				
				k--;			
			}		
		}	
	}	
	return ret;
}
int main(int argc,char **argv)
{
	int nums[6] = {-1, 0, 1, 2, -1, -4};
	int **results;
	int returnSize;
	int i=0,j=0;
	results=threeSum(nums,sizeof(nums)/sizeof(int),&returnSize);
	printf("results =\n");
	for(i=0;i<returnSize;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("  %d",results[returnSize-i-1][j]);
		}
		printf("\n");
	}
	printf("returnSize =%d\n",returnSize);
	return 0;
}