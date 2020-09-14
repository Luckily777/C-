//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> v(n, vector<int>(m));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> v[i][j];
//        }
//    }
//    int flag = 2;
//    if (n % 3 == 0) {
//        flag = 3;
//    }
//    vector<vector<int>> result;
//    int start = 0;
//    int end = n;
//    while (start <= end) {
//        int qql = 0;
//        for (int j = 0; j < m; j++) {
//            if (v[0][j] != v[end-1][j]) {
//                for (int i = start; i < end; i++) {
//                    result.push_back(v[i]);
//                }
//                break;
//            }
//            else {
//                qql++;
//            }
//        }
//        if (qql == m) {
//            end /= flag;
//        }
//        else {
//            break;
//        }
//    }
//    for (int i=0; i < result.size(); i++) {
//        for (int j = 0; j < m; j++) {
//            cout << result[i][j]<<" ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//
