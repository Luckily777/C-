//C++11�ĳ�ʼ����ʽ���൱�ڸ�һ��ȱʡֵ
#include <iostream>
using namespace std;

class Date
{
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


	//���һ����ѡ��ǰ������о���ʹ��ǰ���
	//�����ȱʡ�Ĺ��캯������ô��ʹ��ȱʡ���캯��������
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};
