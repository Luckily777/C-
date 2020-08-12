bool isRBtree() {
	Node* root = _header->_parent;
	if (root == nullptr) {
		return true;
	}
	if (root->_color != Black) {
		return false;
	}

	int blackcount = 0;
	Node* cur = root;
	while (cur) {
		if (cur->_color == Black) {
			++blackcount;
		}
		cur = cur->_left;
	}

	int curcount = 0;
	return _isRBtree(root, blackcount, curcount);
}

bool _isRBtree(Node* root, int blackcount, int curcount) {
	if (root == nullptr) {
		if (blackcount != curcount) {
			return false;
		}
		return true;
	}

	if (root->_color == Black) {
		++curcount;
	}
	Node* parent = root->_parent;
	if (parent && parent->_color == Red && root->_color == Red) {
		return false;
	}

	return _isRBtree(root->_left, blackcount, curcount) && _isRBtree(root->_right, blackcount, curcount);

}