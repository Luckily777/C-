//读入一个字符串str，输出字符串str中的连续最长的数字串
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int nums = 0;
    char str2[255] = " ";
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if ((str[i] >= '1') && (str[i] <= '9')) {
            int k = i + 1;
            while ((str[k] >= '1') && (str[k] <= '9')) {
                k++;
            }
            int j;
            for (j = i + 1; j < k; j++) {
                if ((str[j] - 1) != str[j - 1]) {
                    j = k + 1;
                }
            }
            if ((j == k) && ((k -i) > nums)) {
                nums = k -i;
                int t = 0;
                for (int m = i; m < k; m++) {
                    str2[t++] = str[m];
                }
            }
            i = k;
        }
    }
    cout << str2 << endl;
    return 0;
}