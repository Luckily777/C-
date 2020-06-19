//�������ʵ��

#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& date);
	Date(int year = 1, int month = 1, int day = 1) {//���캯��
		if (year > 0 && month > 0 && month < 13 && day>0 && day <= getMonthDay(year, month)) {
			//�ж�����Ҫ��ֵ�������Ƿ�Ϸ�
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "����������ڲ��Ϸ���" << year << "-" << month << "-" << day << endl;
			cout << "���ڽ��������ã�1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	int getMonthDay(int year, int month) {
		//��ȡ���µ�����
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
			//�ж���������µĻ������1��
			++day;
		}
		return day;

	}

	Date& operator+=(int day) {
		//�ӵȲ��� a+=b
		if (day < 0) 
			return *this-=-day;
		_day += day;
		//�ж������Ƿ�������������Ҫ��λ
		while (_day > getMonthDay(_year, _month)) {
			//��ȥ���µ��·ݣ� ֮���λ
			_day -= getMonthDay(_year, _month);
			++_month;
			if (_month == 13) {
				//�����λ���·ݵ���13�����һ����ݼ�1
				_month -= 1;
				_year++;
			}
		}
		return *this;
	}

	Date& operator++() {
		//ǰ��++ 
		return *this += 1;
	}

	Date operator++(int) {
		//����++ ����++֮ǰ��ֵ
		Date ret(*this);
		//���¿�����������ԭ�ȵ�ֵ
		*this += 1;
		return ret;
	}

	Date& operator-=(int day) {
		if (day < 0) {
			//��������dayС��0����ת���
			return *this += -day;
		}
		_day = day;
		while (_day <= 0) {
			//����ȥ������С�ڵ������������·ݼ�һ
			--_month;
			if (_month == 0) {
				//���·ݵ���0�������¶����иı�
				_month = 12;
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
		return *this;
	}

	Date& operator--(){
		//ǰ��--
		return *this -= 1;
	}

	Date operator--(int) {
		//����-- ����--֮ǰ��ֵ
		Date ret = *this;
		*this -= 1;
		return ret;
	}

	Date operator+(int day) {
		//����һ������
		Date ret = *this;
		ret += day;
		return ret;
	}

	Date operator-(int day) {
		//��ȥһ������
		Date ret = *this;
		ret -= day;
		return ret;
	}

	bool operator==(const Date& date) {
		//�ж���Ȳ���
		return _year == date._year && _month == date._month && _day == date._day;
	}

	bool operator>(const Date& date) {
		//�жϴ��ڲ���
		if (_year > date._year) {
			return true;
			//���ж����
		}
		else if (_year == date._year) {
			//�������ȵ�����£��ж��·�
			if (_month > date._month) {
				return true;
			}
			else if (_month == date._month) {
				//���·���ȵ�����£��ж�����
				if (_day > date._day) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator>=(const Date& date) {
		//���ڵ��ڣ�����ڻ��ߵ��� ��������һ����������
		return (*this > date) || (*this == date);
	}

	bool operator<(const Date& date) {
		//ֻҪ�����ڵ��ڼ���С��
		return !(*this >= date);
	}

	bool operator<=(const Date& date) {
		//�����ڼ�С�ڵ���
		return !(*this > date);
	}

	bool operator!=(const Date& date) {
		//ֻҪ������
		return !(*this == date);
	}

	void PrintDate() {
		//��ӡ����
		cout << _year << " " << _month << " " << _day << endl;
	}

	void PfrintDate()const {
		cout << _year << " " << _month << " " << _day << endl;
	}

	int operator-(Date& date) {
		//�����������
		Date d1(*this);
		Date d2(date);

		int num = 0;
		if (d1 > d2) {
			while (d1 > d2) {
				--d1;
				++num;
			}
			return num;
		}
		else {
			while (d1 < d2) {
				++d1;
				++num;
			}
			return -num;
		}
	}

	Date* operator&() {
		//ȡ��ַ
		return this;
	}

	const Date* operator&()const {
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& date) {
	_cout << date._year << " " << date._month << " " << date._day << endl;
	return _cout;
}