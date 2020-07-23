//×Ö·û´®ÄæÖÃ

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int size = str.size();
        for (int i = size - 1; i >= 0; i--) {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}