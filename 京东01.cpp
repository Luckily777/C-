#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> vict;
    vector<vector<int>> mm;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        v.resize(2);
        cin >> v[0];
        cin >> v[1];
        vict.push_back(v);
        v.clear();
    }
    for (int i = 0; i < p; i++) {
        vector<int> v;
        v.resize(2);
        cin >> v[0];
        cin >> v[1];
        mm.push_back(v);
        v.clear();
    }
    vector<int> result;
    result.push_back(vict[0][0]);
    result.push_back(vict[0][1]);
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < result.size(); j++) {
            if (result[j] == vict[i][0] || result[j] == vict[i][1]) {
                result.push_back(vict[i][0]);
                result.push_back(vict[i][1]);
                break;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        int flag = 0;
        for (int j = 0; j < result.size(); j++) {
            if (result[j] == mm[i][0]) {
                flag++;
                mm[i][0] = -1;
            }
            if (result[j] == mm[i][1]) {
                mm[i][1] = -1;
                flag++;
            }
        }
        if (flag == 2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}