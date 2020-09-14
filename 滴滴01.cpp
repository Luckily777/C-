#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    if (n == 1 || str.size() == 0 || str.size() == 1) {//����ȡ��λΪ1�����������ַ������ȵ���1��0����ֱ�ӷ���Դ�ַ���
        cout << str << endl;
        return 0;
    }
    if (n >= str.size()) {//�����ȡ�ó��ȴ����ַ������ȣ���֤������Ϊһ���ַ�����ֱ�������������
        reverse(str.begin(), str.end());
        cout << str << endl;
        return 0;
    }
    vector<string> result;//�����м�����ռ䣬��ÿһ����ȡ�������ַ�����������Ž�ȥ
    int size = str.size();
    int start = 0;
    int end = n;
    while (size >= n) {
        string s = str.substr(start, end);
        str.erase(start, end);
        reverse(s.begin(), s.end());
        result.push_back(s);
        s.clear();
        size -= n;
    }
    if (size != 0) {
        string s;
        s = str.substr(start, str.size());
        reverse(s.begin(), s.end());
        result.push_back(s);
    }
    str.clear();
    for (int i = 0; i < result.size(); i++) {
        str += result[i];
    }
    cout << str << endl;
    return 0;
}

