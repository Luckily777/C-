//二进制计算


//1. n与n-1循环与运算

class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n - 1);
        }
        return count;
    }
};