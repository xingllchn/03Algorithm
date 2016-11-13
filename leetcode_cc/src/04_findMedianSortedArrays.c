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
//�������������kС�������ݹ�ʵ��
int FindKth(int *nums1, int n1, int *nums2, int n2, int k)
 {    
	int pa = Min(n1, k / 2), pb = k - pa;   
	//pa��pb�ֱ�ָ����������ĵ�k/2��Ԫ�أ�����һС��k/2��ʱpaָ�����һ��Ԫ��
	if(n2 < n1) //ȷ����һ��������ڵڶ�������
		return FindKth(nums2, n2, nums1, n1, k);    
	if(n1 == 0) //��׼�������һ������Ϊ��ʱֱ�ӷ��صڶ��������е�k��Ԫ��
		return nums2[k - 1];    
	if(k == 1)//��׼�����k = 1ʱ�޷��ݹ�����һ��׼�����ֱ�ӷ���ͷ���Ľ�С�ڵ�  
		return Min(nums1[0], nums2[0]); 
	  
	if(nums1[pa - 1] < nums2[pb - 1])
	 { //����һ�еĵ�K/2��Ԫ��С��������еĵ�K/2��Ԫ�أ�˵��С������һ�е�k/2��Ԫ�ص�Ԫ�ظ�������k��������kС��Ԫ��һ����������һ�е�ǰk/2��Ԫ�أ��ݹ��������һ���²��ֺ������ 				
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
	if((nums1Size + nums2Size) % 2 == 1)//����Ϊ���������ص�k����kΪ����һ�룩
		return FindKth(nums1, nums1Size, nums2, nums2Size, k + 1);    
	else//����Ϊż�������ص�k����k+1����ƽ����
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