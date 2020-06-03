#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T>
T add(const T& a, const T& b)
{
	return a + b;
}

template <class T1, class T2>
T2 Add(const T1& a, const T2& b)
{
	return a + b;
}

void test()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	add(a, b);

	add<int>(a, c);

	Add(a, c);

	Add(a, b);
}

int Add(const int& a, const int& b)
{
	return a + b;
}

void test1()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	//普通函数与模板函数共存时，如果普通函数的参数类型可以完全匹配，
	//则执行普通函数，不进行模板函数的实例化
	//直接吃现成的饭
	Add(a, b);

	//普通函数与模板函数共存时，普通函数的参数类型不能完全匹配，
	//但是实例化的函数可以完全匹配参数类型，则进行实例化
	//饭不好吃，重新做
	Add(a, c);

	//普通函数与模板函数共存时，但是指定了需要实例化，则进行实例化
	Add<int>(a, b);
}

//类模板
template <class T1, class T2, class T3>
class Date
{
public:
	Date(T1 year, T2 month, T3 day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void Display();
	/*{
		cout << _year << "-" << _month << "-" << _day << endl;
	}*/
private:
	T1 _year;
	T2 _month;
	T3 _day;
};
//如果在类外定义类模板的成员函数，需要加上泛型的声明
//作用域为 "类名<泛型参数>"
template <class T1, class T2, class T3>
void Date<T1, T2, T3>::Display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

void test2()
{
	//类模板不行进行隐式实例化
	//Date d;
	//类模板
	//类型和类名不同
	//类型：类名<模板实际参数类型>
	Date<int, int, int> d(2020,5, 31);
	d.Display();
}

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

void test4()
{
	string str("0123456789");
	//迭代器的遍历方式
	//迭代器是一个可读可写的接口
	string::iterator it = str.begin();
	while (it != str.end())
	{
		//迭代器解引用
		cout << *it << " ";
		//修改元素内容
		//*it = 'a';
		//迭代器向后移动
		++it;
	}
	cout << endl;

	it = str.begin();
	while (it != str.end())
	{
		//迭代器解引用
		cout << *it << " ";
		//迭代器向后移动
		++it;
	}
	cout << endl;

	cout << "reverse_iterator:" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		//反向迭代器向前移动
		++rit;
	}
	cout << endl;
	cout << "const_iterator:" << endl;
	
	string::const_iterator cit = str.begin();
	//const迭代器建议使用const接口获取：c...()
	string::const_iterator cit2 = str.cbegin();
	while (cit != str.end())
	{
		cout << *cit << " ";
		//const迭代器不支持写操作，其为只读迭代器
		//*cit = '1';
		++cit;
	}
	cout << endl;

	/*vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::iterator vit = vec.begin();
	while (vit != vec.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;*/
}

void printString(const string& str)
{
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		//*it = 'a';
		++it;
	}
	cout << endl;
}

void test5()
{
	string str("0123456789");
	//size: 返回有效字符的个数
	int ret = str.size();
	//length: 返回有效字符的个数
	ret = str.length();
	//capacity: 可以存放的最大有效字符的个数
	ret = str.capacity();
	size_t maxSize = str.max_size();

	//clear: 只清空内容，不改变容量
	str.clear();
	ret = str.size();
	ret = str.capacity();

}

void test6()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();
	//resize(n)
	// 1. 当n > size, 且 n > capacity: 增容(开新的空间 + 拷贝 + 释放原有空间） + 新的位置赋值（如果没有给赋值字符，默认赋值'\0' + 修改size
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	//2. 当 n < size: 只修改size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	//3. 当 n > size, 且 n < capacity: 新的位置赋值（如果没有给赋值字符，默认赋值'\0' + 修改size
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();

}

void test7()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	//reserve: 调整容量，一定不修改size和内容, 
	//如果减小容量，是按需减小，如果要减小的容量小于size,不做任何操作，如果减小的容量大于size，则进行减小的操作
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test8()
{
	string s;
	//容量和实际申请的空间可能不同： 字符串特点：以'\0'结束，需要给'\0'预留空间
	//PJ版string 增容过程： 如果为空字符串对象，初始容量大小为15，第一次增容2倍，后续按照1.5倍增容
	int size = s.size();
	//使用reserve提前开好空间，后续可以节省增容的开销，提高代码效率
	s.reserve(200);
	int cap = s.capacity();
	
	cout << "初始容量：" << cap << endl;
	for (int i = 0; i < 200; ++i)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << cap << endl;
		}
	}
}

void test9()
{
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();
	s.resize(13);
	s.reserve(10);
	size = s.size();
	cap = s.capacity();

	s.shrink_to_fit();
	size = s.size();
	cap = s.capacity();

	s.reserve(10000);
	size = s.size();
	cap = s.capacity();

	s.reserve(15);
	size = s.size();
	cap = s.capacity();
}

void test10()
{
	string str("0123456789");

	//1. 迭代器
	string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//2. operator[]: 可读可写接口，如果越界，非法访问
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.operator[](i) << " ";
		str[i] = 'a';
	}
	cout << endl;
	//operator[]简写
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
	}

	//str[100] = 'c';
	cout << endl;
	//at:可读可写， 但是可读性不强, 如果越界，抛异常
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//str.at(100) = 'c';
	//3. 范围for遍历: 支持读写, 如果需要修改，则接收类型为引用类型
	//   底层通过迭代器实现
	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;

	for (auto& ch : str)
	{
		cout << ch << " ";
		ch = 'X';
	}
	cout << endl;
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