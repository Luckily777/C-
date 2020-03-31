#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//力扣：合并有序数组


//使用申请空间
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	/*
	int* newA = (int*) malloc(sizeof(int) * (m + n));
	int idx = 0;
	int n1 = 0;
	int n2 = 0;
	//合并
	while(n1 < m && n2 < n)
	{
	if(nums1[n1] <= nums2[n2])
	newA[idx++] = nums1[n1++];
	else
	newA[idx++] = nums2[n2++];
	}
	//可能还有没有访问的元素，剩余元素的直接拼接
	if(n1 < m)
	memcpy(newA + idx, nums1 + n1, sizeof(int) * (m - n1));
	if(n2 < n)
	memcpy(newA + idx, nums2 + n2, sizeof(int) * (n - n2));

	memcpy(nums1, newA, sizeof(int) * (m + n));
	free(newA);
	*/


//使用本地数组进行
	//从后向前合并
	int idx = m + n - 1;
	while (m > 0 && n > 0)
	{
		if (nums1[m - 1] >= nums2[n - 1])
		{
			nums1[idx--] = nums1[m - 1];
			--m;
		}
		else
		{
			nums1[idx--] = nums2[n - 1];
			--n;
		}
	}
	if (n > 0)
		memcpy(nums1, nums2, sizeof(int) * n);
}
