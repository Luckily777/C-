//超长正整数相加

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string Addend;
//    string Augend;
//    while (cin >> Addend >> Augend) {
//        int size1 = Addend.size();
//        int size2 = Augend.size();
//        if (size1 < size2) {
//            Addend = string(size2 - size1, '0') + Addend;
//        }
//        else {
//            Augend = string(size1 - size2, '0') + Augend;
//        }
//        int size = Addend.size();
//        string ret = "";
//        int flag = 0;
//        for (int i = size - 1; i >= 0; i--) {
//            int temp = Addend[i] - '0' + Augend[i] - '0' + flag;
//            char c = temp % 10 + '0';
//            ret = c + ret;
//            flag = temp / 10;
//        }
//        if (flag) {
//            ret = '1' + ret;
//        }
//        cout << ret << endl;
//    }
//}
