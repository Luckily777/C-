//重复n次的元素

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> m;
        for (int& e : A) {
            ++m[e];
        }
        int n = A.size() / 2;
        for (auto& p : m) {
            if (p.second == n) {
                return p.first;
            }
        }
        return 0;
    }
};