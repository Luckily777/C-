//ц╟ещеепР

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    while (numsSize) {
        int flag = 1;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i - 1] > nums[i]) {
                Swap(nums, i, i - 1);
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
        numsSize--;
    }
    return nums;
}


void BubbleSort(int* nums, int n) {
    while (n) {
        int flag = 1;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[i - 1]) {
                Swap(nums, i, i - 1);
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
        n--;
    }

}