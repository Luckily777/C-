#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> result;
    while (n) {
        string str;
        cin >> str;
        vector<string> mp;
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            if ((i + 1) % 3 == 0) {
                tmp += str[i];
                mp.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp += str[i];
            }
        }
        int flag = 0;
        for (int i = 0; i < mp.size(); i++) {
            for (int j = 0; j < mp.size(); j++) {
                flag = 0;
                if (mp[i][0] != mp[j][0]) {
                    flag++;
                }
                if (mp[i][1] != mp[j][1]) {
                    flag++;
                }
                if (mp[i][2] != mp[j][2]) {
                    flag++;
                }
                if (flag > 1) {
                    result.push_back("No");
                    flag = -1;
                    break;
                }
            }
            if (flag == -1) {
                break;
            }
        }
        if (flag != -1) {
            result.push_back("Yes");
        }
        n--;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}