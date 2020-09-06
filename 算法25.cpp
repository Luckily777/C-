//最大连续子序列的和
//
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0) {
            return 0;
        }
        int* dp = new int[array.size()];
        dp[0] = array[0];
        int max_value = dp[0];
        for (int i = 1; i < array.size(); i++) {
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            if (max_value < dp[i]) {
                max_value = dp[i];
            }
        }
        delete[] dp;
        return max_value;
    }
};



class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0) {
            return 0;
        }
        int total = array[0];
        int max_value = array[0];
        for (int i = 1; i < array.size(); i++) {
            if (total > 0) {
                total += array[i];
            }
            else {
                total = array[i];
            }
            if (max_value < total) {
                max_value = total;
            }
        }
        return max_value;
    }
};