//×Ö·û´®Í¨Åä·û

#include <iostream>
#include <string>
using namespace std;

int main() {
    string Tstr;
    string Pstr;
    while (cin >> Tstr >> Pstr) {
        int sizeT = Tstr.size();
        int sizeP = Pstr.size();
        int k = 0;
        for (int i = 0; i < sizeT; i++) {
            if (Tstr[i] == '*') {
                if (i == sizeT - 1) {
                    cout << "true" << endl;
                    break;
                }
                else {
                    while (Pstr[k] != Tstr[i + 1]) {
                        k++;
                    }
                }
            }
            else if (Tstr[i] == '?') {
                k++;
            }
            else {
                if (Tstr[i] != Pstr[k++]) {
                    cout << "false" << endl;
                    break;
                }
            }
            if (i == sizeT - 1) {
                cout << "true" << endl;
                break;
            }
        }
    }
}