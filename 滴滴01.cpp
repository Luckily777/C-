#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    if (n == 1 || str.size() == 0 || str.size() == 1) {//若截取单位为1，或者输入字符串长度等于1或0，则直接返回源字符串
        cout << str << endl;
        return 0;
    }
    if (n >= str.size()) {//如果截取得长度大于字符串长度，则证明整体为一个字符串，直接逆置输出即可
        reverse(str.begin(), str.end());
        cout << str << endl;
        return 0;
    }
    vector<string> result;//创建中间遍历空间，将每一个截取出来的字符串，逆序后存放进去
    int size = str.size();
    int start = 0;
    int end = n;
    while (size >= n) {
        string s = str.substr(start, end);
        str.erase(start, end);
        reverse(s.begin(), s.end());
        result.push_back(s);
        s.clear();
        size -= n;
    }
    if (size != 0) {
        string s;
        s = str.substr(start, str.size());
        reverse(s.begin(), s.end());
        result.push_back(s);
    }
    str.clear();
    for (int i = 0; i < result.size(); i++) {
        str += result[i];
    }
    cout << str << endl;
    return 0;
}

