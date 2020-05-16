hora·¨

void Swap(int* array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int PartionHora(int* nums, int begin, int end) {
    int key = nums[begin];
    int start = begin;
    while (begin < end) {
        while (begin < end && nums[end] >= key) {
            end--;
        }
        while (begin < end && nums[begin] <= key) {
            begin++;
        }
        Swap(nums, begin, end);
    }
    Swap(nums, start, begin);
    return begin;
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