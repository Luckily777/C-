//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    vector<int> dp;
//    int n;
//    cin >> n;
//    if (n == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    dp.resize(n + 1);
//    dp[0] = 1;
//    dp[1] = 1;
//    for (int i = 2; i <= n; i++) {
//        for (int j = 1; j <= i; j++) {
//            dp[i] += dp[j - 1] * dp[i - j];
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}