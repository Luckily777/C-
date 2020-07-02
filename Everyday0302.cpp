//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int nums[10] = { 0 };
        int size = numbers.size();
        for (int i = 0; i < size; i++) {
            nums[numbers[i]]++;
        }
        for (int i = 1; i < 10;i++) {
            if (nums[i] > (size / 2)) {
                return i;
            }
        }
        return 0;
    }
};


int main() {
    vector<int> numbers{ 1,2,3,2,2,2,5,4,2 };
    Solution nums;
    nums.MoreThanHalfNum_Solution(numbers);
}