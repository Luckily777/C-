//¼ÆËãÌÇ¹û
#include <iostream>
using namespace std;

int main() {
    int A = 0, B = 0, C = 0;
    int* Suger = new int[4];
    for (int i = 0; i < 4; i++) {
        cin >> Suger[i];
    }
    for (A = 0; A <= 30; A++) {
        for (B = 0; B <= 30; B++) {
            for (C = 0; C <= 30; C++) {
                if (((A - B) == Suger[0]) && ((B - C) == Suger[1]) && ((A + B) == Suger[2]) && ((B + C) == Suger[3])) {
                    cout << A << " " << B << " " << C << " " << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}