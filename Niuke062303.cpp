//���ڲ�ֵ

#include <iostream>
using namespace std;
class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)//���캯��
    {
        //�ڽ���һ�����ڸ�ֵǰ��Ҫ�ж������Ƿ�Ϸ�
        if (year > 0 && month > 0 && month < 13
            && day > 0 && day <= getMonthDay(year, month))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout << "���ڲ��Ϸ��� " << year << "-" << month << "-" << day << endl;
            cout << "����ΪĬ��ֵ�� 2000-1-1" << endl;
            _year = 2000;
            _month = 1;
            _day = 1;
        }

    }

    int getMonthDay(int year, int month)//��õ�ǰ�·ݵ�����
    {
        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int day = days[month];
        //�����2����Ϊ���꣬+1
        if (month == 2
            && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
            ++day;
        return day;
    }
    Date& operator-=(int day)//���Ȳ���
    {
        if (day < 0)
            return *this += -day;
        _day -= day;
        //�ж�_day�Ƿ�Ϊ��ֵ����0, ��λ
        //2020.5.24 - 30 --> 2020.5.-6 --> �·���λ --> +30 --> 2020.4.24
        while (_day <= 0)
        {
            //�·���λ
            --_month;
            //�·��Ƿ�Ϊ��ֵ����0
            if (_month == 0)
            {
                _month = 12;
                //�����λ
                --_year;
            }
            _day += getMonthDay(_year, _month);
        }
        return *this;
    }


    Date& operator--()//ǰ�ü�������
    {
        return *this -= 1;
    }

    Date& operator+=(int day) //�ӵȲ���
    {
        // a += -b  --> a -= b
        if (day < 0)
            return *this -= -day;

        //2020.5.1  + 20  --> 2020.5.21
        //2020.5.21 + 20 --> 2020.5.41 --> ��λ --> -31 -->�·ݽ�λ --> 2020.6.10
        //2020.12.6 + 90 --> 2020.12.96 --> ��λ --> -31 -->�·ݽ�λ --> 2020.13.65 -->���λ
        // --> 2021.1.65--> --> ��λ --> -31 -->�·ݽ�λ --> 2021.2.34 --> --> ��λ --> -28 -->�·ݽ�λ --> 2021.3.6
        _day += day;
        //�ж������Ƿ����,�����Ҫ��λ
        while (_day > getMonthDay(_year, _month))
        {
            //��ȥ���µ��������·ݽ�λ
            _day -= getMonthDay(_year, _month);
            ++_month;
            //�ж��·��Ƿ����
            if (_month == 13)
            {
                //��λ����һ���1��
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

    bool operator>(const Date& date)//����
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
    bool operator==(const Date& date)//�Ƚ����
    {
        return _year == date._year
            && _month == date._month
            && _day == date._day;
    }

    bool operator>=(const Date& date)//���ڵ���
    {
        return (*this > date) || (*this == date);
    }

    bool operator<(const Date& date)
    {
        return !(*this >= date);
    }

    int operator-(Date& date)//�������ڽ������
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
