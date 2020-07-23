//ÆûË®Æ¿

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int K = n;
        int count = 0;
        while (K > 2) {
            int Dnum = K / 3;
            int Snum = K % 3;
            K = Dnum + Snum;
            count += Dnum;
        }
        if (K == 2) {
            count += 1;
        }
        cout << count << endl;
    }
    return 0;
}