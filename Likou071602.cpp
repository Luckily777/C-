//两个数组的交集

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;

        for (int& e : nums1)
            s1.insert(e);
        for (int& e : nums2)
            s2.insert(e);

        vector<int> ret;
        for (const int& e : s1) {
            if (s2.count(e))
                ret.push_back(e);
        }
        return ret;
    }
};