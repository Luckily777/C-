//快到碗里来

#include <iostream>
using namespace std;

int main() {
    double n, r;
    while (cin >> n >> r) {
        double L = 2 * r * 3.14;
        if (n > L) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}