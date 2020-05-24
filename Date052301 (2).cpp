#include <iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};
//class Date
//{
//public:
//	Date(int y = 1, int m = 1, int d = 1)
//	{
//		_year = y;
//		_month = m;
//		_day = d;
//	}
//	//拷贝构造： 构造函数一种重载形式，也是在创建对象时自动调用
//	//调用场景： 用一个已经存在的对象去创建一个新的对象， 创建的新对象和当前对象的内容相同
//	//类型必须是引用，否则会引发无穷递归，编译器语法检查，不支持传值类型
//	//编译器默认生成的拷贝构造为字节拷贝，浅拷贝(只拷贝对象模型中的内容，不拷贝资源)
//	
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "const Date& d" << endl;
//	}
//	
//	//一般的重载构造
//	Date(const Date& d, const Date& d2)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d2._day;
//		cout << "const Date& d" << endl;
//	}
//	//析构函数： 清理资源，不是销毁对象，在对象生命周期结束时，编译器自动调用
//	//如果没有资源需要清理，可以不用显式写析构函数，直接使用编译器默认生成的析构函数
//
//	~Date()
//	{
//		//自动调用自定义类型的析构函数，完成自定义类型成员的资源清理工作
//		cout << "~Date()" << endl;
//	}
//	
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	//A _a;
//};

//class String
//{
//public:
//	String(const char* str = "bite")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	//如果有资源，必须显式定义拷贝构造，完成深拷贝
//
//	~String()
//	{
//		if (_str)
//		{
//			free(_str);
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//Date fun()
//{
//	Date d;
//	return d;
//}
//
//void test1()
//{
//	Date d;
//	Date d2(2020, 4, 1);
//	Date& rd = d;
//
//	Date copy(d);
//
//	Date copy2(Date(2020, 5, 20));  //优化： 直接调用构造函数创建copy2, 不优化：调用构造创建匿名对象，+ 拷贝构造
//	
//	Date copy3(fun());
//}
//
//void test2()
//{
//	const volatile int a = 10;
//	int* pa = (int*)&a;
//	*pa = 20;
//	cout << a << endl;
//	cout << *pa << endl;
//}
//
//void test3()
//{
//	String s("123");
//	String copy(s);  //拷贝构造
//
//}

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}
	
	bool isEqual(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	//运算符重载函数：增强代码的可读性
	//函数名特殊，定义和使用方式和普通函数一样
	//返回值 operator + 需要重载的运算符 (参数列表) {}
	///运算符重载函数如果是成员函数，则参数的个数比运算符需要的个数少一个，这里编译器会传入this指针作为第一个参数
	// this指针始终占用运算符操作数的第一个位置
	bool operator==(const Date& d) //底层接口： bool operator==(Date* const this, const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	// 赋值：d = d2
	// 赋值运算符重载函数: 修改已经存在的对象的内容， 不是去创建新的对象
	// 如果不写，编译器也会默认生成，默认生成的也是字节拷贝，即浅拷贝
	// 如果当前类中有资源，则必须显式定义赋值运算符重载函数，完成深拷贝
	Date& operator=(const Date& d2)
	{
		//判断是否给自己赋值
		if (this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		
		cout << "operator=(const Date& d2)" << endl;
		//返回当前调用此函数的对象本身
		return *this;
	}
	
//private:
	int _year;
	int _month;
	int _day;
};

//普通的运算符重载函数，参数的个数和运算符需要的个数一致
//bool operator==(const Date& d1, const Date& d)
//{
//	return d1._year == d._year
//		&& d1._month == d._month
//		&& d1._day == d._day;
//}
//输出运算符重载函数
//ostream& operator<<(ostream& _cout, const Date& date)
//{
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}



void test4()
{
	Date d(2020, 1, 1);
	Date d2(d);

	Date d3(2020, 5, 23);
	cout << d.isEqual(d2) << endl;
	cout << d.isEqual(d3) << endl;
	cout << (d == d2) << endl;  //等价于 d.operator==(d2);
	cout << d.operator==(d2) << endl;
	cout << (d == d3) << endl;  //等价于 d.operator==(d3);
	cout << d.operator==(d3) << endl;
	//cout << d << endl;
}

void test5()
{
	Date d(2020, 5, 22);
	Date d2(2019, 1, 1);
	// =调用：如果对象都存在，调用赋值运算符重载函数， 如果左边对象不存在，调用拷贝构造
	d2 = d; //赋值运算符重载函数
	d2.operator=(d);//同上等价
	d2 = d2;
	Date d3(2018, 10, 1);
	//连续赋值：从右向左赋值
	d = d2 = d3;
	d.operator=(d2.operator=(d3));  //同上等价
	Date d4 = d3;  //调用拷贝构造：d4不存在，用d3创建d4对象，所以调用构造，不是赋值运算符
}
//int main()
//{
//	//test1();
//	////test2();
//	//test3();
//	//test4();
//	test5();
//	return 0;
//}