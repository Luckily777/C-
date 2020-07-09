//201301 JAVA��Ŀ2-3��
#include <iostream>
using namespace std;

int Stem(int n, int m) {
    if ((n == 0) || (m == 0)) {
        return 1;
    }
    else {
        return Stem(n, m - 1) + Stem(n - 1, m);
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << Stem(n, m) << endl;
    }
    return 0;
}