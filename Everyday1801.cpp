//统计每个月兔子的总数

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int month;
//    while (cin >> month) {
//        vector<int> v;
//        int count = 0;
//        if (month <= 2) {
//            count = 1;
//        }
//        else {
//            v.push_back(1);
//            v.push_back(1);
//            for (int i = 2; i < month; i++) {
//                v.push_back(v[i - 1] + v[i - 2]);
//                count = v[i];
//            }
//        }
//        cout << count << endl;
//    }
//    return 0;
//}