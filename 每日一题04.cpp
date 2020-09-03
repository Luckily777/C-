//倒置字符串

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    reverse(str.begin(), str.end());//先行将整个字符串全部倒置
    auto start = str.begin();
    while (start != str.end()) {
        auto end = start;
        while (end != str.end() && *end != ' ') {
            end++;//之后找到每一个单词，将其进行倒置
        }
        reverse(start, end);
        if (end != str.end()) {
            start = end + 1;
        }
        else {
            start = end;
        }
    }
    cout << str << endl;
    return 0;
}