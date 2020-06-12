//vector的接口功能
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void t1()
{
	vector<int> v;
	vector<char> v2;
	vector<string> v3;

	vector<int> v4(10, 5);

	string s2 = "0123456789";
	vector<char> v5(s2.begin(), s2.end());

	vector<char> v6(v5);
}

void t2()
{
	string s = "0123456789";
	vector<char> v(s.begin(), s.end());

	cout << "reverse_iterator" << endl;
	vector<char>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<char>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		*it = 'a';
		++it;
	}
	cout << endl;

	for (char& ch : v)
	{
		cout << ch << " ";
		ch = 'b';
	}
	cout << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
		v[i] = 'c';
	}
	cout << endl;

	for (char& ch : v)
	{
		cout << ch << " ";
	}
	cout << endl;
}
template <class T>
void printVec(const vector<T>& v)
{
	vector<T>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << "reverse_iterator" << endl;
	vector<T>::const_reverse_iterator rit = v.crbegin();
	while (rit != v.crend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void t3()
{
	/*
	template <class InputIterator>
	vector (InputIterator first, InputIterator last);
	*/
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> v(a, a + 10);
	char a2[] = "1234567890";
	vector<char> v2(a2, a2 + 10);
	string a3[5] = { "123", "456", "789", "abc", "def" };
	vector<string> v3(a3, a3 + 5);
	printVec(v);
	printVec(v2);
	printVec(v3);

	v.resize(15);
	v2.resize(15);
	v3.resize(15);
}

void t4()
{

	vector<int> v;
	size_t sz = v.size();
	size_t cap = v.capacity();
	cout << cap << endl;
	for (int i = 0; i < 200; ++i)
	{
		v.push_back(i);
		if (cap != v.capacity())
		{
			cap = v.capacity();
			cout << cap << endl;
		}
	}
}

void t5()
{
	vector<int> v;
	size_t cap = v.capacity();
	v.reserve(100);
	cap = v.capacity();
	v.reserve(10);
	cap = v.capacity();
}

void t6()
{
	vector<int> v;
	//operator[]越界，调试版本产生断言错误
	//int ret = v[0];
	//at越界：抛异常
	//int ret2 = v.at(0);
}

void t7()
{
	vector<int> v;
	v.insert(v.begin(), 1);  // 1
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;  // 1
	it = v.insert(it, 0);
	cout << *it << endl;
	//v.insert(it, 5, 0); // 000001
	////迭代器失效：
	//cout << *it << endl;  // 0 ?
	//int a[] = { 1, 2, 3, 4, 5 };
	//v.insert(it, a + 1, a + 3);  //23000001
	//cout << *it << endl;  // 2 ?

	/*v.resize(2);
	cout << *it << endl;*/

	/*v.reserve(2);
	cout << *it << endl;*/

	/*v.push_back(2);
	cout << *it << endl;*/

	/*v.erase(it);
	cout << *it << endl;*/

	//it = v.end() - 1;
	/*it = v.erase(it);
	cout << *it << endl;*/

}

void t8()
{
	vector<int> v;
	v.insert(v.begin(), 10, 5);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);
	}
}

void t9()
{
	vector<int> v(5, 2);
	vector<int> v2(5, 1);
	swap(v, v2);  //内部调用vector的成员函数swap完成
	v.swap(v2);
}

class B
{
public:
	B(int a, int b)
		:_a(a)
		, _b(b)
	{}
private:
	int _a;
	int _b;
};


void t10()
{
	vector<B> v;
	B b(1, 2);
	v.insert(v.begin(), b);  //插入
	v.emplace(v.begin(), 3, 4); // 构造 + 插入
	B b2(5, 6);
	v.emplace(v.begin(), b2);

	v.push_back(b2);
	v.emplace_back(b);
	v.emplace_back(7, 8);  //构造 + 尾插

}

int main()
{
	//t1();
	//t2();
	//t3();
	//t4();
	//t5();
	//t6();
	//t7();
	//t8();
	t10();
	return 0;
}