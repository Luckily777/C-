#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    int start1 = 0;
    int start2 = 0;
    while (start1 < str1.size() && start2 < str2.size()) {
        if (str1[start1] != str2[start2]) {
            if (str2[start2] == '.') {
                start2++;
                start1++;
            }
            else if (str2[start2] == '*' && start2 < str2.size() - 1) {
                while (str1[start1] != str2[start2 + 1]) {
                    start1++;
                }
                start2++;
            }
            else if (str2[start2] == '+') {
                while (str1[start1] != str2[start2 + 1]) {
                    start1++;
                }
            }
            else {
                break;
            }
        }
        else {
            start2++;
            start1++;
        }
    }
    if (start1 != str1.size() || start2 != str2.size()) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }
    return 0;
}