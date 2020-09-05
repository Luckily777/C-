//进制变换


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, table = "0123456789ABCDEF";//对应的16进制
    int m, n;
    cin >> m >> n;
    bool flag = false;//标志位，用来检验所输入的数的正负
    if (m < 0) {
        m = 0 - m;//若为负，将其转为整数，使得其标志位为正
        flag = true;
    }
    while (m)
    {
        s += table[m % n];//除以进制数取余
        m /= n;//除
    }
    if (flag) {
        s += '-';
    }
    reverse(s.begin(), s.end());//逆置
    cout << s << endl;
    return 0;
}