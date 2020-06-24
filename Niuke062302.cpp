//打印日期


#include <iostream>
using namespace std;

class Date {
public:
    Date(int year = 0, int month = 1, int day = 0) {
        if (year > 0 && year <= 3000) {
            _year = year;
            _month = month;
            _day = day;
        }
    }

    int GetMonthDay(int year, int month) {
        static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int day = days[month];
        if (month == 2
            && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
            ++day;
        return day;
    }

    Date& operator+=(int day) {
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            //减去当月的天数，月份进位
            _day -= GetMonthDay(_year, _month);
            ++_month;
            //判断月份是否溢出
            if (_month == 13)
            {
                //进位到下一年的1月
                _month = 1;
                _year++;
            }
        }
        return *this;
    }

    void PrintfDate() {
        if (_month >= 10) {
            if (_day >= 10) {
                cout << _year << "-" << _month << "-" << _day << endl;
            }
            else {
                cout << _year << "-" << _month << "-" << 0 << _day << endl;
            }
        }
        else {
            if (_day >= 10) {
                cout << _year << "-" << 0 << _month << "-" << _day << endl;
            }
            else {
                cout << _year << "-" << 0 << _month << "-" << 0 << _day << endl;
            }
        }
    }
private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int year, num;
    cin >> year >> num;
    Date date(year);
    date += num;
    date.PrintfDate();
}