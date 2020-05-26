#include <iostream>
using namespace std;
class Time
{
public:
	Time(int a = 1)
		:_a(a)
	{
		cout << "Time(int)" << endl;
	}
private:
	int _a;
};

class Date1
{
public:
	Date1(int y = 1, int m = 1, int d = 1)
		//��ʼ���б� : ��Ա(��ʼ��ֵ/���ʽ), ��Ա2()......
		//ÿһ����Ա����ֻ���ڳ�ʼ���б��г���һ��
		//����ĳ�Ա��������ĵط��� ��ʼ���б�
		//��������ó�Ա��const��Ա��û��Ĭ�Ϲ��캯�����Զ����Ա�������ڳ�ʼ���б��н��г�ʼ��
		//������Ա���Բ�������ʽ��ʼ��
		//�����Զ����Ա������ڳ�ʼ���б��г�ʼ������ʹ���ڳ�ʼ���б�����ʽ��ʼ����
		//������Ҳ���ڳ�ʼ���б����Զ������Զ����Ա��Ĭ�Ϲ�����ɳ�ʼ��
		//��Ա�����ڳ�ʼ���б��г�ʼ��˳��:������˳��һ�£������ڳ�ʼ���б��е�˳���޹�
		//ע�⣺��ó�ʼ���б��еĳ�Ա˳�������˳�򱣳�һ��
		: _a(_year)
		,_year(y)
		, _month(2 * _year)
		,_day(3 * _year)
		,_b(d)
		//, _time(10)
	{
		_year = y;
		_month = m;
		_day = d;
		//��_time���¸��ƣ������ǳ�ʼ��
		_time = Time(10);
	}



private: //��Ա���������ĵط�
	int _year;
	int _month;
	int _day;
	int& _a;  //�����ڶ���ʱ�����ʼ�����˴����Ƕ���ĵط�
	const int _b;  //const�����ڶ���ʱ�����ʼ�����˴����Ƕ���ĵط�
	Time _time;

};

class A
{
public:
	//explicit: �������ι������ʽ����ת��
	/*explicit*/ A(int a)
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

	A& operator=(const A& a)
	{
		if (this != &a)
		{
			_a = a._a;
		}
		cout << "A& operator=(const A& a)" << endl;
		return *this;
	}

private:
	int _a;
};


void test8()
{
	Date1 d(2020, 5, 25);
}

void test9()
{
	A a(1); //��������
	A a2 = 2; //��������:���ι��캯������ʽ����ת�� --> ���ù��촴��һ����������+ �������죨ͨ���������󿽱�����a2����)
	a2 = 3;  //3��Ϊ�������빹�캯���� ������������ ���ø�ֵ��ʹ�����������a2��ֵ
	
	//ֻ֧�ֵ��ι��캯������ʽ����ת��,������벻֧��
	//A a4 = 5, 6;
}
int main()
{
	//test8();
	test9();
	return 0;
}