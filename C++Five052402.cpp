//���ι��캯��

#include <iostream>
using namespace std;
class A {
public:
	//explicit:�������ι������ʽ����ת��
	//explicit
	A(int a)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

	A(int a, int b)
		:_a(a)
	{
		cout << "A(int)" << endl;
	}

	A(const A& a)
		:_a(a._a)
	{
		cout << "A(const A&)" << endl;
	}

	A& operator=(const A& A) {
		if (this != &a) {
			_a = a._a;
		}
		cout << "A& operator=(const A& a)" << endl;
		return *this;
	}
private:
	int _a;
};

void Test() {
	A a(1);//��������
	A a2 = 2;//�������󣺵��ι��캯������ʽ����ת��--->���ù��촴��һ���������� + �������죨ͨ���������󿽱�����a2����
	a2 = 3;//��Ϊ�������繹�캯���������������󣬵��ø�ֵ��ʹ�����������a2��ֵ

	//ֻ֧�ֵ��ι��캯������ʽ����ת����������벻֧��
	//A a4=5��6
}


int main() {
	//test8();
	test9();
	return 0;
}