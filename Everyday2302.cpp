//¼ÆËã×Ö·û´®µÄ¾àÀë

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a, b;
    while (cin >> a >> b) {
        int len1 = a.size();
        int len2 = b.size();
        vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = j;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    int tem = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i - 1][j - 1], tem) + 1;
                }
            }
        }
        cout << dp[len1][len2] << endl;
    }
    return 0;
}