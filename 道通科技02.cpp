#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int v, n;
    cin >> v >> n;
    if (n == 0) {
        cout << v << endl;
        return 0;
    }
    vector<int> Vt;
    Vt.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> Vt[i];
    }
    sort(Vt.begin(), Vt.end());
    for (int i = Vt.size() - 1; i >= 0; i--) {
        if (Vt[i] <= v) {
            v -= Vt[i];
        }
    }
    cout << v << endl;
    return 0;
}