//ģ�庯�� ʵ����

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
T add(const T& a, const T& b)
{
	return a + b;
}

template <class T1,class T2>
T2 Add(const T1& a, const T2& b)
{
	return a + b;
}

void Test()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	add(a, b);

	add<int>(a, c);

	Add(a, c);

	Add(a, b);
}


int Add(const int& a, const int& b)
{
	return a + b;
}

void TestOne()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';

	//��ͨ������ģ�庯������ʱ�������ͨ�����Ĳ������Ϳ�����ȫƥ�䣬��ִ����ͨ������������ģ�庯����ʵ����
	//Ҳ����ζ�ſ���ֱ�ӳ��ֳɵķ�
	Add(a, b);

	//��ͨ������ģ�庯������ʱ����ͨ�����Ĳ������Ͳ��ܹ���ȫƥ��
	//����ʵ�����ĺ���������ȫƥ����������ͣ������ʵ��������ζ�ŷ����óԣ�������
	Add(a, c);

	//��ͨ������ģ�庯������ʱ������ָ������Ҫʵ�����������ʵ����
	Add<int>(a,b) 
}
