//#include <iostream>
//using namespace std;
//static int Month[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//
//int main() {
//    int year, month, day;
//    int nums = 0;
//    while (cin >> year >> month >> day) {
//        nums += Month[month - 1] + day;
//        if (month > 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) {
//            nums += 1;
//        }
//        cout << nums << endl;
//    }
//    return 0;
//}