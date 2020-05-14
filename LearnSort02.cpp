//1.Ö±½Ó²åÈëÅÅĞò

int* sortArray(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        int end = i;
        int key = nums[end + 1];
        while (end >= 0 && nums[end] > key) {
            nums[end + 1] = nums[end];
            end--;
        }
        nums[end + 1] = key;
    }
    return nums;
}


//2.Ï£¶ûÅÅĞò
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int gap = numsSize;
    while (gap > 1) {
        gap = gap / 3 + 1;
        for (int i = 0; i < numsSize - gap; i++) {
            int end = i;
            int key = nums[end + gap];
            while (end >= 0 && nums[end] > key) {
                nums[end + gap] = nums[end];
                end -= gap;
            }
            nums[end + gap] = key;
        }
    }
    return nums;
}