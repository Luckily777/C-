//把字符串转换成整数

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        long long ret = 0;
        int flag = 1;
        if (str.empty()) {
            return 0;
        }
        if (str[0] == '-') {
            flag = -1;
            str.erase(0, 1);
        }
        if (str[0] == '+') {
            str.erase(0, 1);
        }
        int size = str.size();
        for (int i = 0; i < size; i++) {
            if ((str[i] <= '9') && (str[i] >= '0')) {
                ret = (ret * 10) + (str[i] - '0');
            }
            else {
                ret = 0;
                break;
            }
        }
        ret = ret * flag;
        return ret;
    }
};

int main() {
    Solution s;
    string str("123");
    s.StrToInt(str);
}