//����������

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
		//���Ҳ���λ��
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
		//�жϷ���parent����һ��
		if (parent->_val < val)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}

	bool erase(const T& val)
	{
		//����
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
		//�ж��Ƿ��ҵ�����Ҫɾ���Ľڵ�
		if (cur == nullptr)
			return false;
		//ɾ��
		//1. Ҷ��
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			if (cur == _root)
			{
				//����Ǹ��ڵ㣬���¸��ڵ�
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
			//2. ����Ϊ��
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
			//3. �Һ���Ϊ��
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
			// 4.���Һ��Ӷ�����
			// a. ������������ҽڵ�
			// ��������������ڵ�
			Node* leftMostChild = cur->_right;
			Node* parent = cur;
			while (leftMostChild->_left)
			{
				parent = leftMostChild;
				leftMostChild = leftMostChild->_left;
			}

			// b. ֵ�滻
			cur->_val = leftMostChild->_val;

			// c. ɾ������������ҽڵ�
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

	/*
	BSTree<T>& operator=(const BSTree<T>& bst)
	{
		if (this != &bst)
		{
			destory(_root);
			_root = copyTree2(bst._root);
		}
		return *this;
	}
	*/
private:
	Node* _root = nullptr;
};

void test()
{
	BSTree<int> bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(4);
	bst.insert(1);
	bst.insert(2);
	bst.insert(0);
	bst.insert(7);
	bst.insert(6);
	bst.insert(8);
	bst.insert(9);
	bst.insert(8);
	bst.inorder();

	bst.erase(0);
	bst.inorder();
	bst.erase(8);
	bst.inorder();
	bst.erase(3);
	bst.inorder();
	bst.erase(2);
	bst.inorder();
	bst.erase(1);
	bst.inorder();
	bst.erase(4);
	bst.inorder();
	bst.erase(5);
	bst.inorder();

}

void test2()
{
	BSTree<int> bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(4);
	bst.insert(1);
	bst.insert(2);
	bst.insert(0);
	bst.insert(7);
	bst.insert(6);
	bst.insert(8);
	bst.insert(9);
	bst.insert(8);
	bst.inorder();

	BSTree<int> copy(bst);
	bst.inorder();
}

int main()
{
	//test();
	test2();
	return 0;
}