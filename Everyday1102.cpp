//求最大连续bit数

#include <iostream>
using namespace std;

int main() {
    int byte;
    while (cin >> byte) {
        int sum;
        for (sum = 0; byte != 0; sum++) {
            byte = byte & (byte << 1);
        }
        cout << sum << endl;
    }
    return 0;
}