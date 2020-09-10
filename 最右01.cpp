#include <iostream>
#include <string>
using namespace std;

int main() {
    int nums[36] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    string str;
    cin >> str;
    if (str.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int flag = 0;//¸ºÊý
    if (str[0] == '-') {
        flag = 1;
    }
    long long result = 9223372036854775807;
    string strp = "1y2p0ij32e8e7";
    if (str.size() - flag >= strp.size()) {
        for (int i = flag; i < str.size(); i++) {
            if (str[i] > strp[i - flag]) {
                cout << result << endl;
                return 0;
            }
        }
    }
    else {
        result = 0;
        int C=1;
        for (int i = str.size() - 1; i >= flag; i--) {
            if (str[i] >= '0' && str[i] <= '9') {
                result += (nums[str[i] - '0']) * C;
                C *= 36;
            }
            else if (str[i] >= 'a' && str[i] <= 'z') {
                result += (nums[str[i] - 87]) * C;
                C *= 36;
            }
            else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (flag == 1) {
        cout << '-';
    }
    cout << result << endl;
    return 0;
}