//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�(�����Ѿ�����)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int size = str.size();
        int count;
        for (int i = 0; i < size; i++) {
            count = 0;
            for (int j = 0; j < size; j++) {
                if (str[i] == str[j]) {
                    count++;
                }
            }
            if (count == 1) {
                cout << str[i] << endl;
                break;
            }
        }
        if (count != 1) {
            cout << -1 << endl;
        }
    }
    return 0;
}