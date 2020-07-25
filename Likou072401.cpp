//217. ´æÔÚÖØ¸´ÔªËØ
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int size;
        for (auto& e : nums) {
            size = s.size();
            s.insert(e);
            if (size == s.size()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{ 1,2,3,1 };
    s.containsDuplicate(nums);
}