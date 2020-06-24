
//�����ۼ�

#include <iostream>
using namespace std;

class Date {
public:
    Date(int year, int month, int day)
    {
        if (year > 0 && month > 0 && month < 13 && day>0 && day <= GetMonthDay(year, month)) {
            _year = year;
            _month = month;
            _day = day;
        }
    }
    int GetMonthDay(int year, int month) {
        static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int day = days[month];
        if (month == 2
            && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
            ++day;
        }
        return day;
    }
    Date& operator+=(int day) //�ӵȲ���
    {
        _day += day;
        //�ж������Ƿ����,�����Ҫ��λ
        while (_day > GetMonthDay(_year, _month))
        {
            //��ȥ���µ��������·ݽ�λ
            _day -= GetMonthDay(_year, _month);
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
    int m;
    cin >> m;
    while (m--) {
        int year, month, day;
        int num;
        cin >> year >> month >> day >> num;
        Date date(year, month, day);
        date += num;
        date.PrintfDate();

    }
}