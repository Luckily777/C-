//ËÑË÷¶þ²æÊ÷ ¿½±´£¬Îö¹¹ ¹¹Ôì
 
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

	void destory(Node* root)
	{
		if (root)
		{
			destory(root->_left);
			destory(root->_right);
			delete root;
		}
	}

	~BSTree()
	{
		destory(_root);
	}

	void copyTree(Node* root)
	{
		if (root)
		{
			insert(root->_val);
			copyTree(root->_left);
			copyTree(root->_right);
		}
	}

	Node* copyTree2(Node* root)
	{
		if (root)
		{
			Node* cur = new Node(root->_val);
			cur->_left = copyTree2(root->_left);
			cur->_right = copyTree2(root->_right);
			return cur;
		}
		return nullptr;
	}

	BSTree()
		:_root(nullptr)
	{}

	BSTree(const BSTree<T>& bst)
		:_root(nullptr)
	{
		_root = copyTree2(bst._root);
	}

	BSTree<T>& operator=(BSTree<T> bst)
	{
		swap(_root, bst._root);
		return *this;
	}

private:
	Node* _root = nullptr;
};