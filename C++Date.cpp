//������
#include <iostream>
using namespace std;

class Date {
public:
	Date(int year = 1, int month = 1, int day = 1) {
		//�ж������Ƿ�Ϸ�
		if (year > 0 && month > 0 && month < 13
			&& day>0 && day <= GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "���ڲ��Ϸ���" << year << "-" << month << "-" << day << endl;
			cout << "����ΪĬ��ֵ��2000-1-1" << endl;
			_year = 200;
			_month = 1;
			_day = 1;
		}
	}

	int GetMonthDay(int year, int month) {
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		//�ж����Ƿ�Ϊ����
		if (month == 2
			&& (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
			++day;
		}
		return day;
	}

	// a+=b
	Date& operator+=(int day) {
		//a+=-b ---->>> a-=b
		if (day < 0) {
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month)) {
			//��ȥ���µ��������·ݽ�λ
			_day -= GetMonthDay(_year, _month);
			++_month;
			//�ж��·��Ƿ����
			if (_month == 13) {
				//��λ����һ��1��
				_month = 1;
				_year++;
			}
		}
		return *this;
	}


	//ǰ��++ ��++d������++ ����++֮���ֵ
	Date& operator++() {
		return *this += 1;
		//�ȼ���return (*this).operator+=(1);
		//return *this;
	}


	//����++��d++������++������++֮ǰ��ֵ
	//ǰ��++������++��Ϊ��Ŀ�����
	//���Ϊ��Ա�����������ϲ���Ҫ��ʽ���Σ����������Զ�����thisָ��
	//int�� �ββ���һ�������Ĳ�����ֻ��һ����ǲ��������������������Ķ��壬ͨ���﷨�����������Խ���Ϊ����++
	Date operator++(int) {
		//����++֮ǰ��ֵ
		Date ret(*this);
		//++
		*this += 1;
		//����++֮ǰ��ֵ
		return ret;
	}

	Date& operator-=(int day) {
		if (day < 0) {
			return *this += -day;
		}
		_day -= day;
		//�ж�_day�Ƿ�Ϊ��ֵ����Ϊ0��������λ
		while (_day <= 0) {
			//�·���λ
			--_month;
			//�·��Ƿ�Ϊ��ֵ����Ϊ0
			if (_month == 0) {
				_month = 12;
				//�����λ
				--_year;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	//ǰ��--
	Date& operator--() {
		return *this -= 1;
	}

	//����--
	Date operator--(int) {
		Date ret = *this;
		//Date ret(*this);
		*this -= 1;
		return ret;
	}

	//+,-����������ܹ��޸Ĳ����������ݣ��� c=a+b a��b��ֵ�ǲ��ܹ��޸ĵ�
	Date operator+(int day) {
		Date ret = *this;
		ret += day;
		return ret;
	}

	Date operator-(int day) {
		Date ret = *this;
		ret -= day;
		return ret;
	}

	bool operator==(const Date& date) {
		return _year == date._year
			&& _month == date._month
			&& _day == date._day;
	}

	bool operator>(const Date& date) {
		if (_year > date._year) {
			return true;
		}
		else if (_yaer == date._year) {
			if (_month > date._month) {
				return true;
			}
			else if (_month == date._month) {
				if (_day > date._day) {
					return true;
				}
			}
		}
		return false;
	}

	//���ڵ���
	bool operator>=(const Date& date) {
		return (*this > date) || (*this == date);
	}

	//С��
	bool operator<(const Date& date) {
		return !(*this >= date);
	}

	bool operator<=(const Date& date) {
		return !(*this > date);
	}

	bool operator!=(const Date& date) {
		return !(*this == date);
	}

	void PrintDate() {//�ȼ���PrintDate��Date* const this��
		cout << _year << " " << _month << " " << _day << endll;
		//�����޸�����
		//this->_year=100;
		//���Ե���const��Ա
		fun();
	}

	//const��Ա�����е�const���ε�Ϊ��һ����������thisָ��
	//const��Ա�����ڲ������޸ĳ�Ա������ֵ
	void PrintDate() const// �ȼ���PrintDate(const Date* const this)
	{
		cout << _year << " " << _month << " " << _day << endl;
		//�����޸�����
		//this ->_year=100;
		//���ܵ��÷�const��Ա��������д��Ȩ�޲��ܱ��Ŵ�
		//++*this��
	}

	void fun()const
	{

	}

	int operator-(Date& date) {
		Date d1(*this);
		Date d2(date);

		//d1-d2
		int num = 0;
		if (d1 > d2) {
			while (d1 > d2) {
				--d1;
				++num;
			}
		}
		else {
			//d1<=d2
			while (d1 < d2) {
				++d1;
				++num;
			}
			return -num;
		}
	}


	/*
	Date operator-(Date& date){

	}
	*/

	//ȡ��ַ��������غ�����operator&
	//һ�㲻��Ҫ��ʽ���壬ֱ����Ĭ�ϵļ���

	Date* operator&()
	{
		//return (Date*)0x1234;
		return this;
	}

	const Date* operator&()const
	{
		//return nullptr;
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& date)
{
	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}



void test()
{
	Date d(2020, 5, 1);
	d.printD();
	d += 20;
	d.printD();
	d += 20;
	Date d2(2020, 12, 6);
	d2.printD();
	d2 += 90;
	d2.printD();
	d2 += 3650;
	d2.printD();
	++d2;
	//ǰ��++
	d2.operator++();
	d2.printD();
	//����++
	d2.operator++(0);
	d2.printD();
	d2++;
	d2.printD(); //�ȼ�d2.operator++(0);
}

void test2()
{
	Date d(2020, 5, 23);
	d.printD();
	cout << "ǰ��++" << endl;
	cout << (++d) << endl;
	d.printD();
	cout << "����++" << endl;
	cout << (d++) << endl;
	d.printD();
}

void test3()
{
	Date d(2020, 5, 24);
	d.printD();
	d -= 30;
	d.printD();
	d -= -30;
	d.printD();
	d -= 3650;
	d.printD();
	d += -3650;
	d.printD();
}

void test4()
{
	Date d1(2020, 5, 25);
	Date d2(2020, 5, 25);
	Date d3(2020, 5, 26);
	Date d4(2020, 5, 23);
	cout << (d1 > d4) << endl;
	cout << (d1 > d4) << endl;
	cout << (d1 < d4) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d3 > d1) << endl;
	cout << (d1 >= d1) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
}

void test5()
{
	Date d1(2020, 5, 25);
	Date d2 = d1 + 3650;
	cout << (d1 - d2) << endl;
	cout << (d2 - d1) << endl;
	Date d3 = d2 + 189;
	cout << (d2 - d3) << endl;
	cout << (d3 - d2) << endl;

}


void test6()
{
	Date d1(2020, 5, 25);
	const Date d2(d1);
	d1.printD(); //��const����(���ɶ���д)���÷�const��Ա������ Ҳ���Ե���const��Ա������ ԭ�򣺶�дȨ��û�б��Ŵ�
	d2.printD(); //const����(ֻ��)����const��Ա����, ���ܵ��÷�const��Ա�����ģ�ԭ�򣺶�дȨ�޲��ܱ��Ŵ�
}

void test7()
{
	Date d1;
	const Date d2;
	Date* pd1 = &d1;   // �ȼ��� d1.operator&();
	const Date* pd2 = &d2;  //�ȼ��� d2.operator&() const;
}

//int main()
//{
//	//test();
//	//test2();
//	//test3();
//
//	//test4();
//	//test5();
//	//test6();
//	test7();
//	return 0;
//}