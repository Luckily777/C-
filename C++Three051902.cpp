//���ʵ����
//����һ�������ͱ����Ĺ���
//Ҳ������ֻ��һ�����ͼ��ͨ���ഴ�����������ǽ���������ת��Ϊһ��ʵ��
#include <stdio.h>
#include <iostream>
using namespace std;

struct A
{
public:  //Ĭ��public
	int _a;

	void fun()
	{
		cout << "struct A fun()" << endl;
	}
};

class B
{
private: //Ĭ��˽��
	int _a;

	void fun()
	{
		cout << "class B fun()" << endl;
	}

	void fun2();
};

void fun2()
{
	cout << "fun2()" << endl;
}

void B::fun2()
{
	cout << "B::fun2()" << endl;
}

void Test() {
	A a;
	B b;
	//���������� �����Զ������͵ı���һ��ϰ�߳�Ϊ����

	//struct����ĳ�ԱĬ�Ϸ���Ȩ��Ϊpublic
	//class����ĳ�ԱĬ�Ϸ���Ȩ��Ϊprivate
	a._a;
	a.fun;
	//���߲�����
	//b._a;
	//b.fun();
}