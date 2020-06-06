//��ģ��
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <class T1, class T2, class T3>
class Date
{
public:
	Date(T1 year, T2 month, T3 day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Display();
	/*{
		cout << _year << "-" << _month << "-" << _day << endl;
	}*/
private:
	T1 _year;
	T2 _month;
	T3 _day;
};
//��������ⶨ����ģ��ĳ�Ա��������Ҫ���Ϸ��͵�����
//������Ϊ "����<���Ͳ���>"
template <class T1, class T2, class T3>
void Date<T1, T2, T3>::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

void test2()
{
	//��ģ�岻�н�����ʽʵ����
	//Date d;
	//��ģ��
	//���ͺ�������ͬ
	//���ͣ�����<ģ��ʵ�ʲ�������>
	Date<int, int, int> d(2020, 5, 31);
	d.Display();
}


void printString(const string& str)
{
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		//*it = 'a';
		++it;
	}
	cout << endl;
}