//���캯��
#include <iostream>
using namespace std;


class AA {
	//6����Ա����
public:
	AA() {

	}
	AA(int a) {

	}
};

class Data {
public:

	//���캯���� ��������������ͬ�� �޷���ֵ�� �������أ��������ڴ������Զ�����
	//ֻ�е���û�ж����κι��캯��ʱ���������Ż��Զ�����һ���޲ι��죬 ��������Ѿ������˹��캯��
	//�������������Զ����ɣ���ʹ����û����ʽ�����޲ι���

	//Ĭ�Ϲ��죺ֻ�ܴ���һ��
	// 1. ������Ĭ������
	// 2. ��ʾ������޲ι���
	// 3. ȫȱʡ���캯��
	/*Date()
	{

	}*/
	//ȫȱʡĬ�Ϲ���
	Date(int y = 2020, int m = 5, int d = 20)
	{
		_year = y;
		_month = m;
		_day = d;
	}
	//���صĹ��캯��
	Date(float f)
	{

	}

	void Display()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		//this = nullptr;
		this->_year = 2022;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void fun1()
	{
		cout << "Date::fun1()" << endl;
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
	//������д����Զ����Ա�� ���캯�����Զ������Զ����Ա��Ĭ�Ϲ��죬����Զ����Ա�ĳ�ʼ����
	//����Զ����Աû��Ĭ�Ϲ��캯�����������������
	AA _aa;
};


void test6()
{
	Date d;
	d.SetDate(2020, 5, 15);
	d.Display();

	Date d2(2020, 5, 20);
	d2.Display();

	Date d3();//����һ����������������޲ι���

	//Date d4(2020);

	Date d5(2.0f);

	AA a1;
	AA a2(3);

	int i = 3;
}

int main()
{
	test6();
	return 0;
}



