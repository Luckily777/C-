//ÌÔ±¦Íøµê

//#include <iostream>
//#include <vector>
//using namespace std;
//static int money[13] = { 0,62,28,31,60,31,60,31,62,60,62,30,62 };
//static int month[13] = { 0,2,1,1,2,1,2,1,2,2,2,1,2 };
//
//int Getmoney(int year) {
//    int gmoney = 0;
//    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
//        gmoney += 1;
//    }
//    return gmoney;
//}
//
//int main() {
//    int fromyear = 0;
//    int frommonth = 0;
//    int fromday = 0;
//    int endyear = 0;
//    int endmonth = 0;
//    int endday = 0;
//    while (cin >> fromyear >> frommonth >> fromday >> endyear >> endmonth >> endday) {
//        int moneys = 0;
//        if (fromyear == endyear) {
//            if (frommonth == endmonth) {
//                moneys += (endday - fromday + 1) * month[endmonth];
//            }
//            else {
//                while (frommonth < endmonth) {
//                    moneys += money[frommonth] - ((fromday - 1) * month[frommonth]);
//                    if (frommonth == 2) {
//                        moneys += Getmoney(fromyear);
//                    }
//                    frommonth++;
//                    fromday = 1;
//                }
//                moneys += endday * month[frommonth];
//
//            }
//        }
//        else {
//            while (fromyear < endyear) {
//                moneys += money[frommonth] - ((fromday-1) * month[frommonth]);
//                if (frommonth == 2) {
//                    moneys += Getmoney(fromyear);
//                }
//                frommonth++;
//                if (frommonth == 13) {
//                    fromyear++;
//                    frommonth = 1;
//                }
//                fromday = 1;
//            }
//            while (frommonth < endmonth) {
//                moneys += money[frommonth];
//                if (frommonth == 2) {
//                    moneys += Getmoney(fromyear);
//                }
//                frommonth++;
//            }
//            moneys += endday * month[endmonth];
//        }
//        cout << moneys << endl;
//    }
//    return 0;
//}