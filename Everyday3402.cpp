//³­ËÍÁĞ±í

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1;
    string str2;
    while (getline(cin, str1)) {
        getline(cin, str2);
        if (str1.find(str2) != -1) {
            cout << "Ignore" << endl;
        }
        else {
            cout << "Important!" << endl;
        }
    }
    return 0;
}