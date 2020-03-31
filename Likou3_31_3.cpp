#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//力扣 数组相加和

void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	//获取最大位数
	int tmp = K;
	int knum = 0;
	while (tmp)
	{
		knum++;
		tmp /= 10;
	}
	//开空间，考虑最高位的进位
	int newArraySize = ASize > knum ? ASize + 1 : knum + 1;
	int* newArray = (int*)malloc(sizeof(int) * newArraySize);
	//模拟加法运算，从低位开始相加
	int i = 0;
	int idx = ASize - 1;
	int step = 0;
	while (idx >= 0 || K > 0)
	{
		//当前位的加法
		newArray[i] = step;
		if (idx >= 0)
			newArray[i] += A[idx];
		if (K > 0)
			newArray[i] += K % 10;
		//更新进位
		if (newArray[i] > 9)
		{
			newArray[i] -= 10;
			step = 1;
		}
		else
			step = 0;
		//继续下一位的加法运算
		--idx;
		K /= 10;
		++i;
	}
	//判断最高位是否有进位
	if (step == 1)
		newArray[i++] = 1;
	//逆转
	reverse(newArray, 0, i - 1);
	*returnSize = i;
	return newArray;
}