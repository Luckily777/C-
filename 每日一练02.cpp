//ɾ�������ַ�

//1. �������
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);
	int size1 = str1.length();
	int size2 = str2.length();
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (str1[i] == str2[j]) {
				str1.erase(i, 1);
			}
		}
	}
	cout << str1 << endl;
	return 0;
}


//2. ��ϣӳ��˼��
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);
	int hashtable[256] = { 0 };//���ù�ϣӳ��
	for (size_t i = 0; i < str2.length(); i++) {
		hashtable[str2[i]]++;//���ڶ����ַ����д��ڵ��ַ�ȫ��ӳ�䵽���Ӧ��λ����ȥ
	}
	string ret;//�������ַ���
	for (size_t i = 0; i < str1.length(); i++) {
		if (hashtable[str1[i]] == 0) {//�ӹ�ϣ�����Ҷ�Ӧ��ֵ�������ڼ�ֵ����1�������ڼ�����0
			ret += str1[i];//������0��׷����ret�ַ��к�
		}
	}
	cout << ret << endl;
	return 0;
}