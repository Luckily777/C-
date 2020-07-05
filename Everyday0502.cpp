//连续最大和
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* nums = new int[n];
    int Maxnums = 0, Curnums = 0;;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        Curnums += nums[i];
        if (Curnums > Maxnums) {
            Maxnums = Curnums;
        }
        if (Curnums < 0) {
            Curnums = 0;
        }
    }
    cout << Maxnums << endl;
    return 0;
}