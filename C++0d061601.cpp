//使用双端队列实现栈
#include <deque>
#include <vector>
#include <list>
#include <iostream>
using namespace  std;
template <class T,class Container=deque<T>>
class Stack {
public:
	void push(const T& val) {
		_c.push_back(val);
	}

	void pop() {
		_c.pop_back();
	}

	const T& top() {
		return _c.back();
	}

	size_t size()const {
		return _c.size();
	}

	bool empty()const {
		return _c.empty();
	}

private:
	Container _c;
};


void testSt()
{
	//Stack<int>  st;
	Stack<int, list<int>>  st;
	//Stack<int, vector<int>>  st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}