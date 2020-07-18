//完全数计算

#include <iostream>
using namespace std;
int PerFectNum = 0;


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= (i / 2); j++) {
            if (i % j == 0) {
                count += j;
            }
        }
        if (count == i) {
            PerFectNum++;
        }
    }
    if (PerFectNum > 0) {
        cout << PerFectNum << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}