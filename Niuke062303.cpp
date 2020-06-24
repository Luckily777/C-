//日期差值

#include <iostream>
using namespace std;
class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)//构造函数
    {
        //在进行一个日期赋值前需要判断日期是否合法
        if (year > 0 && month > 0 && month < 13
            && day > 0 && day <= getMonthDay(year, month))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout << "日期不合法： " << year << "-" << month << "-" << day << endl;
            cout << "重置为默认值： 2000-1-1" << endl;
            _year = 2000;
            _month = 1;
            _day = 1;
        }

    }

    int getMonthDay(int year, int month)//获得当前月份的天数
    {
        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int day = days[month];
        //如果是2月且为闰年，+1
        if (month == 2
            && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
            ++day;
        return day;
    }
    Date& operator-=(int day)//减等操作
    {
        if (day < 0)
            return *this += -day;
        _day -= day;
        //判断_day是否为负值或者0, 退位
        //2020.5.24 - 30 --> 2020.5.-6 --> 月份退位 --> +30 --> 2020.4.24
        while (_day <= 0)
        {
            //月份退位
            --_month;
            //月份是否为负值或者0
            if (_month == 0)
            {
                _month = 12;
                //年份退位
                --_year;
            }
            _day += getMonthDay(_year, _month);
        }
        return *this;
    }


    Date& operator--()//前置减减操作
    {
        return *this -= 1;
    }

    Date& operator+=(int day) //加等操作
    {
        // a += -b  --> a -= b
        if (day < 0)
            return *this -= -day;

        //2020.5.1  + 20  --> 2020.5.21
        //2020.5.21 + 20 --> 2020.5.41 --> 进位 --> -31 -->月份进位 --> 2020.6.10
        //2020.12.6 + 90 --> 2020.12.96 --> 进位 --> -31 -->月份进位 --> 2020.13.65 -->年进位
        // --> 2021.1.65--> --> 进位 --> -31 -->月份进位 --> 2021.2.34 --> --> 进位 --> -28 -->月份进位 --> 2021.3.6
        _day += day;
        //判断日期是否溢出,溢出需要进位
        while (_day > getMonthDay(_year, _month))
        {
            //减去当月的天数，月份进位
            _day -= getMonthDay(_year, _month);
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


    Date& operator++()
    {
        return *this += 1;
        //return (*this).operator+=(1);
        //return *this;
    }

    bool operator>(const Date& date)//大于
    {
        if (_year > date._year)
            return true;
        else if (_year == date._year)
        {
            if (_month > date._month)
                return true;
            else if (_month == date._month)
            {
                if (_day > date._day)
                    return true;
            }
        }
        return false;
    }
    bool operator==(const Date& date)//比较相等
    {
        return _year == date._year
            && _month == date._month
            && _day == date._day;
    }

    bool operator>=(const Date& date)//大于等于
    {
        return (*this > date) || (*this == date);
    }

    bool operator<(const Date& date)
    {
        return !(*this >= date);
    }

    int operator-(Date& date)//两个日期进行相减
    {
        Date d1(*this);
        Date d2(date);
        //d1 - d2
        int num = 1;
        if (d1 > d2)
        {
            while (d1 > d2)
            {
                --d1;
                ++num;
            }
            return num;
        }
        else
        {
            //d1 <= d2
            while (d1 < d2)
            {
                ++d1;
                ++num;
            }
            return num;
        }
    }




private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int date1, date2;
    cin >> date1 >> date2;
    int year1, month1, day1;
    int n = 2;
    while (n--) {
        if (n == 1) {
            day1 = date1 % 100;
        }
        else if (n == 0) {
            month1 = date1 % 100;
        }
        date1 = date1 / 100;
    }
    year1 = date1;
    int year2, month2, day2;
    n = 2;
    while (n--) {
        if (n == 1) {
            day2 = date2 % 100;
        }
        else if (n == 0) {
            month2 = date2 % 100;
        }
        date2 = date2 / 100;
    }
    year2 = date2;
    Date d1(year1, month1, day1);
    Date d2(year2, month2, day2);
    cout << (d1 - d2) << endl;
}
