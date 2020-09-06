#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n;
//    vector<long long> v;
//    v.resize(n);
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//    }
//    cin >> m;
//    vector<long long> ret;
//    ret.resize(m);
//    vector<long long> mm;
//    for (int i = 0; i < m; i++) {
//        cin >> ret[i];
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (ret[j] == v[i]) {
//                mm.push_back(ret[j]);
//                break;
//            }
//        }
//    }
//    sort(mm.begin(), mm.end());
//    reverse(mm.begin(), mm.end());
//    for (int i = 0; i < mm.size(); i++) {
//        cout << mm[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    int index = v.size()-2;
    int Sumtime = 0;
    while (m > 0&&index>=0) {
        if (m > v[index]) {
            Sumtime += v[index];
            m -= v[index--];
        }
        else {
            Sumtime += v[v.size() - 1];
        }
    }
    cout << Sumtime << endl;
    return 0;
}