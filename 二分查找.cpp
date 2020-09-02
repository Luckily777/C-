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
        if (n == 0 || a.size() == 0) {
            return n + 1;
        }
        int start = 0;
        int end = n - 1;
        int mid = 0;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (a[mid] == v) {
                return mid;
            }
            else if (a[mid] > v) {
                end = mid - 1;
            }
            else if (a[mid] < v) {
                start = mid + 1;
            }
        }
        return n + 1;
    }
};