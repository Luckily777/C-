//查找输入整数二进制中1的个数

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        cout << count << endl;
    }
    return 0;
}