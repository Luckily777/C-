//#include <iostream>
//#include<stdio.h>
//#include<string>
//#include<stack>
//#include<map>
//using namespace std;
//
//int main()
//{
//    string str;
//    cin >> str;
//    stack<int> stk;
//    map<int, int> indexMap;
//    int cnt = 0;
//    for (int i = 0; i < str.length(); ++i) {
//        if (str[i] == '(') {
//            cnt++;
//            stk.push(i);
//        }
//        else if (str[i] == ')') {
//            int n = stk.top();
//            indexMap.insert({ n,i });
//            stk.pop();
//        }
//    }
//    printf("%d\n", cnt);
//    for (auto m : indexMap) {
//        printf("%d\n%d\n", m.first, m.second);
//    }
//    return 0;
//}
