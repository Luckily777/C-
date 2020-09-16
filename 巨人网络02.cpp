#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * ÕÒ³ö×Ö·û´®ÖÐ×î´ó¹«¹²×Ó×Ö·û´®
     * @param str1 string×Ö·û´® ÊäÈë×Ö·û´®1
     * @param str2 string×Ö·û´® ÊäÈë×Ö·û´®2
     * @return string×Ö·û´®
     */
    string GetCommon(string str1, string str2) {
        if (str1.size() == 0 || str2.size() == 0) {
            return nullptr;
        }
        string result;
        for (unsigned long i = 0; i < str1.size(); i++) {
            for (unsigned long j = 0; j < str1.size(); j++) {
                string fstr = str1.substr(i, j);
                if (str2.find(fstr) != -1 && fstr.size() > result.size()) {
                    result.clear();
                    result = fstr;
                }
                fstr.clear();
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string str1 = "abccade";
    string str2 = "dgcadde";
    s.GetCommon(str1, str2);
}