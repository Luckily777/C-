//#include <iostream>
//#include <vector>
//using namespace std;
////直接使用选择排序或者插入排序，去进行排序即可
//void Swap(vector<int>& result, int start, int end) {
//    int temp;
//    temp = result[end];
//    result[end] = result[start];
//    result[start] = temp;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<vector<int>> vt(n, vector<int>(2));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 2; j++) {
//            cin >> vt[i][j];
//        }
//    }
//    vector<int> result(n);
//    for (int i = 0; i < n; i++) {
//        result[i] = i + 1;
//    }
//    for (int i = 0; i < n - 1; i++) {
//        if (vt[i][1] < vt[i + 1][1]) {
//            Swap(result, i, i + 1);
//        }
//        if (vt[i][1] == vt[i + 1][1]) {
//            if (vt[i][0] < vt[i + 1][0]) {
//                Swap(result, i, i + 1);
//            }
//        }
//    }
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//    cout << endl;
//    return 0;
//
//}