//日期类的实现

#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& date);
	Date(int year = 1, int month = 1, int day = 1) {//构造函数
		if (year > 0 && month > 0 && month < 13 && day>0 && day <= getMonthDay(year, month)) {
			//判断所需要赋值的日期是否合法
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "所输入的日期不合法！" << year << "-" << month << "-" << day << endl;
			cout << "日期将进行重置：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	int getMonthDay(int year, int month) {
		//获取当月的天数
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
			//判断如果是闰月的话，则加1天
			++day;
		}
		return day;

	}

	Date& operator+=(int day) {
		//加等操作 a+=b
		if (day < 0) 
			return *this-=-day;
		_day += day;
		//判断日期是否溢出，溢出则需要进位
		while (_day > getMonthDay(_year, _month)) {
			//减去当月得月份， 之后进位
			_day -= getMonthDay(_year, _month);
			++_month;
			if (_month == 13) {
				//如果进位后月份等于13，则减一，年份加1
				_month -= 1;
				_year++;
			}
		}
		return *this;
	}

	Date& operator++() {
		//前置++ 
		return *this += 1;
	}

	Date operator++(int) {
		//后置++ 返回++之前的值
		Date ret(*this);
		//重新开变量，保存原先的值
		*this += 1;
		return ret;
	}

	Date& operator-=(int day) {
		if (day < 0) {
			//若所减的day小于0，则转向加
			return *this += -day;
		}
		_day = day;
		while (_day <= 0) {
			//若减去的天数小于当月天数，则月份减一
			--_month;
			if (_month == 0) {
				//若月份等于0，则年月都进行改变
				_month = 12;
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
		return *this;
	}

	Date& operator--(){
		//前置--
		return *this -= 1;
	}

	Date operator--(int) {
		//后置-- 返回--之前的值
		Date ret = *this;
		*this -= 1;
		return ret;
	}

	Date operator+(int day) {
		//加上一个天数
		Date ret = *this;
		ret += day;
		return ret;
	}

	Date operator-(int day) {
		//减去一个天数
		Date ret = *this;
		ret -= day;
		return ret;
	}

	bool operator==(const Date& date) {
		//判断相等操作
		return _year == date._year && _month == date._month && _day == date._day;
	}

	bool operator>(const Date& date) {
		//判断大于操作
		if (_year > date._year) {
			return true;
			//先判断年份
		}
		else if (_year == date._year) {
			//在年份相等的情况下，判断月份
			if (_month > date._month) {
				return true;
			}
			else if (_month == date._month) {
				//在月份相等的情况下，判断天数
				if (_day > date._day) {
					return true;
				}
			}
		}
		return false;
	}

	bool operator>=(const Date& date) {
		//大于等于，则大于或者等于 两者任意一个成立即可
		return (*this > date) || (*this == date);
	}

	bool operator<(const Date& date) {
		//只要不大于等于即是小于
		return !(*this >= date);
	}

	bool operator<=(const Date& date) {
		//不大于及小于等于
		return !(*this > date);
	}

	bool operator!=(const Date& date) {
		//只要不等于
		return !(*this == date);
	}

	void PrintDate() {
		//打印函数
		cout << _year << " " << _month << " " << _day << endl;
	}

	void PfrintDate()const {
		cout << _year << " " << _month << " " << _day << endl;
	}

	int operator-(Date& date) {
		//两个日期相减
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
		//取地址
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