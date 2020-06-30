#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

void t5()
{
	vector<int> v;
	size_t cap = v.capacity();
	v.reserve(100);
	cap = v.capacity();
	v.reserve(10);
	cap = v.capacity();
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


class A
{
public:
	A(int a, int b)
		:_a(a)
	{
		cout << "A(int, int)" << endl;
	}

	bool operator<(const A& a)
	{
		return _a < a._a;
	}

	bool operator>(const A& a)
	{
		return _a > a._a;
	}
private:
	int _a;
};

void t2()
{
	/*list<int> lst;
	lst.push_back(1);
	lst.push_front(0);
	lst.push_front(-1);
	lst.push_front(-2);
	for (const auto& e : lst)
		cout << e << " ";
	cout << endl;

	lst.pop_back();
	printLst(lst);
	lst.pop_front();
	printLst(lst);
*/
	list<A> lst;
	A a(5, 6);


	lst.emplace_back(10, 9);
	lst.emplace_front(-1, 0);
	lst.emplace_back(a);

}

int main() {
	t2();
}