//�ַ������ҳ�����ִ�


#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, ret, cur;
    while (getline(cin, str)) {
        for (int i = 0; i <= str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {//��������
                cur += str[i];
            }
            else {//�����ַ�������Ƚ�֮ǰ�洢�͵�ǰ���ִ��ĳ���
                if (ret.size() < cur.size()) {
                    ret = cur;
                }
                else {
                    cur.clear();
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}