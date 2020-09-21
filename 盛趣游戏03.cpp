#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    int begin1 = 0, begin2 = 0;
    while (begin1 < str1.size() && begin2 < str2.size()) {
        if ((str1[begin1] == str2[begin2])) {
            if (str2[begin2 + 1] == '*') {
                int tmp = begin1;
                while (str1[begin1] == str1[tmp]) {
                    begin1++;
                }
                begin2 += 2;
            }
            else {
                begin1++;
                begin2++;
            }
        }
        else if (str2[begin2] == '.') {
            break;
        }
        else {
            begin2 += 2;
        }
    }
    cout << "true" << endl;
    return 0;
}