//青蛙跳台阶

//动态规划
class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) {
            return 1;
        }
        if (number <= 2) {
            return number;
        }
        int* dp = new int[number + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};


//2. 斐波那契

class Solution {
public:
    int jumpFloor(int number) {
        int first = 1;
        int second = 1;
        int third = 1;
        for (int i = 2; i <= number; i++) {
            third = second + first;
            first = second;
            second = third;
        }
        return third;
    }
};