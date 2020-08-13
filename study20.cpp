
//map和set的红黑树实现

template <class V>
struct RBiterator {
	typedef RBNode<V> node;
	typedef RBiterator<V> Self;

	Node* _node;
	RBiterator(Node* node) 
		:_node(node)
	{

	}

	V& operator*() {
		return _node->_value;
	}

	V* operator->() {
		return &_node->_value;
	}

	V* operator!=(const Self& if) {
		return _node != it._node;
	}

	bool operator==(const Self& it) {
		return _node == it._node;
	}

	Self& operator++() {
		if (_node->_right) {
			_node = _node->_right;
			while (_node->_left) {
				_node = _node->_left;
			}
		}
		else {
			Node* parent = _node->_parent;
			while (_node == parent->_right) {
				_node = parent;
				parent = parent->_parent;
			}

			if (_node->_right != parent) {
				_node = parent;
			}
		}
		return *this;
	}
};