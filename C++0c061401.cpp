
//list的实现
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

template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef	ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	ListIterator(Node* node)
		:_node(node)
	{}

	//解引用： *iterator --->  获取节点value
	Ref operator*()
	{
		return _node->_value;
	}

	// 指针->成员
	Ptr operator->()
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

/*
template <class T>
struct ConstListIterator
{
	typedef	ListNode<T> Node;
	typedef ConstListIterator<T> Self;

	ConstListIterator(Node* node)
		:_node(node)
	{}

	//解引用： *iterator --->  获取节点value
	const T& operator*()
	{
		return _node->_value;
	}

	// 指针->成员
	const T* operator->()
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
*/

template <class T>
class List
{
public:
	typedef ListNode<T> Node;

	typedef ListIterator<T, T&, T*> iterator;

	//不能通过添加const修饰符定义const迭代器
	typedef ListIterator<T, const T&, const T*> const_iterator;

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
		return const_iterator(_header->_next);
	}

	const_iterator end() const
	{
		//最后一个元素的下一个位置
		return const_iterator(_header);
	}

	List()
		:_header(new Node)
	{
		//构建循环结构
		_header->_next = _header->_prev = _header;
	}

	void pushBack(const T& val)
	{
		//Node* cur = new Node(val);

		////链接
		//Node* prev = _header->_prev;

		//prev->_next = cur;
		//cur->_prev = prev;

		//cur->_next = _header;
		//_header->_prev = cur;
		insert(end(), val);
	}

	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}

	void insert(iterator pos, const T& val)
	{
		Node* cur = new Node(val);

		Node* node = pos._node;
		Node* prev = node->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = node;
		node->_prev = cur;
	}

	//删除导致pos迭代器失效
	//返回值： 下一个元素的位置
	iterator erase(iterator pos)
	{
		//不能删除头结点（_header)
		if (pos != end())
		{
			Node* node = pos._node;
			Node* prev = node->_prev;
			Node* next = node->_next;

			delete node;

			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		return pos;
	}

	size_t size() const
	{
		size_t count = 0;
		for (const auto& e : *this)
			++count;
		return count;
	}

	~List()
	{
		if (_header)
		{
			clear();
			delete _header;
			_header = nullptr;
		}
	}

	void clear()
	{
		//清空所有非头结点
		Node* cur = _header->_next;
		while (cur != _header)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		//重新构建循环结构
		_header->_next = _header->_prev = _header;
	}

	List(const List<T>& lst)
		:_header(new Node)
	{
		_header->_next = _header->_prev = _header;
		//深拷贝，插入元素
		for (const auto& e : lst)
			pushBack(e);
	}
	//现代写法
	List<T>& operator=(List<T> lst)
	{
		swap(_header, lst._header);
		return *this;
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
		//*it = T();
		++it;
	}
	cout << endl;
}

template <class T>
void printListFor(const List<T>& lst)
{
	for (const auto& e : lst)
	{
		cout << e << " ";
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

void test()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	printList(lst);
	printListFor(lst);
}

void test2()
{
	List<int> lst;
	lst.insert(lst.begin(), 1);
	printListFor(lst);
	lst.pushBack(2);
	printListFor(lst);
	lst.pushFront(0);
	printListFor(lst);
	List<int>::iterator it = ++lst.begin();
	lst.insert(it, -1);
	printListFor(lst);
	it = lst.erase(it);
	printListFor(lst);
	cout << *it << endl;
}

void test3()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	lst.pushBack(6);
	cout << "size:" << lst.size() << endl;
	printListFor(lst);

	lst.popBack();
	printListFor(lst);
	lst.popFront();
	printListFor(lst);
	lst.popBack();
	printListFor(lst);
	lst.popFront();
	printListFor(lst);
	lst.popBack();
	printListFor(lst);
	lst.popFront();
	printListFor(lst);
	lst.popFront();
	printListFor(lst);
	lst.popBack();
	printListFor(lst);
}

void test4()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	lst.pushBack(6);

	List<int> copy(lst);

	List<int> lst2;
	lst2.pushBack(100);
	lst2 = copy;
}

//int main()
//{
//	//test();
//	//test2();
//	//test3();
//	test4();
//	return 0;
//}