//���Ʊ任


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, table = "0123456789ABCDEF";//��Ӧ��16����
    int m, n;
    cin >> m >> n;
    bool flag = false;//��־λ�������������������������
    if (m < 0) {
        m = 0 - m;//��Ϊ��������תΪ������ʹ�����־λΪ��
        flag = true;
    }
    while (m)
    {
        s += table[m % n];//���Խ�����ȡ��
        m /= n;//��
    }
    if (flag) {
        s += '-';
    }
    reverse(s.begin(), s.end());//����
    cout << s << endl;
    return 0;
}