#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* num = new int[3];
    while (n) {
        int a, b, c;
        cin >> a >> b >> c;
        num[0] = a;
        num[1] = b;
        num[2] = c;
        int index;
        cin >> index;
        for (int i = 3; i < index; i++) {
            int temp = (num[0] + num[1] + num[2]);
            if (temp >= 10) {
                num[0] = num[2];
                num[1] = (temp / 10);
                num[2] = (temp % 10);
                i++;
            }
            else {
                num[0] = num[1];
                num[1] = num[2];
                num[2] = temp;
            }
        }
        cout << num[2] << endl;
        n--;
    }
    delete[] num;
    return 0;
}