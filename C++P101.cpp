//×Ö·ûºÏ¼¯

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int nums[126] = { 0 };
        int size = str.size();
        for (int i = 0; i < size; i++) {
            nums[str[i]]++;
            if (nums[str[i]] == 1) {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}