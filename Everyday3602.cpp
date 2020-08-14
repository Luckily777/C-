//mkdir

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<string> vs;
        int m = n;
        while (m--) {
            string s;
            cin >> s;
            vs.push_back(s);
        }

        for (int i = 0; i < n; i++) {
            int j;
            for (j = i + 1; j < n; j++) {
                if (vs[j].find(vs[i]) == 0) {
                    break;
                }
                if (j == n - 1) {
                    cout << "mkdir -p" << " " << vs[i] << endl;
                }
            }

        }
        cout << "mkdir -p" << " " << vs[n - 1] << endl;
        cout << endl;
    }
    return 0;
}