//优先级队列

#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

void test7()
{
	//通过堆实现，默认为大堆
	priority_queue<int>  pq;
	pq.push(10);
	pq.push(1);
	pq.push(15);
	pq.push(20);
	pq.push(2);
	pq.push(4);
	pq.push(19);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

struct C
{
	C(int a = 0, int b = 0, int c = 0)
		:_a(a)
		, _b(b)
		, _c(c)
	{}
	bool operator<(const C& c) const
	{
		return _a < c._a;
	}

	bool operator>(const C& c) const
	{
		return _a > c._a;
	}
	int _a;
	int _b;
	int _c;
};


void test8()
{
	//优先级队列存放自定义类型，自定义类型需要支持大小比较运算
	//建大堆，需要提供小于的比较
	priority_queue<C> pq;
	pq.push(C(1, 1, 1));
	pq.push(C(2, 1, 1));
	pq.push(C(3, 1, 1));
	pq.push(C(4, 1, 1));
	pq.push(C(5, 1, 1));
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}


void test10()
{
	//优先级队列存放自定义类型，自定义类型需要支持大小比较运算
	//建小堆，需要提供可以进行大于比较的仿函数类
	//
	//priority_queue<C, vector<C>, Greater<C>> pq;
	priority_queue<C, vector<C>, Less<C>> pq;
	pq.push(C(1, 1, 1));
	pq.push(C(2, 1, 1));
	pq.push(C(3, 1, 1));
	pq.push(C(4, 1, 1));
	pq.push(C(5, 1, 1));
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}

void test11()
{
	stack<int, vector<int>> st;
	st.push(1);
	stack<int, list<int>> st2;
	st2.push(1);
	stack<int, deque<int>> st3;
	st3.push(1);

	queue<int, list<int>> q;
	q.push(1);
	queue<int, deque<int>> q2;
	q2.push(1);

	priority_queue<int, vector<int>> pq;
	pq.push(1);
	priority_queue<int, deque<int>> pq2;
	pq2.push(1);

	/*queue<int, vector<int>> q3;
	q3.push(1);
	q3.pop();*/

	/*priority_queue<int, list<int>> pq3;
	pq3.push(1);*/
}

int main()
{
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test11();
	return 0;
}