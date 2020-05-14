// ∂—≈≈–Ú

void Swap(int* nums, int start, int min) {
    int tmp = nums[start];
    nums[start] = nums[min];
    nums[min] = tmp;
}

void ShiftDown(int* nums, int n, int parent) {
    int child = parent * 2 + 1;
    while (child < n) {
        if (child + 1 < n && nums[child + 1] > nums[child]) {
            child++;
        }
        if (nums[child] > nums[parent]) {
            Swap(nums, child, parent);
            parent = child;
            child = 2 * parent + 1;
        }
        else {
            break;
        }
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = (numsSize - 2) / 2; i >= 0; i--) {
        ShiftDown(nums, numsSize, i);
    }
    while (numsSize) {
        Swap(nums, 0, numsSize - 1);
        numsSize--;
        ShiftDown(nums, numsSize, 0);
    }
    return nums;
}



void ShiftDown(int* nums, int n, int parent) {
    int child = 2 * parent + 1;
    while (child < n) {
        if (child + 1 < n && nums[child] < nums[child + 1]) {
            child++;
        }
        if (nums[child] > nums[parent]) {
            Swap(nums, child, parent);
            parent = child;
            child = 2 * parent + 1;
        }
        else {
            break;
        }
    }
}

void HeadSort(int* nums, int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        ShiftDown(nums, n, i);
    }
    while (n) {
        Swap(nums, 0, n - 1);
        n--;
        ShiftDown(nums, n, 0);

    }
}

