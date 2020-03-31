#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//���� ������Ӻ�

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
	//��ȡ���λ��
	int tmp = K;
	int knum = 0;
	while (tmp)
	{
		knum++;
		tmp /= 10;
	}
	//���ռ䣬�������λ�Ľ�λ
	int newArraySize = ASize > knum ? ASize + 1 : knum + 1;
	int* newArray = (int*)malloc(sizeof(int) * newArraySize);
	//ģ��ӷ����㣬�ӵ�λ��ʼ���
	int i = 0;
	int idx = ASize - 1;
	int step = 0;
	while (idx >= 0 || K > 0)
	{
		//��ǰλ�ļӷ�
		newArray[i] = step;
		if (idx >= 0)
			newArray[i] += A[idx];
		if (K > 0)
			newArray[i] += K % 10;
		//���½�λ
		if (newArray[i] > 9)
		{
			newArray[i] -= 10;
			step = 1;
		}
		else
			step = 0;
		//������һλ�ļӷ�����
		--idx;
		K /= 10;
		++i;
	}
	//�ж����λ�Ƿ��н�λ
	if (step == 1)
		newArray[i++] = 1;
	//��ת
	reverse(newArray, 0, i - 1);
	*returnSize = i;
	return newArray;
}