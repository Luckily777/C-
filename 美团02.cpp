//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n, m, k;
//    cin >> n >> m >> k;
//    if (m > n || n < 2 || m == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    vector<int> v;
//    v.resize(n);
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//    }
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        int flag = 0;
//        for (int j = i; j < i + m; j++) {
//            if (v[j] < k) {
//                break;
//            }
//            else {
//                flag++;
//            }
//        }
//        if (flag == m) {
//            count++;
//        }
//    }
//    cout << count << endl;
//    return 0;
//}