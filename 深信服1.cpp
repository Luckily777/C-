//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int W, L;
//    cin >> W >> L;
//    if (W == 0 || L == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    vector<int> v;
//    v.resize(L);
//    for (int i = 0; i < L; i++) {
//        cin >> v[i];
//    }
//    int max = 0;
//    int sum = 0;
//    for (int i = v.size() - 1; i >= 0; i--) {
//        if (max > v[i]) {
//            sum += (max - v[i]);
//        }
//        else {
//            max = v[i];
//        }
//    }
//    int Vmax = sum * W;
//    cout << Vmax << endl;
//    return 0;
//}