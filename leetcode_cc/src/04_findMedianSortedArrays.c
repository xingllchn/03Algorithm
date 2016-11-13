/*Description: 
			Example 1:
			nums1 = [1, 3]
			nums2 = [2]

			The median is 2.0
			Example 2:
			nums1 = [1, 2]
			nums2 = [3, 4]
			The median is (2 + 3)/2 = 2.5
*/
#include <stdio.h>
#include <stdlib.h>
int Min(int a, int b) 
{    
	return a < b ? a : b;
}
//返回两个数组第k小的数，递归实现
int FindKth(int *nums1, int n1, int *nums2, int n2, int k)
 {    
	int pa = Min(n1, k / 2), pb = k - pa;   
	//pa，pb分别指向两个数组的第k/2个元素，数组一小于k/2个时pa指向最后一个元素
	if(n2 < n1) //确保第一个数组短于第二个数组
		return FindKth(nums2, n2, nums1, n1, k);    
	if(n1 == 0) //基准情况，第一个数组为空时直接返回第二个数组中第k个元素
		return nums2[k - 1];    
	if(k == 1)//基准情况，k = 1时无法递归至上一基准情况；直接返回头结点的较小节点  
		return Min(nums1[0], nums2[0]); 
	  
	if(nums1[pa - 1] < nums2[pb - 1])
	 { //数组一中的第K/2个元素小于数组二中的第K/2个元素，说明小于数组一中第k/2个元素的元素个数少于k个，即第k小的元素一定不在数组一中的前k/2个元素；递归查找数组一余下部分和数组二 				
		return FindKth(nums1 + pa, n1 - pa, nums2, n2, k - pa);   
	 }    
	else if(nums1[pa - 1] > nums2[pb - 1]) 
	{
		return FindKth(nums1, n1, nums2 + pb, n2 - pb, k - pb);    
	}   
	 else 
	{
		return nums1[pa - 1];    
	}
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{    
	int k = (nums1Size + nums2Size) / 2;    
	if((nums1Size + nums2Size) % 2 == 1)//总数为奇数，返回第k个（k为总数一半）
		return FindKth(nums1, nums1Size, nums2, nums2Size, k + 1);    
	else//总数为偶数，返回第k、第k+1个的平均数
		return (FindKth(nums1, nums1Size, nums2, nums2Size, k) + FindKth(nums1, nums1Size, nums2, nums2Size, k + 1)) / 2.0;
}
int main(int argc,char ** argv)
{
	int nums1[2]={1,5};
	int nums2[2]={6,8};
	double median=0.0;
	median=findMedianSortedArrays(nums1,sizeof(nums1)/sizeof(int),nums2,sizeof(nums2)/sizeof(int));
	printf(" median=%f\n",median);
	return 0;
}