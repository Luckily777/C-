//二叉树遍历和接口


typedef struct BTNode {
	struct BTNode* left;
	struct BTNode* right;
	int data;
}BTNode;


BTNode* BTtreecreate(int* a, int* pi) {
	if (a[*pi] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = a[*pi];
		(*pi++);
		root->left = BTtreecreate(a, pi);
		(*pi++);
		root->right = BTtreecreate(a, pi);
		return root;
	}else {
		return NULL;
	}
}


void BTtreeDestory(BTNode** root) {
	BTNode* cur = *root;
	if (cur) {
		BTtreeDestory(&cur->left);
		BTtreeDestory(&cur->right);
		free(cur);
		*root = NULL;
	}
}

int BTtreesize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return BTtreesize(root->left) + BTtreesize(root->right) + 1;
}


int BTtreeLevesize(BTNode* root,int k){
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BTtreeLevesize(root->left, k - 1) + BTtreeLevesize(root->right, k - 1);
}

BTNode* BTtreefind(BTNode* root, int x) {
	BTNode* ret;
	if (root == NULL) {
		return NULL;
	}
	if (root->data == x) {
		return root;
	}

	ret = BTtreefind(root->left, x);
	if (ret) {
		return ret;
	}
	return BTtreefine(root->right, x);
}



void BTtreePrev(BTNode* root) {
	if (root) {
		cout << root->data;
		BTtreePrev(root->left);
		BTtreePrev(root->right);
	}
}

void BTtreeIn(BTNode* root) {
	if (root) {
		BTtreeIn(root->left);
		cout << root->data;
		BTtreeIn(root->right);
	}
}

void BTtreePost(BTNode* root) {
	if (root) {
		BTtreePost(root->left);
		BTtreePost(root->right);
		cout << root->data;
	}
}

void BTtreeleve(BTNode* root) {
	Queue q;
	Queueinit(&q);

	if (root) {
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		Queuepop(&q);
		cout << front->data;
		if (front->left) {
			QueuePush(&q, front->left);
		}
		if (front->right) {
			QueuePush(&q, front->right);
		}
	}
	cout << endl;
}

