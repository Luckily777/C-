//调整数组顺序使奇数位于偶数前面


class Solution {
public:
    void reOrderArray(vector<int>& array) {
        if (array.size() == 0) {
            return;
        }
        int k = 0;
        for (int i = 0; i < array.size(); i++) {
            if ((array[i] & 1) == 1) {
                int temp = array[i];
                int j = i;
                while (j >= k) {
                    array[j] = array[j - 1];
                    j--;
                }
                array[k++] = temp;
            }
        }
    }
};