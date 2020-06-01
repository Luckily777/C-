//��Ԫ��������Ԫ��
#include <iostream>
using namespace std;
class Date
{
public:
	//��Ԫ�����������ã�����һ��ͻ�Ʒ�װ���﷨
	//��Ԫ������ friend + ���������Ķ���/����
	//��Ԫ�������Է������˽�г�Ա
	//��Ԫ����������ĳ�Ա������������ͨ�ķǳ�Ա����
	//ֻ��Ҫ������������Ԫ����������Ҫ�����ж���
	//��Ԫ������������������κεط������ܷ����޶���������

	friend ostream& operator<<(ostream& outputS, Date& d);
	friend istream& operator >> (istream& inputS, Date& d);
	friend class B;
	/*Date()
	{}*/

	Date(int year = 2020, int month = 12, int day = 25)
		:_year(year)
		, _month(month)
		, _day(day)

	{
		cout << "Date(int,int,int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._month)
	{

		cout << "Date(const Date&)" << endl;
	}


	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		//�Ǿ�̬��Ա�������Է��ʾ�̬��Ա����/����
	}


private:
	int _year = 1;
	int _month = 1;
	int _day = 1;

};

class B
{
	//��Ԫ��ϵ�ǵ����ˣ������ڵ���˼
	//���һ��������һ�������Ԫ�࣬������е����г�Ա������Ϊ��һ�������Ԫ����
	//��Ԫ��ϵ���ܴ��ݣ� ���������ѵ����Ѳ�һ�����Լ�������
public:
	//disPlay, fun, fun1��ΪDate��ĵ���Ԫ����
	void disPlay(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}

	void fun(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}

	void fun1(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}
};

void test4()
{
	B b;
	Date d(2020, 5, 26);
	b.disPlay(d);
}