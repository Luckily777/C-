//两种排序方法

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lexicographically(vector<string> v, int n) {
    for (int i = 1; i < n; i++) {
        string str1(v[i - 1]);
        string str2(v[i]);
        if ((str1.compare(str2)) > 0) {
            return false;
        }
    }
    return true;
}

int lengths(vector<string> v, int n) {
    for (int i = 1; i < n; i++) {
        string str1(v[i - 1]);
        string str2(v[i]);
        if (str1.size() > str2.size()) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    int flag = 0;
    if (lexicographically(v, n)) {
        if (lengths(v, n)) {
            cout << "both" << endl;
            flag = 1;

        }
        else {
            cout << "lexicographically" << endl;
            flag = 1;
        }
    }
    if (flag != 1) {
        if (lengths(v, n)) {
            cout << "lengths" << endl;
        }
        else {
            cout << "none" << endl;
        }
    }
    return 0;
}