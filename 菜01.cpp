//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    vector<vector<int>> mat;
//    string tmp;
//    cin >> tmp;
//    int i = 0;
//    vector<int> ans;
//    while (i < tmp.size()) {
//        if (tmp[i] >= '0' && tmp[i] <= '9') {
//            ans.push_back(tmp[i] - '0');
//        }
//        if (tmp[i] == '#') {
//            mat.push_back(ans);
//            ans.clear();
//        }
//        i++;
//    }
//    mat.push_back(ans);
//    vector<int> result;
//    int x1, y1, x2, y2;
//    for (x1 = y1 = 0, x2 = mat.size() - 1, y2 = mat[0].size() - 1; x1 <= x2 && y1 <= y2; x1++, y1++, x2--, y2--) {
//        for (int y = y1; y <= y2; y++) {//打印行
//            result.push_back(mat[x1][y]);
//        }
//        if (x1 == x2) {//若只存在一行
//            break;
//        }
//        for (int x = x1 + 1; x <= x2; x++) {//打印列
//            result.push_back(mat[x][y2]);
//        }
//        if (y1 == y2) {//若只存在一列
//            break;
//        }
//        for (int y = y2 - 1; y >= y1; y--) {//反向打印最下面的一行
//            result.push_back(mat[x2][y]);
//        }
//        for (int x = x2 - 1; x > x1; x--) {//反向打印最左边的一列
//            result.push_back(mat[x][y1]);
//        }
//    }
//    for (int i = 0; i < result.size(); i++) {
//        if (i == result.size() - 1) {
//            cout << result[i];
//        }
//        else {
//            cout << result[i] << ',';
//        }
//    }
//    cout << endl << endl;
//    return 0;
//}