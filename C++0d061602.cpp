//使用双端队列实现队列
#include <deque>
#include <vector>
#include <list>
#include <iostream>
using namespace  std;

template <class T,class Container = deque<T>>
class Queue {

public:
	void push(const T& val) {
		_c.push_back();
	}

	void pop() {
		_pop_front();
	}

	T& front() {
		return _c.front();
	}

	T& back() {
		return _c.back();
	}

	size_t size() const{
		return _c.size();
	}

	bool empty()const {
		return _c.empty();
	}
private:
	Container _c;
};

void testQ()
{
	//Queue<int> q;
	Queue<int, list<int>> q;
	//vector不能实现队列
	//Queue<int, vector<int>> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}