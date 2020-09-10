//×óÐý×ª×Ö·û´®


//class Solution {
//public:
//    void LeftRotateStringHelper(string& str) {
//        char temp = str[0];
//        int len = str.size();
//        for (int i = 0; i < len - 1; i++) {
//            str[i] = str[i + 1];
//        }
//        str[len - 1] = temp;
//    }
//    string LeftRotateString(string str, int n) {
//        if (str.empty() || n < 0) {
//            return str;
//        }
//        int step = n % str.size();
//        for (int i = 0; i < step; i++) {
//            LeftRotateStringHelper(str);
//        }
//        return str;
//    }
//};
