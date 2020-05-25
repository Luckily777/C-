//拷贝函数
#include <iostream>
using namespace std;

class Date {
public:
	//构造函数
	Date(int y = 1, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}

	//拷贝构造
	//拷贝构造：构造函数一种重载形式，也是在创建对象时自动调用
	//调用场景：用一个已经存在的对象去创建一个新的对象，创建的新对象和当前对象的内容相同
	//类型必须是引用，否则会引发无穷的递归，编译器语法检查，不支持传值类型
	//编译器默认生成的拷贝构造为字节拷贝，浅拷贝（只拷贝对象模型中的内容，不拷贝资源）

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//一般的重载构造
	Date(const Date& d, const Date& d2) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "const Date& d" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};



class String {
public:
	String(const char* str = "luckily") {
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String() {
		if (_str) {
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


Date fun() {
	Date d;
	return d;
}

void Test() {
	Date d;
	Date d2(2020, 4, 1);
	Date& rd = d;

	Date copy1(d);

	Date copy2(Date(2020, 5, 20));//优化，直接调用构造函数创建copy2
		                          //不优化：调用构造创建匿名对象，+ 拷贝构造

	Date copy3(fun());
}

void Teststring() {
	String s("123");
	String copy(s);//拷贝构造
}