«∞∫Û÷∏’Î

void Swap(int* array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int PartionHora(int* nums, int begin, int end) {
    int last = begin;
    int next = last + 1;
    int key = nums[begin];
    while (next <= end) {
        if (nums[next] < key && ++last != next) {
            Swap(nums, last, next);
        }
        next++;
    }
    Swap(nums, begin, last);
    return last;
}


void QuickSort(int* nums, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int keyPos = PartionHora(nums, begin, end);

    QuickSort(nums, begin, keyPos - 1);
    QuickSort(nums, keyPos + 1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    QuickSort(nums, 0, numsSize - 1);
    return nums;
}