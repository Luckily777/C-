//ì³²¨ÄÇÆõ·ïÎ²
//#include <iostream>
//#include<iomanip>
//using namespace std;
//
//int main() {
//    int Fib[100001] = { 0 };
//    Fib[0] = 1;
//    Fib[1] = 1;
//    for (int i = 2; i <= 100000; i++) {
//        Fib[i] = Fib[i - 1] + Fib[i - 2];
//        if (Fib[i] - 1000000 > 0) {
//            Fib[i] = Fib[i] % 1000000;
//        }
//    }
//    int n;
//    while (cin >> n) {
//        if (n < 37) {
//            cout << Fib[n] << endl;
//        }
//        else {
//            cout << setfill('0') << setw(6) << Fib[n] << endl;
//        }
//    }
//    return 0;
//}