//使用双端队列和vector实现优先队列
#include <deque>
#include <vector>
#include <list>
#include <iostream>
using namespace  std;

//仿函数
template <class T>
struct Greater {
	bool operator()(contst T& val1, const T& val2) {
		return val1 > val2;
	}
};

template <class T>
struct Less {
	bool operator()(const T& val1, const T& val2) {
		return val1 < val2;
	}
};

ostream& operator<<(ostream& cout, const Date& d) {
	cout < d._y << "-" << d._m << "-" << d._d << endl;
	return cout;
}

template <class T,class Container=deque<T>,class Compare=Less<T>>
class Priority_Queue {
public:
	void push(const T& val) {
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	void pop() {
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& top() {
		return _c.front();
	}

	size_t size()const {
		return _c.size();
	}

	bool empty()const {
		return _c.empty();
	}

private:
	void shiftDown(int parent) {
		int child = 2 * parent + 1;
		while (child < _c.size()) {
			if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1]) {
				++child;
			}
			if (_cmp(_c[parent],_c[child])){

				swap(_c[parent],_c[child])
					parent=child
					child=2*parent+1;
			}
			else
				break;
		}
	}

	void shiftUp(int child) {
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (_cmp(_c[parent], _c[child])) {
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

private:
	Container _c;
	Compare _cmp;
};




void testPQ()
{
	Priority_Queue<int, vector<int>, Less<int>> pq;
	/*pq.push(10);
	pq.push(1);
	pq.push(12);
	pq.push(50);
	pq.push(5);
	pq.push(100);*/

	int n = 200;
	for (int i = 0; i < n; ++i)
		pq.push(i);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;


}

void testPQ2()
{
	Priority_Queue<int, vector<int>, Less<int>> pq;
	pq.push(10);
	pq.push(1);
	pq.push(12);
	pq.push(50);
	pq.push(5);
	pq.push(100);

	int n = 200;
	for (int i = 0; i < n; ++i)
		pq.push(i);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}




//自定义类型
class Date
{
public:
	Date(int y, int m, int d)
		:_y(y), _m(m), _d(d)
	{}

	bool operator>(const Date& d) const
	{
		if (_y > d._y)
			return true;
		else if (_y == d._y)
		{
			if (_m > d._m)
				return true;
			else if (_m == d._m)
			{
				if (_d > d._d)
					return true;
			}
		}
		return false;
	}

	bool operator<(const Date& d) const
	{
		if (_y < d._y)
			return true;
		else if (_y == d._y)
		{
			if (_m < d._m)
				return true;
			else if (_m == d._m)
			{
				if (_d < d._d)
					return true;
			}
		}
		return false;
	}
public:
	int _y;
	int _m;
	int _d;
};


void testPQ3()
{
	Priority_Queue<Date, deque<Date>, Greater<Date>> pq;
	//list不能实现优先级队列
	//Priority_Queue<Date, list<Date>, Greater<Date>> pq;
	pq.push(Date(2020, 5, 31));
	pq.push(Date(2022, 5, 31));
	pq.push(Date(2008, 5, 31));
	pq.push(Date(2025, 5, 31));
	pq.push(Date(2020, 12, 31));
	pq.push(Date(2020, 5, 3));

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}
