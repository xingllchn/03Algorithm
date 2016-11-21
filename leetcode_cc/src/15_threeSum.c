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
֪ʶ��	:
			1)
����	:
			1)
*/

#include <stdio.h>
#include <stdlib.h>
/*---�鲢����ǵݹ鷽ʽʵ��---*/
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
	//�����numsSize�е�3ά������
	int **ret = (int **)calloc(numsSize,sizeof(int *));
	//ÿһ������3��int�ռ�
	for (i = 0; i < numsSize; i++)		
		ret[i] = (int *)calloc(3,sizeof(int));
	*returnSize = 0;
	//�������ݴ�С��������
	mergeSort(nums,numsSize);
	for (i = 0; i < numsSize; i++) 
	{
		//�����غ�,ֱ������
		if(i > 0 && nums[i] == nums[i - 1])	        
			continue;
		/*---��iΪ��ֵ,������ֵ�ֱ�ӵ�i+1�͵�numsSize-1��ֵ���м�����---*/  
		j = i + 1;
		k = numsSize - 1;	
		while (j < k) 
		{
			//������ֵ�ĺ�С��0,��j��ֵ����(��ʹ��Ҳ����),���������Һ�Ϊ0;��֮,��kֵ��С
			if (nums[i] + nums[j] + nums[k] < 0)				
				j++;			
			else if (nums[i] + nums[j] + nums[k] > 0)				
				k--;			
			else 
			{
				//�����ظ�ʱ,���浱ǰֵ��ret[*returnSize]��,*returnSizeֵ��1
				if (   *returnSize == 0 
					|| ret[*returnSize - 1][0] != nums[i] 
					|| ret[*returnSize - 1][1] != nums[j] 
					|| ret[*returnSize - 1][2] != nums[k]
				   )
				{
					//ȡ���ظ��⡣ ��Ϊ�����Ź����ظ���ֻ��������һ������ͬ��ֻ��Ҫ�Ƚ���һ�������				
					ret[*returnSize][0] = nums[i];					
					ret[*returnSize][1] = nums[j];					
					ret[*returnSize][2] = nums[k];					
					(*returnSize)++;				
				}
				//�ҵ���Ϊ0��������������if�ж�,˵���ظ�,�����һ�ֵi�µ�����0
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