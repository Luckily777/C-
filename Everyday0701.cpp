//ì³²¨ÄÇÆõÊıÁĞ
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int f0 = 0, f1 = 1, f;
    int k = 0, l = 0;
    while (1) {
        f = f0 + f1;
        k = N - f;
        if (k>=0) {
            l = k;
        };
        if (k < 0) {
            if (l < (-k)) {
                cout << l << endl;
                break;
            }
            else {
                k = -k;
                cout <<k << endl;
                break;
            }
        }
        f0 = f1;
        f1 = f;
    }
}