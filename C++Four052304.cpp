//��ֵ���������
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}

	//��ֵ��������غ����� d=d2�����޸��Ѿ����ڵĶ�������ݣ�����ȥ�����µĶ���
	//�����д��������Ҳ��Ĭ�����ɣ�Ĭ�����ɵ�Ҳ���ֽڿ�������ǳ����
	//�����ǰ��������Դ�Ļ����������ʽ���帳ֵ��������غ�����������

	Date& operator=(const Date& d2)
	{
		//�ж��Ƿ���Լ���ֵ
		if (this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}

		cout << "operator=(const Date& d2)" << endl;
		//���ص�ǰ���ô˺����Ķ�����
		return *this;
	}

	//private:
	int _year;
	int _month;
	int _day;
};


void Test() {
	Date d(2020, 5, 22);
	Date d2(2019, 1, 1);

	//������󶼴��ڣ����ø�ֵ��������غ����������߶��󲻴��ڣ�����ÿ�������
	d2 = d;
	d2.operator==(d);// ͬ�ϵȼ�
	d2 = d2;
	Date d3(2018, 10, 1);

	//������ֵ����������ֵ
	d = d2 = decltype;
	d.operator=(d2.operator=(d3));//ͬ����ȼ�
	Date d4 = d3;//��Ϊd4�����ڣ�����ÿ������죬��d3����d4����
}
