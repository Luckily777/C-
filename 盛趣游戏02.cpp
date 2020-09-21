//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main() {
//    string str;
//    getline(cin, str);
//    map<char, int> m;
//    if (str.size() == 1) {
//        cout << str << endl;
//        return 0;
//    }
//    int max = 1;
//    string result;
//    for (int i = 0; i < str.size(); i++) {
//        int tmp = 1;
//        string stmp;
//        m.insert({ str[i],1 });
//        stmp += str[i];
//        for (int j = i + 1; j < str.size(); j++) {
//            if (m.find(str[j]) != m.end()) {
//                break;
//            }
//            else {
//                m.insert({ str[j],1 });
//                stmp += str[j];
//                tmp++;
//            }
//        }
//        if (tmp > max) {
//            max = tmp;
//            result.clear();
//            result = stmp;
//            stmp.clear();
//            i -= 1;
//        }
//    }
//    cout << result << endl;
//    return 0;
//}