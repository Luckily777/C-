//��ģ��
#include <iostream>
using namespace std;

//��ģ����ػ�
// 1. ȫ�ػ�--> ���еĲ�����Ϊ��������

//�ػ�֮ǰ��Ҫ���ڻ�����ģ��
template <class T1, class T2>
class A
{
public:
	A()
	{
		cout << "A(T1, T2)" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

//ȫ�ػ�
template <>
class A<int, char>
{
public:
	A()
	{
		cout << "A(int, char)" << endl;
	}
private:
	int _t1;
	char _t2;
};



//2.ƫ�ػ��� a. �����ػ���  b. ��ģ���������һ��������
template <class T1>
class A<T1, double>
{
public:
	A()
	{
		cout << "A(T1, double)" << endl;
	}
private:
	T1 _t1;
	double _t2;
};

template <class T1>
class A<T1, char>
{
public:
	A()
	{
		cout << "A(T1, char)" << endl;
	}
private:
	T1 _t1;
	double _t2;
};

template <class T1, class T2>
class A<T1&, T2&>
{
public:
	A()
	{
		cout << "A(T1&, T2&>" << endl;
	}
};

void test3()
{
	A<int, int>  a;
	A<int, char> b;
	A<float, char> f;
	A<int, double> c;
	A<int&, int&> d;
	A<int&, double&> e;
}
