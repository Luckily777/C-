//iNOC产品部-杨辉三角的变形

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    while (cin >> n) {
//        vector<vector<int>> v(n);
//        if (n < 2) {
//            cout << -1 << endl;
//        }
//        else {
//            v[0].push_back(1);
//            v[1].push_back(1);
//            v[1].push_back(1);
//            v[1].push_back(1);
//            for (int i = 2; i < n; i++) {
//                int temp = i - 1;
//                v[i].push_back(1);
//                v[i].push_back((v[temp][0]) + (v[temp][1]));
//                for (int j = 2; j <= i; j++) {
//                    v[i].push_back((v[temp][j - 2]) + (v[temp][j - 1]) + (v[temp][j]));
//                }
//                for (int k = i - 1; k >= 0; k--) {
//                    v[i].push_back(v[i][k]);
//                }
//            }
//            for (int m = 1; m < n; m++) {
//                if ((v[n-1][m]) % 2 == 0) {
//                    cout << m+1 << endl;
//                    break;
//                }
//            }
//        }
//
//    }
//    return 0;
//}