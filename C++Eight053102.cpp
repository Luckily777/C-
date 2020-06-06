//String的6种定义方式
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test3()
{
	/*
	default (1)
	string();
	copy (2)
	string (const string& str);
	substring (3)
	string (const string& str, size_t pos, size_t len = npos);
	from c-string (4)
	string (const char* s);
	from sequence (5)
	string (const char* s, size_t n);
	fill (6)
	string (size_t n, char c);
	*/
	string str;  //""
	string str2("123");  // "123"
	string str3 = "abc";  // "abc"
	string str4("0123456789", 5); //"01234"
	string cpy(str3);  // "abc"

	string str5(str4, 2, 2);  //"23"
	string str6(10, 'a');  //"aaaaaaaaaa"

	str6 = str5;
	str6 = "111";
	str6 = 'X';

}


int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	test10();
	return 0;
}