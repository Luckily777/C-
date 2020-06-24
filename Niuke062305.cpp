//箔1+2+3+。。。。。+n

class Solution {
public:
    int Sum_Solution(int n) {
        bool x = n > 1 && (n += Sum_Solution(n - 1));
        return n;
    }
};