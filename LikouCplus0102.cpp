189. ��ת����
����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����

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