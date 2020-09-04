//字符串中找出最长数字串


#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, ret, cur;
    while (getline(cin, str)) {
        for (int i = 0; i <= str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {//先找数字
                cur += str[i];
            }
            else {//若出现非数字则比较之前存储和当前数字串的长度
                if (ret.size() < cur.size()) {
                    ret = cur;
                }
                else {
                    cur.clear();
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}