//小易的升级之路


#include <iostream>
#include <vector>
using namespace std;

int MaxYuenum(int m, int n) {
    int r;
    while (r = m % n) {
        m = n;
        n = r;
    }
    return n;
}

int main() {
    int k, a;
    while (cin >> k >> a) {
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            遇见小于等于它能力值
            if (b[i] <= a) {
                a += b[i];
            }
            else {
                遇见大于它能力的
                a += MaxYuenum(a, b[i]);
            }
        }
        cout << a << endl;
    }
}