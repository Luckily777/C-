//Ï´ÅÆ
////
////#include <iostream>
////#include <vector>
////using namespace std;
////
////int main() {
////    int Group, n, k;
////    cin >> Group;
////    while (Group--) {
////        cin >> n >> k;
////        int num = 2 * n;
////        vector<int> v(num);
////        for (int l = 0; l < num; l++) {
////            cin >> v[l];
////        }
////        while (k--) {
////            vector<int> tmp(v.begin(), v.end());
////            for (int i = 0; i < n; i++) {
////                v[2 * i] = tmp[i];
////                v[(2 * i) + 1] = tmp[i + n];
////            }
////        }
////        for (int t = 0; t < num - 1; t++) {
////            cout << v[t] << " ";
////        }
////        cout << v[num - 1] << endl;
////    }
////    return 0;
////}