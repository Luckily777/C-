//删除公共字符

//1. 暴力输出
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	getline(cin, str1);
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
	return 0;
}


//2. 哈希映射思想
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);
	int hashtable[256] = { 0 };//采用哈希映射
	for (size_t i = 0; i < str2.length(); i++) {
		hashtable[str2[i]]++;//将第二个字符串中存在的字符全部映射到相对应的位置中去
	}
	string ret;//设置新字符串
	for (size_t i = 0; i < str1.length(); i++) {
		if (hashtable[str1[i]] == 0) {//从哈希表中找对应的值，若存在即值等于1，不存在即等于0
			ret += str1[i];//若等于0则追加在ret字符中后
		}
	}
	cout << ret << endl;
	return 0;
}