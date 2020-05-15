//¹é²¢ÅÅĞò



void Merge(int* nums, int begin, int mid, int end, int* tmp) {
    int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
    int idx = begin;

    while (begin1 <= end1 && begin2 <= end2) {
        if (nums[begin1] <= nums[begin2]) {
            tmp[idx++] = nums[begin1++];
        }
        else {
            tmp[idx++] = nums[begin2++];
        }
    }
    if (begin1 <= end1) {
        memcpy(tmp + idx, nums + begin1, sizeof(int) * (end1 - begin1 + 1));
    }
    if (begin2 <= end2) {
        memcpy(tmp + idx, nums + begin2, sizeof(int) * (end2 - begin2 + 1));
    }
    memcpy(nums + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void SortMergeR(int* nums, int begin, int end, int* tmp) {
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;

    SortMergeR(nums, begin, mid, tmp);
    SortMergeR(nums, mid + 1, end, tmp);

    Merge(nums, begin, mid, end, tmp);
}


void Merge(int* nums, int begin, int mid, int end, int* tmp) {
    int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
    int idx = begin;

    while (begin1 <= end1 && begin2 <= end2) {
        if (nums[begin1] <= nums[begin2]) {
            tmp[idx++] = nums[begin1++];
        }
        else {
            tmp[idx++] = nums[begin2++];
        }
    }
    if (begin1 <= end1) {
        memcpy(tmp + idx, nums + begin1, sizeof(int) * (end1 - begin1 + 1));
    }
    if (begin2 <= end2) {
        memcpy(tmp + idx, nums + begin2, sizeof(int) * (end2 - begin2 + 1));
    }
    memcpy(nums + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* tmp = (int*)malloc(sizeof(int) * numsSize);
    int k = 1;
    while (k < numsSize) {
        for (int i = 0; i < numsSize; i += 2 * k) {
            int begin = i;
            int mid = i + k - 1;
            if (mid >= numsSize - 1) {
                continue;
            }
            int end = i + 2 * k - 1;
            if (end >= numsSize) {
                end = numsSize - 1;
            }
            Merge(nums, begin, mid, end, tmp);
        }
        k *= 2;
    }
    free(tmp);
    return nums;
}


int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* tmp = (int*)malloc(sizeof(int) * numsSize);
    SortMergeR(nums, 0, numsSize - 1, tmp);
    free(tmp);
    return nums;
}