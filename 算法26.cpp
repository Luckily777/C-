// »ØÎÄË÷Òı


#include <iostream>
#include <string>
using namespace std;

int IsPalindrome(string& str, int* start, int* end) {
    int i = 0;
    int j = str.size() - 1;
    bool result = true;
    while (i <= j) {
        if (str[i] != str[j]) {
            result = false;
            break;
        }
        i++;
        j--;
    }
    if (start != nullptr) {
        *start = i;
    }
    if (end != nullptr) {
        *end = j;
    }
    return result;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int start = 0;
        int end = str.size() - 1;
        if (IsPalindrome(str, &start, &end)) {
            cout << -1 << endl;
        }
        else {
            str.erase(end, 1);
            if (IsPalindrome(str, nullptr, nullptr)) {
                cout << end << endl;
            }
            else {
                cout << start << endl;
            }
        }
    }
    return 0;
}