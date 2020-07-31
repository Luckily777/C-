//Èı½ÇĞÎ

#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    while (cin >> a >> b >> c) {
        int num[3];
        int i = 0;
        if (a > b) {
            if (a > c) {
                num[i++] = a;
                if (b > c) {
                    num[i++] = b;
                    num[i++] = c;
                }
                else {
                    num[i++] = c;
                    num[i++] = b;
                }
            }
            else {
                num[i++] = c;
                num[i++] = a;
                num[i++] = b;
            }
        }
        else {
            if (b < c) {
                num[i++] = c;
                num[i++] = b;
                num[i++] = a;
            }
            else {
                if (a > c) {
                    num[i++] = b;
                    num[i++] = a;
                    num[i++] = c;
                }
                else {
                    num[i++] = b;
                    num[i++] = c;
                    num[i++] = a;
                }
            }
        }
        if (num[1] + num[2] > num[0]) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}