//��̬��Ա����ϰ
#include <iostream>
using namespace std;

//int cnt = 0;  //����ȫ�ֱ����Ļ�����ȫ�Խϵͣ����״۸�

class Date
{
public:
	Date(int year = 2020, int month = 12, int day = 20)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		++cnt;
		cout << "Date(int ,int ,int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++cnt;
		cout << "Date(const Date&)" << endl;
	}


	//��̬��Ա�����������ڲ�û��thisָ��
	static int getCount()
	{
		//��̬��Ա�������ܷ��ʷǾ�̬��Ա����/��������>��Ϊ�Ǿ�̬��Ա��Ҫthisָ�룬���Ǿ�̬��Ա�����ڲ�ȱ��thisָ�룬���Բ��ܷ���
		return 1;
	}


	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//�Ǿ�̬��Ա�������Է��ʾ�̬��Ա����/����
		getCount();
		cout << cnt << endl;
	}
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;

	//��̬��Ա���������ж�����˳�Ա���������Կ������Ա
	//��̬��Ա����������������ʱ���Ĭ��
	//��̬��Ա���ڶ���ģ���У�һ���������ݶΣ������ڳ�ʼ���б��г�ʼ��

public:
	static int cnt;
};

//��̬��Ա�����������ʼ��
int Date::cnt = 0;


Date fun(Date d) //��������
{
	cout << &d.cnt << endl;
	return d;
}

void Test()
{
	Date d;//����
	Date d2 = fun(d);//�������� fun�������Ż���ֻ�����ο������죬���δ���d2

	//��̬��Ա����/��̬��Ա�������ʷ�ʽ��
	// 1. �������
	cout << d.getCount() << endl;
	cout << d2.getCount() << endl;
	cout << &d.cnt << endl;
	cout << &d2.cnt << endl;
	// 2. ���� + �������޶���
	cout << &Date::cnt << endl;
	cout << Date::cnt << endl;
	cout << Date::getCount() << endl;
	//��ͨ��Աֻ��ͨ��������ʣ�����ͨ����������
	d.Display();
	//Date::Display(); //��֧��
}

int main() {
	Test();
}