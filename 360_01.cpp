#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int o1, o2;
        cin >> o1 >> o2;
        if (mp.find(o1) != mp.end()) {
            mp[o1].push_back(o2);
        }
        else {
            mp[o1] = v;
            mp[o1].push_back(o2);
        }
    }
    vector<int> result;
    int flag = 0;
    int count = 0;
    for (auto& it : mp) {
        flag = it.first;
        int size = it.second.size();
        if (size == 2 && size == m - count) {
            for (int i = flag; i <= n; i++) {
                result.push_back(i);
            }
            count = n;
            break;
        }
        count++;
    }
    if (count != n) {
        for (int i = count + 1; i <= n; i++) {
            result.push_back(i);
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}