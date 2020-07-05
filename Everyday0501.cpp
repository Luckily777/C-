//统计回文

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    int size = str1.size();
    int count = 0;
    string str3(str1);
    for (int i = 0; i <= size; i++) {
        str1.assign(str3);
        str1.insert(i, str2);
        int size1 = str1.size();
        int j = 0, flag = 1;
        while ((j < size1) && (flag)) {
            if (str1[j] != str1[size1-1]) {
                flag = 0;
            }
            j++;
            size1--;
        }
        if (j >= size1) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}






























//#include <stdio.h>
//
//int main() {
//	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//}