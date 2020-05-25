//���������
#include <iostream>
using namespace std;

//��������غ�������ǿ����Ŀɶ���
//���������⣺�����ʹ�÷�ʽ����ͨ����һ��
//����ֵ operator +��Ҫ���ص�������������б�{}
//��������غ�������ǳ�Ա������������ĸ������������Ҫ�ĸ�����һ��������������ᴫ��thisָ����Ϊ��һ������
//thisָ��ʼ��վ��������������ĵ�һ��λ��


class Date {
public:
	//���캯��
	Date(int y = 1, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}
	//��������
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}


	bool IsEqual(const Date& d) {
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	
	bool operator==(const Date& d) {//�ײ�ӿ� bool operator==(Date* const this, const Date& d)
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
private:
	int _year;
	int _month;
	int _day;
	//A _a;//a����ָ�������Դ�Ŀռ�
};

//��ͨ����������غ���
bool operator==(const Date& d1, const Date& d2) {
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}

//�����������غ���
ostream& operator<<(ostream& _cout, const Date& date) {
	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}


void Test() {
	//����
	Date d(2020, 1, 1);
	Date d2(d);//��������

	Date d3(2020, 5, 23);

	cout << d.IsEqual(d2) << endl;
	cout << d.IsEqual(d3) << endl;

	cout << (d == d2) << endl;//�ȼ��ڵ�d.operator==(d2);
	cout << d.operator==(d2) << endl;
	cout << (d == d3) << endl;//�ȼ��ڵ�d.operator==(d3);
	cout << d.operator==(d3) << endl;
	//cout<<d<<endl;
}

