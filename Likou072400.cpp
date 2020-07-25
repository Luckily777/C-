//884. 两句话中的不常见单词
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//    vector<string> uncommonFromSentences(string A, string B) {
//        vector<string> v;
//        vector<string> out;
//        string temp = "";
//        for (auto& e : A) {
//            if (e != ' ') {
//                temp.push_back(e);
//            }
//            else {
//                v.push_back(temp);
//                temp = "";
//            }
//        }
//        v.push_back(temp);
//        temp = "";
//        for (auto& f : B) {
//            if (f != ' ') {
//                temp.push_back(f);
//            }
//            else {
//                v.push_back(temp);
//                temp = "";
//            }
//        }
//        v.push_back(temp);
//        for (int i = 0; i < v.size(); i++) {
//            int count = 0;
//            for (int j = 0; j < v.size(); j++) {
//                if (v[i] == v[j]) {
//                    count++;
//                }
//            }
//            if (count == 1) {
//                out.push_back(v[i]);
//            }
//        }
//        return out;
//    }
//};
//
//int main() {
//    Solution s;
//    string A("this apple is sweet");
//    string B("this apple is sour");
//
//    s.uncommonFromSentences(A, B);
//}