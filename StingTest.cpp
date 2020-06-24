#include <string>
#include <iostream>
using namespace std;

void test() {
	string s;
	s.push_back('a');
	s.append(2, 'b');
	s.append("cde");

	string s2;
	s2.append(s);

	string s3;
	s3.append(s, 3, 2);

	char strArr[] = "1234";
	s3.append(strArr, strArr + 2);  //cd12

	s3.append(s2.begin(), s2.end()); // cd12abbcde

	string s4;
	//operator+=使用的最多
	s4 += '1';    // 1
	s4 += "234";  // 1234
	s4 += s;   //1234abbcde


	s4.insert(0, s3);
	s4.insert(0, s3, 7, 3);
	s4.insert(s4.end(), 3, '1');
	s4.insert(s4.end(), strArr + 1, strArr + 3);

	s4.assign("11111");  // 11111
	s4 = "11111";

	s4.erase(0, 2); // 111
	s4.erase(s4.begin()); //11
	s4.erase(s4.end());
	s4.erase(s4.begin(), s4.end());
}


void test2() {
	string file1 = "test.tar.gz.zip";
	size_t pos = file1.rfind('.');
	//substr(pos, len):  如果len大于从pos到结束位置的字符串长度，则把剩余字符串全部截取出来
	string str2 = file1.substr(pos + 1, file1.size() - pos - 1);
	string str3 = file1.substr(pos + 1);
	pos = string::npos;
}


void test3() {
	string s = "9";
	string s2 = "123";
	string s3 = "1234";
	bool ret = s > s2;
	ret = s2 > s3;
	ret = s > s3;
}

void test4() {
	string s;
	//cin >> s;

	getline(cin, s);
	cout << s;
	getline(cin, s, ',');
	getline(cin, s, ',');
	getline(cin, s, ',');
}
int main() {
	//test();
	//test2();
	//test3();
	test4();
	return 0;
}