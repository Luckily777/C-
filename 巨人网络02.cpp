#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * �ҳ��ַ�������󹫹����ַ���
     * @param str1 string�ַ��� �����ַ���1
     * @param str2 string�ַ��� �����ַ���2
     * @return string�ַ���
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