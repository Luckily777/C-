//红黑树


enum color {
	Black,
	Red
};

template <class K, class V>
struct RBNode {
	pair<K, V> _value;
	color _color;
	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;

	RBNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		, _color(Red)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{

	}
};


Node* leftMost() {
	Node* cur = _header->_parent;
	while (cur&&cur->_left) {
		cur = cur->_left;
	}
	return cur;
}


Node* rightMost() {
	Node* cur = _header->_parent;
	while (cur && cur->_right) {
		cur = cur->_right;
	}
	return cur;
}

bool insert(const pair<K, V>& val) {
	if (_header->_parent == nullptr) {
		Node* root = new Node(val);
		root->_color = Black;
		_header->_parent = root;
		root->_parent = _header;
		_header->_left = root;
		_header->_right = root;
	}

	Node* cur = _header_->parent;
	Node* parent = nullptr;
	while (cur) {
		parent = cur;
		if (cur->_value.first == val.first) {
			return false;
		}
		if (cur->value.first < val.first) {
			cur = cur->_right;
		}
		else {
			cur = cur->_left;
		}
	}

	cur = new Node(val);
	if (parent->_value.firse < val.first) {
		parent->_right = cur;
	}
	else {
		parent->left = cur;
	}
	cur->parent = parent;

	//调整颜色转换
	while (cur != _header->_parent && cur->_parent->_color == Red) {
		Node* p = cur->_parent;
		Node* g = p->_parent;
		if (g->_left == p) {
			Node* u = g->_right;
			if (u && u->_color == Red) {
				u->_color = p->_color = Black;
				g->_color = Red;
				cur = g;
			}
			else {
				if (cur == p->_right) {
					RotateL(p);
					Swap(cur, p);
				}

				RotateR(g);
				p->_color = Black;
				g->_color = Red;

				break;
			}
		}
		else {
			Node* u = g->_left;
			if (u && u->_color == Red) {
				u->_color = p->_color = Black;
				g->_color = Red;
				cur = g;
			}
			else {
				if (cur == p->_left) {
					RotateR(p);
					Swap(cur, p);
				}
				RotateL(g);
				g->_color = Black;
				g->_color = Red;

				break;
			}
		}
	}

	_header->_parent->_color = Black;
	_header->_left = leftMost();
	_header->_right = rightMost();
	return true;
}