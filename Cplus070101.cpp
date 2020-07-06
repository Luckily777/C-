//搜索二叉树 插入和查找

#include <iostream>
using namespace std;

template <class T>
struct BSTNode
{
	T _val;
	BSTNode<T>* _left;
	BSTNode<T>* _right;

	BSTNode(const T& val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};


template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;

	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_val == val)
				return cur;
			else if (cur->_val < val)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		return nullptr;
	}

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		//查找插入位置
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val < val)
				cur = cur->_right;
			else
				cur = cur->_left;
		}

		cur = new Node(val);
		//判断放在parent的哪一边
		if (parent->_val < val)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
private:
	Node* _root = nullptr;
};