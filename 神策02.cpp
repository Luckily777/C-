//class Solution {
//public:
//    void swap(string& str, int start, int end) {
//        char temp = str[start];
//        str[start] = str[end];
//        str[end] = temp;
//    }
//    bool IsExist(vector<string>& result, string& str) {
//        for (auto it = result.begin(); it != result.end(); it++) {
//            if (*it == str) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void permutationHelper(string& str, int start, vector<string>& result) {
//        if (start == str.length() - 1) {
//            if (!IsExist(result, str)) {
//                result.push_back(str);
//            }
//            return;
//        }
//
//        for (int i = start; i < str.length(); i++) {
//            swap(str, start, i);
//            permutationHelper(str, start + 1, result);
//            swap(str, start, i);
//        }
//
//    }
//
//    vector<string> permutation(string s) {
//        vector<string> result;
//        if (s.length() > 0) {
//            permutationHelper(s, 0, result);
//            sort(result.begin(), result.end());
//        }
//        return result;
//    }
//};