//×óÓÒµ÷Õû

void RotateR(Node* parent) {
	Node* subL = parent->_left;
	Node* subLR = subL->_right;

	subL->_right = parent;
	parent->_left = subLR;

	if (subLR) {
		subLR->_parent = parent;
	}
	if (parent == _header->_parent) {
		_header->_parent = subL;
		subL->_parent = _header;
	}
	else {
		Node* g = parent->_parent;
		subL->_parent = g;
		if (g->_left == parent) {
			g->_left = subL;
		}
		else {
			g->_right = subL;
		}
	}
	parent->_parent = subL;
}



void RotateL(Node* parent) {
	Node* subR = parent->_right;
	Node* subRL = subR->_left;
	subR->_left = parent;
	parent->_right = subRL;

	if (subRL) {
		subRL->_parent = parent;
	}
	if (parent == _header->_parent) {
		_header->_parent = subR;
		subR->_parent = _header;
	}
	else {
		Node* g = parent->_parent;
		subR->_parent = g;
		if (g->_left == parent) {
			g->_left = subR;
		}
		else {
			g->_right = subR;
		}
	}
	parent->_parent = subR;
}