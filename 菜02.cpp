//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main() {
//    string str;
//    cin >> str;//没将空格后面的内容读取进来
//    if (str.size() == 0 || (str[0] != '-' && str[0] != '+' && str[0] < '0' && str[0]>'9')) {
//        cout << str << endl;
//        return 0;
//    }
//    int falg = 0;
//    vector<int> result;
//    int b = 0;
//    for (int i = 0; i < str.size(); i++) {
//        if (str[i] == '-' && b == 0) {
//            falg = 1;
//            b = 1;
//        }
//        if (str[i] >= '0' && str[i] <= '9') {
//            result.push_back(str[i] - '0');
//        }
//    }
//    if (falg == 1) {
//        cout << '-';
//    }
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i];
//    }
//    cout << endl;
//    return 0;
//}