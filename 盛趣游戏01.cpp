//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//bool IsHstring(string str) {
//    int size = str.size() - 1;
//    for (int i = 0; i <= str.size() / 2; i++) {
//        if (str[i] != str[size--]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    string str;
//    getline(cin, str);
//    if (str.size() == 1) {
//        cout << str << endl;
//        return 0;
//    }
//    stack<char> s;
//    int max = 0;
//    string result;
//    for (int i = 0; i < str.size(); i++) {
//        int num = 0;
//        string tmp;
//        for (int j = 1; j < str.size(); j++) {
//            tmp = str.substr(i, j);
//            if (IsHstring(tmp)) {
//                num = tmp.size();
//            }
//            if (num > max) {
//                max = num;
//                result.clear();
//                result = tmp;
//                tmp.clear();
//            }
//        }
//    }
//    cout << result << endl;
//    return 0;
//}