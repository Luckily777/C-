//IO输入输出流
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

void test5()
{
	//C++语言，对于不同类型的数据，输入输出调用不同的重载函数
	// 调用ostream对象的成员函数operator <<
	cout << "abc" << 1 << 2.0 << endl;
	//调用ostream对象的成员函数operator<<
	cout.operator<<("abc").operator<<(1).operator<<(2.0).operator<<(endl);
	//调用普通函数 operator<<(ostream&, char*)
	operator<<(cout, "abc");
	cout << "abc" << 1 << 2.0 << endl;
	clog << "abc" << 1 << 2.0 << endl;


	int a;
	//调用istream对象的成员函数 operator>>
	cin >> a;
	cin.operator>>(a);

	//C语言，对于不同类型的数据，输入输出调用同一个函数
	printf("%d\n", a);
	scanf("%d", &a);
}

void test6()
{
	//输入文件流对象
	ifstream fin("test.txt");
	if (!fin.is_open())
		cout << "文件打开失败" << endl;
	//文本读： getline, >>
	char str[100];
	//>>: 遇到空格或者换行，结束读入
	/*fin >> str;
	cout << str << endl;
	fin >> str;
	cout << str << endl;*/
	//getline: 默认遇到换行结束或者读完最大字节结束
	char str2[4];
	fin.getline(str2, 3);
	cout << str2 << endl;

}

struct Student
{
	int _age;
	char _name[30];
};

void test7()
{
	//文本读写
	ofstream fout("new.test.txt");
	if (!fout.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//<<
	fout << "123" << "456" << endl;
	fout << "abcd";
	fout.close();

	ifstream fin("new.test.txt");
	if (!fin.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	char str[100];
	fin >> str;
	cout << str << endl;
	fin >> str;
	cout << str << endl;
	fin.close();

}

//二进制读写： 效率高， 可读性差
void writeFile(const char* filename)
{
	ofstream fout(filename);
	if (!fout.is_open())
		return;
	Student st;
	st._age = 20;
	strcpy(st._name, "bitekeji");

	//二进制写
	fout.write((char*)&st, sizeof(Student));
	fout.close();
}

void readFile(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
		return;
	Student st;
	fin.read((char*)&st, sizeof(Student));
	fin.close();
}

//文本读写： 效率低， 可读性好
void writeTxtFile(const char* filename)
{
	ofstream fout(filename);
	if (!fout.is_open())
		return;
	Student st;
	st._age = 20;
	strcpy(st._name, "bitekeji");
	fout << st._age << endl;
	fout << st._name << endl;
	fout.close();
}

void readTxtFile(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
		return;
	Student st;
	fin >> st._age;
	fin >> st._name;
	fin.close();
}

void test8()
{
	writeFile("test.binary.txt");
	readFile("test.binary.txt");

	writeTxtFile("test.text.txt");
	readTxtFile("test.text.txt");
}

void test9()
{
	//错误示范

	writeFile("test.binary.txt");
	readTxtFile("test.binary.txt");

	writeTxtFile("test.text.txt");
	readFile("test.text.txt");
}

void test10()
{
	//atoi

	//itoa: 整数转字符串
	char str[100];
	itoa(100, str, 10);
	itoa(100, str, 16);
	itoa(100, str, 2);
	itoa(100, str, 8);

	sprintf(str, "%d", 100);
	float f = 1.2;
	sprintf(str, "%0.1f", f);

	//把非字符串数据转成字符串形式的数据
	stringstream ss;
	ss << f;
	string ret = ss.str();
	cout << ret << endl;
	int a = 120;
	ss.str("");  //Set
	ss.clear();  //clear: 情况流中的状态位
	ss << "123\n";
	ss << a;
	ret = ss.str();  //Get
	ss >> ret;
	cout << ret << endl;

}
