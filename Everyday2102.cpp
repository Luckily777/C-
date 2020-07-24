//mp3

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nums;
    while (cin >> nums) {
        int Temp;
        Temp = nums;
        vector<int> v(nums);
        vector<int> L(4);
        for (int i = 0; i < nums; i++) {
            v[i] = i + 1;
            if (i < 4) {
                L[i] = i + 1;
            }
        }
        int head = 0;
        char C;
        if (nums <= 4) {
            for (int i = 0; i < 3; i++) {
                cout << L[i] << " ";
            }
            cout << L[3] << endl;
        }
        while (cin >> C) {
            if (C == 'U') {
                if (head == 0) {
                    for (int i = 3; i >= 0; i--) {
                        L[i] = Temp;
                        Temp--;
                    }
                    head = 10;
                }
                else {
                    for (int i = 3; i >= 0; i--) {
                        L[i] = L[i] - 1;;
                    }
                    head--;
                }
            }
            if (C == 'D') {
                if (head == 10) {
                    for (int i = 0; i < 4; i++) {
                        L[i] = i + 1;
                    }
                    head = 1;
                }
                else {
                    for (int i = 0; i < 4; i++) {
                        L[i] = L[i] + 1;;
                    }
                    head--;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            cout << L[i] << " ";
        }
        cout << L[3] << endl;
        cout << head << endl;
    }
    return 0;
}