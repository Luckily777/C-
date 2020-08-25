//斐波那契数列

//1.迭代累加
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) {
            return n;
        }
        int first = 1;
        int second = 1;
        int third = 1;
        while (n > 2) {
            third = first + second;
            first = second;
            second = third;
            n--;
        }
        return third;
    }
};


//2. 剪枝

class Solution {
private:
    unordered_map<int, int> filter;
public:
    int Fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        int ppre = 0;
        if (filter.find(n - 2) == filter.end()) {
            ppre = Fibonacci(n - 2);
            filter.insert({ n - 2,ppre });
        }
        else {
            ppre = filter[n - 2];
        }
        int pre = 0;
        if (filter.find(n - 1) == filter.end()) {
            pre = Fibonacci(n - 1);
            filter.insert({ n - 1,pre });
        }
        else {
            pre = filter[n - 1];
        }
        return pre + ppre;
    }
};