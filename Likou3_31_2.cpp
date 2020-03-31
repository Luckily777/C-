#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//力扣 旋转数组

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

void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);

}

