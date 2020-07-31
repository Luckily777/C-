//奇数位上是奇数，偶数位上是偶数

class Solution {
public:
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i = 0, j = 1;
        while (i < len && j < len)
        {
            if (arr[len - 1] % 2 == 0)
            {
                swap(arr[len - 1], arr[i]);
                i += 2;
            }
            else
            {
                swap(arr[len - 1], arr[j]);
                j += 2;
            }
        }
    }
};