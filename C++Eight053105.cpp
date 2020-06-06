//string�����ֱ�����ʽ
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test10()
{
	string str("0123456789");

	//1. ������
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//2. operator[]: �ɶ���д�ӿڣ����Խ�磬�Ƿ�����
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.operator[](i) << " ";
		str[i] = 'a';
	}
	cout << endl;
	//operator[]��д
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
	}

	//str[100] = 'c';
	cout << endl;
	//at:�ɶ���д�� ���ǿɶ��Բ�ǿ, ���Խ�磬���쳣
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//str.at(100) = 'c';
	//3. ��Χfor����: ֧�ֶ�д, �����Ҫ�޸ģ����������Ϊ��������
	//   �ײ�ͨ��������ʵ��
	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;

	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;
}