#include <stdio.h>

//1. ¡Ω÷÷—°‘Ò≈≈–Ú


void Swap(int* nums, int start, int min) {
    int tmp = nums[start];
    nums[start] = nums[min];
    nums[min] = tmp;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int start = i;
        int min = start;
        for (int j = start + 1; j < numsSize; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        Swap(nums, start, min);
    }
    return nums;
}

void Swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int* sortArray(int* nums, int numsSize) {
    int begin = 0;
    int end = numsSize - 1;
    while (begin < end) {
        int min = begin, max = begin;
        for (int i = begin + 1; i <=end; i++) {
            if (nums[i] >= nums[max]) {
                max = i;
            }
            if (nums[i] < nums[min]) {
                min = i;
            }
        }
        Swap(nums, begin, min);
        if (max == begin) {
            max = min;
        }
        Swap(nums, end, max);
        begin++;
        end--;
    }
    return nums;
}


int main() {
    int nums[] = { 5,2,3,1 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    sortArray(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
    }
    return 0;
}



void SelectSort(int* nums, int n) {
    int begin = 0;
    int end = n - 1;
    while (begin < end) {
        int max = begin, min = begin;
        for (int i = begin+1; i <=end; i++) {
            if (nums[i] >= nums[max]) {
                max = i;
            }
            if (nums[i] < nums[min]) {
                min = i;
            }
        }
        Swap(nums, begin, min);
        if (max == begin) {
            max = min;
        }
        Swap(nums, end, max);
        begin++;
        end--;
    }
}