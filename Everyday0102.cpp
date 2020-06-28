#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	getline(cin,str1);
	string str2;
	getline(cin, str2);
	int size1 = str1.length();
	int size2 = str2.length();
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (str1[i] == str2[j]) {
				str1.erase(i, 1);
			}
		}
	}
	cout << str1 << endl;
}