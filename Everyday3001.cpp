//美国节日

//#include <iostream>
//using namespace std;
//
//int GetDay(int year) {
//    int Daynums = 0;
//    while (year >= 2000) {
//        int y = 365;
//        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
//            y += 1;
//        }
//        Daynums += y;
//        year--;
//    }
//    return Daynums;
//}
//
//int Runyear(int year) {
//    int days = 28;
//    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
//        days += 1;
//    }
//    return days;
//}
//
//int main() {
//    int year;
//    while (cin >> year) {
//        int Days = GetDay(year - 1);
//        int flag = ((Days + 6) % 7);
//        int days = 1;
//        cout << year << '-' << 0 << 1 << '-' << 0 << 1 << endl;
//        days = 15 +(7 - flag)%7 +1;
//        cout << year << '-' << 0 << 1 << '-' << days << endl;
//        flag = (flag + 31) % 7;
//        days = 15 + (7 - flag) % 7 + 1;
//        cout << year << '-' << 0 << 2 << '-' << days << endl;
//        int day = Runyear(year);
//        flag = (flag + day + 31 + 30 + 31) % 7;
//        days = 32 -7 +((7 - flag)%7+1);
//        cout << year << '-' << 0 << 5 << '-' << days << endl;
//        cout << year << '-' << 0 << 7 << '-' << 0 << 4 << endl;
//        flag = (flag + 30 + 31 + 31) % 7;
//        days = 8-((7 - flag)%7 + 1);
//        cout << year << '-' << 0 << 9 << '-' << 0 << days << endl;
//        flag = (flag + 30 + 31) % 7;
//        days = 25 + (7 - flag)%7 + 1;
//        cout << year << '-' << 11 << '-' << days << endl;
//        cout << year << '-' << 12 << '-' << 25 << endl;
//    }
//    return 0;
//}