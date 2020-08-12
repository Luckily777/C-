//二叉搜索树的实现


template <class T>
struct BtsNode {
	T _val;
	BtsNode<T>* _left;
	BtsNode<T>* _right;

	BtsNode(const T& val = T())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{

	}

};

template <class T>
class BSTree {
public:
	typedef BtsNode<T> Node;

	Node* find(const T& val) {
		Node* cur = _root;
		while (cur) {
			if (cur->_val == val) {
				return cur;
			}
			else if (cur->_val < val) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}
		return nullptr;
	}


	bool insert(const T& val) {
		if (_root == nullprt) {
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			parent = cur;
			if (cur->_val == val) {
				return false;
			}
			else if (cur->_val < val) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}

		cur = new Node(val);
		if (parent->_val < val) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		return true;
	}


	bool earse(const T& val) {
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (cur->_val == val) {
				break;
			}
			parent = cur;
			else if (cur->_val < val) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}

		if (cur == nullptr) {
			return false;
		}

		if (cur->_left == nullptr && cur->_right == nullptr) {
			if (cur == _root) {
				_root = nullptr;
			}
			else {
				if (parent->_left == cur) {
					parent->_left = nullptr;
				}
				else {
					parent->_right = nullptr;
				}
			}
			delete cur;
		}
		else if (cur->_left == nullptr) {
			if (cur == _root) {
				_root = cur->_right;
			}
			else {
				if (parent->_left == cur) {
					parent->_left = cur->_right;
				}
				else {
					parent->_right = cur->_right;
				}
			}
			delete cur;
		}
		else if (cur->_right == nullptr) {
			if (cur == _root) {
				_root = cur->_left;
			}
			else {
				if (parent->_left == cur) {
					parent->_left = cur->_left;
				}
				else {
					parent->_right = cur->_left;
				}
			}
			delete cur;
		}

		else {
			Node* leftMostchild = cur->_right;
			Node* parent = cur;
			while (leftMostchild->_left) {
				parent = leftMostchild;
				leftMostchild = leftMostchild->_left;
			}
			cur->_val = leftMostchild->_val;

			if (parent->left == leftMostchild) {
				parent->_left = leftMostchild->_right;
			}
			else {
				parent->_right = leftMostchild->_right;
			}
			delete leftMostchild;
		}
		return true;
	}
private:
	Node* _root=nullptr;
};