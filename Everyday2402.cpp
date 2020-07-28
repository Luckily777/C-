//√‘π¨Œ Ã‚

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int N, M;
//    while (cin >> N >> M) {
//        vector<vector<int>> v(N, vector<int>(M));
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < M; j++) {
//                int temp;
//                cin >> temp;
//                v[i][j] = temp;
//            }
//        }
//        int temp = 0;
//        for (int i = 0; i < N; i++) {
//            for (int j = temp; j < M; j++) {
//                if (v[i][j] == 0) {
//                    cout << '(' << i << ',' << j << ')' << endl;
//                    temp = j;
//                }
//                else {
//                    break;
//                }
//            }
//        }
//    }
//    return 0;
//}