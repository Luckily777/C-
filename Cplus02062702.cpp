//������

#include <iostream>
using namespace std;

//�����ࣺ�������麯������
//�����಻��ʵ��������
//���壺 ʵ�ֶ�̬
//���֣��ӿڼ̳�
class A
{
public:
	//���麯���� û�к�������麯��
	virtual void fun() = 0;
};

class B : public A
{
public:
	virtual void fun()
	{
		cout << "B::fun()" << endl;
	}
};

void test2()
{
	/*A a;
	a.fun();*/

	B b;
	A* pb = &b;
	b.fun();
	pb->fun();
}
