189. 旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

void rotate(int* nums, int numsSize, int k) {
    int* Num = (int*)malloc(sizeof(int) * numsSize);
    int n = 0;
    for (int i = abs(numsSize - (k % numsSize)); i < numsSize; i++) {
        Num[n++] = nums[i];
    }
    for (int i = 0; i < abs(numsSize - (k % numsSize)); i++) {
        Num[n++] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = Num[i];
    }
    free(Num);
}