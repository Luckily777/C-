//���������
#include <stdio.h>
#include <iostream>
using namespace std;


struct A
{
public:
	int _a;
	void fun() {
		cout << "struct A fun()" << endl;
	}
};

class B
{
private:
	int _a;

	void fun() {
		cout << "class B fun()" << endl;
	}
	void fun2();
};

void fun2() {//���������һ��ȫ�����
	cout << "fun2()" << endl;
}

void B::fun2() {//����֮�е�fun2�Ķ���
	cout << "B::fun2()" << endl;
}