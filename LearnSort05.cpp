//¼ÆÊıÅÅĞò

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int max = nums[0], min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    int leng = max - min + 1;
    int* count = (int*)malloc(sizeof(int) * leng);
    memset(count, 0, sizeof(int) * leng);
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] - min]++;
    }
    int idx = 0;
    for (int i = 0; i < leng; i++) {
        while (count[i]--) {
            nums[idx++] = i + min;
        }
    }
    free(count);
    return nums;
}


void CountSort(int* nums, int n) {
    int max = nums[0], min = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    int range = max - min + 1;
    int* countarray = (int*)malloc(sizeof(int) * range);
    memset(countarray, 0, sizeof(int) * range);
    for (int i = 0; i < range; i++) {
        countarray[nums[i] - min]++;
    }
    int idx = 0;
    for(int i =0;i<range;i++){
        while (countarray[i]--) {
            nums[idx++] = i + min;
        }
    }
    free(countarray);
}