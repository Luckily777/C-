//
//class Solution {
//public:
//    /**
//     *
//     * @param nums int����һά����
//     * @param numsLen int nums���鳤��
//     * @return int����
//     */
//    int firstMissingPositive(int* nums, int numsLen) {
//        // write code here
//        if (nums == nullptr || numsLen == 0) {
//            return 0;
//        }
//        vector<int> v;
//        v.resize(numsLen);
//        for (int i = 0; i < numsLen; i++) {
//            v[i] = nums[i];
//        }
//        sort(v.begin(), v.end());
//        int result = 0;
//        for (int i = 0; i < v.size() - 1; i++) {
//            if (v[i] > 0) {
//                if ((v[i] + 1) != (v[i + 1])) {
//                    result = v[i] + 1;
//                    return result;
//                }
//            }
//        }
//        if (v[v.size() - 1] <= 0 || v[0] > 1) {
//            result = 1;
//        }
//        else {
//            result = v[v.size() - 1] + 1;
//        }
//        return result;
//    }
//};