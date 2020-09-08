#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    vector<int> v;
    v.resize(4, 0);//用来存放四个类型的字符，若存在则将其改为1
    while (cin >> str) {
        if (str.size() >= 8 && str.size() <= 120) {
            for (int i = 0; i < str.size(); i++) {
                if (str[i] >= '0' && str[i] <= '9') {//数字
                    v[0] = 1;
                }
                else if (str[i] >= 'A' && str[i] <= 'Z') {
                    //daxie
                    v[1] = 1;
                }
                else if (str[i] >= 'a' && str[i] <= 'z') {
                    //xiaoxie
                    v[2] = 1;
                }
                else if (str[i] == ' ') {
                }
                else {
                    v[3] = 1;
                }
            }
            int sum = 0;
            for (int i = 0; i < v.size(); i++) {
                sum += v[i];
            }
            if (sum == 4) {
                cout << 0 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
        else {
            cout << 1 << endl;
        }
    }
    return 0;
}