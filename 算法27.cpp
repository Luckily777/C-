//把数组排成最小的数

class Solution {
public:
    static bool cmp(int x, int y) {
        string xs = to_string(x);
        string ys = to_string(y);
        string A = xs;
        A += ys;
        string B = ys;
        B += xs;
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.size() == 0) {
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);
        string result = "";
        for (int i = 0; i < numbers.size(); i++) {
            result += to_string(numbers[i]);
        }
        return result;
    }
};