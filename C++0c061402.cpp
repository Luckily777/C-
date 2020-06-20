//栈

include <list>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

void test6()
{
	stack<int>  st;
	st.push(1);
	st.push(2);
	st.push(3);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

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


ostream& operator<<(ostream& cout, const C& c)
{
	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}