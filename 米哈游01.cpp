//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main() {
//    int m, n;
//    cin >> m >> n;
//    vector<vector<char>> mat(m, vector<char>(n));
//    char c = 'A';
//    for (int x1 = 0, x2 = m - 1, y1 = 0, y2 = n - 1; x1 <= x2 && y1 <= y2; x1++, x2--, y1++, y2--) {
//        for (int y = y1; y <= y2; y++) {//打印行
//            mat[x1][y] = c++;
//            if (c == 91) {
//                c = 'A';
//            }
//        }
//        if (x1 == x2) {//若只存在一行
//            break;
//        }
//        for (int x = x1 + 1; x <= x2; x++) {//打印列
//            mat[x][y2] = c++;
//            if (c == 91) {
//                c = 'A';
//            }
//        }
//        if (y1 == y2) {//若只存在一列
//            break;
//        }
//        for (int y = y2 - 1; y >= y1; y--) {//反向打印最下面的一行
//            mat[x2][y] = c++;
//            if (c == 91) {
//                c = 'A';
//            }
//        }
//        for (int x = x2 - 1; x > x1; x--) {//反向打印最左边的一列
//            mat[x][y1] = c++;
//            if (c == 91) {
//                c = 'A';
//            }
//        }
//    }
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << mat[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}