//矩形覆盖


//1. 动态规划

//2. 斐波那契
class Solution {
public:
    int rectCover(int number) {
        int first = 1;
        int second = 2;
        int third = 0;
        if (number <= 2) {
            return number;
        }
        for (int i = 3; i <= number; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};