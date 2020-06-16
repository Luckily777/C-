//list双向链表的实现

#include <iostream>
using namespace std;

//List: 双向带头循环链表

template < class T>
struct ListNode
{
	T _value;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_value(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template <class T>
struct ListIterator
{
	typedef	ListNode<T> Node;
	typedef ListIterator<T> Self;

	ListIterator(Node* node)
		:_node(node)
	{}

	//解引用： *iterator --->  获取节点value
	T& operator*()
	{
		return _node->_value;
	}

	// 指针->成员
	T* operator->()
	{
		return &_node->_value;
	}

	// ++: 移动到下一个元素的位置
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}


	Node* _node;
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;

	typedef ListIterator<T> iterator;

	//不能通过添加const修饰符定义const迭代器
	//typedef const ListIterator<T> const_iterator;

	iterator begin()
	{
		//第一个元素的位置
		return iterator(_header->_next);
	}

	iterator end()
	{
		//最后一个元素的下一个位置
		return iterator(_header);
	}

	const_iterator begin() const
	{
		//第一个元素的位置
		return iterator(_header->_next);
	}

	const_iterator end() const
	{
		//最后一个元素的下一个位置
		return iterator(_header);
	}

	List()
		:_header(new Node)
	{
		//构建循环结构
		_header->_next = _header->_prev = _header;
	}

	void pushBack(const T& val)
	{
		Node* cur = new Node(val);

		//链接
		Node* prev = _header->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = _header;
		_header->_prev = cur;
	}

private:
	Node* _header;
};

template <class T>
void printList(const List<T>& lst)
{
	List<T>::const_iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

class B
{
public:
	B(int a = 1, int b = 1)
		:_a(a)
		, _b(b)
	{}
	int _a;
	int _b;
};

void tt()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);

}



void tt2()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);

	List<int>::iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << it.operator*() << " ";
		*it = 10;
		it.operator++();
	}
	cout << endl;

	it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void tt3()
{
	List<B> lst;
	lst.pushBack(B(1, 2));
	lst.pushBack(B(3, 4));
	lst.pushBack(B(5, 6));

	B* pb = new B(7, 8);
	cout << pb->_a << endl;
	cout << pb->_b << endl;
	//cout << *pb << endl;

	List<B>::iterator it = lst.begin();
	while (it != lst.end())
	{
		//cout << *it << " ";
		cout << it->_a << "-" << it->_b << endl;
		cout << it.operator->()->_a << "-" << it.operator->()->_b << endl;
		++it;
	}
}

void tt4()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	printList(lst);
}
int main()
{
	//tt();
	//tt2();
	//tt3();
	tt4();
	return 0;
}