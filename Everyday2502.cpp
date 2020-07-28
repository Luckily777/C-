//Êý¸ù

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        size_t count = 0;
        int nums = 0;
        for (int i = 0; i < str.size(); i++) {
            nums += str[i] - '0';
        }
        while (nums) {
            int temp = nums % 10;
            count += temp;
            nums /= 10;
            if ((nums == 0) && (count >= 10)) {
                nums = count;
                count = 0;
            }
        }
        cout << count << endl;
    }
}