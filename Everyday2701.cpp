//不用加减乘除的加法
//#include <iostream>
//using namespace std;
//
//
//class Solution {
//public:
//    int Add(int num1, int num2)
//    {
//        if (num2 == 0) {
//            return num1;
//        }
//        else {
//            return Add(num1 ^ num2, (num1 & num2) << 1);
//        }
//    }
//};
//
//
//
//class Solution {
//public:
//    int Add(int num1, int num2)
//    {
//        if (num1 > 0) {
//            while (num1-- != 0)
//                num2++;
//        }
//        else if (num1 < 0) {
//            while (num1++ != 0)
//                num2--;
//        }
//        return num2;
//    }
//};
//
//int main() {
//    Solution s;
//    cout<<s.Add(2, 2)<<endl;
//}