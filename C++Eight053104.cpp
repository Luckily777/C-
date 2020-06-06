//迭代器接口函数
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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