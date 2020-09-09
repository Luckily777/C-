#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    long long Sum = 1;
    for (int i = 1; i <= a; i++) {
        Sum *= i;
    }
    int flag = 0;
    while (Sum % 10 == 0) {
        flag++;
        Sum /= 10;
    }
    cout << flag << endl;
    return 0;
}
