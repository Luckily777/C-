//二分查找

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (a[mid] >= v) {
                if (mid == 0 || a[mid - 1] < v) {
                    return mid + 1;//返回的是数组下标+1
                }
                else {
                    end = mid;
                }
            }
            else {
                start = mid + 1;
            }
        }
        return n + 1;
    }
};
int main() {
    Solution s;
    vector<int> v({ 1,2,2,3,7,7,7,9,9,10 });
    s.upper_bound_(10, 2, v);
}