//350. 两个数组的交集 II


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s;
        for (int i = 0; i < nums1.size(); i++) {
            int falg = 0;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    if (falg == 0) {
                        s.push_back(nums1[i]);
                        falg = 1;
                        nums2[j] = -1;
                    }
                }
            }
        }
        return s;
    }
};