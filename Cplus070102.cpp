//搜索二叉树 删除

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



	bool erase(const T& val)
	{
		//查找
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_val == val)
				break;
			else if (cur->_val < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		//判断是否找到了需要删除的节点
		if (cur == nullptr)
			return false;
		//删除
		//1. 叶子
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			if (cur == _root)
			{
				//如果是根节点，更新根节点
				_root = nullptr;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			delete cur;
		}
		else if (cur->_left == nullptr)
		{
			//2. 左孩子为空
			if (cur == _root)
			{
				_root = cur->_right;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			delete cur;
		}
		else if (cur->_right == nullptr)
		{
			//3. 右孩子为空
			if (cur == _root)
			{
				_root = cur->_left;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			delete cur;
		}
		else
		{
			// 4.左右孩子都存在
			// a. 找最左或者最右节点
			// 找右子树的最左节点
			Node* leftMostChild = cur->_right;
			Node* parent = cur;
			while (leftMostChild->_left)
			{
				parent = leftMostChild;
				leftMostChild = leftMostChild->_left;
			}

			// b. 值替换
			cur->_val = leftMostChild->_val;

			// c. 删除最左或者最右节点
			if (parent->_left == leftMostChild)
				parent->_left = leftMostChild->_right;
			else
				parent->_right = leftMostChild->_right;
			delete leftMostChild;
		}

		return true;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}
private:
	Node* _root = nullptr;
};