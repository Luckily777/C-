//avlÊ÷

template <class T>
struct AVLNode {
	T _value;
	int _bf;
	AVLNode* _left;
	AVLNode* _right;
	AVLNode* _parent;

	AVLNode(const T& val = T()) {
		:_value(val)
			, _bf(0)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
		{

		}
	}
};

template <class T>
class AVl {
	typedef AVLNode<T> Node;

	bool insert(const T& val) {
		if (_root == nullptr) {
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			parent = cur;
			if (cur->_value == val) {
				return false;
			}
			else if (cur->_value < val) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}

		cur = new Node(val);
		if (parent->_value < val) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}

		cur->_parent = parent;
		while (parent) {
			if (parent->_left == cur) {

			}
		}
	}

private:
	Node* _root;
};
