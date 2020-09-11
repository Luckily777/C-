#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    string result = "Irregular password";
    while (cin >> str) {
        int flag[4] = { 0 };
        if (str.size() >= 8) {
            for (int i = 0; i < str.size(); i++) {
                if (str[i] >= '0' && str[i] <= '9') {
                    flag[0] = 1;
                }
                else if (str[i] >= 'a' && str[i] <= 'z') {
                    flag[1] = 1;
                }
                else if (str[i] >= 'A' && str[i] <= 'Z') {
                    flag[2] = 1;
                }
                else {
                    flag[3] = 1;
                }
            }
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += flag[i];
            }
            if (sum == 4) {
                cout << "Ok" << endl;
            }
            else {
                cout << result << endl;
            }
        }
        else {
            cout << result << endl;
        }
    }
    return 0;

}