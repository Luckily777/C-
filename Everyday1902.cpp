//查找两个字符串中的最长公共子串


#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    while (cin >> str1 >> str2) {
        string str = "";
        if (str1.size() > str2.size()) {
            str1.swap(str2);
        }
        for (int i = 0; i < str1.size(); i++) {
            for (int j = i; j < str1.size(); j++) {
                string temp = str1.substr(i, j - i + 1);
                if (int(str2.find(temp)) < 0) {
                    break;
                }
                else if (temp.size() > str.size()) {
                        str = temp;
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}