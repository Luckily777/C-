//����ʶ��
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int func(int a)
{
	cout << a << endl;
	return a;
}

void func2()
{
	cout << "func2����" << endl;
}

void testAuto()
{
	map<string, string> m;
	m["123"] = "456";
	m["789"] = "012";

	std::map<std::string, std::string>::iterator it = m.begin();
	//auto: ����ʱ���ݳ�ʼ�����ʽ���������Ƶ�
	// auto: ����ʱ����ʶ��
	auto it2 = m.begin();

	//decltype: ����ʱ����ʶ��
	decltype(1 + 2) a;

	decltype(func(10)) b;
	//decltype: ����в����б��Ƶ�����ֵ����
	cout << "b: type: " << typeid(b).name() << endl;
	//decltype: ���û�в����б�ֻ�к��������Ƶ�Ϊ�����Ľӿ�����
	cout << typeid(decltype(func)).name() << endl;
}
