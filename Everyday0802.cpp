//最小公倍数
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a, b, c;
//    cin >> a >> b;
//    int ret = a * b;
//    int MinNum = 0;
//    if (a == b) {
//        MinNum = a;
//    }
//    if (a < b) {
//        int temp = 0;
//        temp = a;
//        a = b;
//        b = temp;
//    }
//    while ((a - b) != 0) {
//        c = a - b;
//        if (c > b) {
//            a = c;
//        }
//        else {
//            a = b;
//            b = c;
//        }
//    }
//    MinNum = ret / b;
//    cout << MinNum << endl;
//    return 0;
//}