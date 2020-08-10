//µ¥ÏòÁ´±í

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Singlist {
	Node* head;
}Singlist;

void SinglistInit(Singlist* sl) {
	sl->head = NULL;
}

Node* CreatNode(int data) {
	Node* node = (Node*)malloc(size(Node));

	node->data = data;
	node->next = NULL;
	return node;
}

void Singlistprint(Singlist* sl) {
	Node* cur = sl->head;
	while (cur) {
		cout << cur->data;
	}
	cout << endl;
}


void SinglistFonrtpush(Singlist* sl, int data) {
	Node* node=CreatNode(data);
	if (sl->head == NULL) {
		sl->head = node;
	}else{
		node->next = sl->head;
		sl->head = node;
	}
}

void SinglistFonrtPop() {

}

void SinglistInsrt(Node* pos, int value) {
	if (pos == NULL) {
		return;
	}
	Node* node = CreatNode(value);
	node->next = pos->next;
	pos->next = node;
}

void SinglistErase(Node* pos) {
	Node* next;
	if (pos == NULL) {
		return;
	}
	next = pos->next;
	if (next) {
		pos->next = netx->next;
		free(next);
	}
}


Node* SinglistFind(Singlist* sl, int data) {
	Node* cur = sl->head;
	while (cur) {
		if (cur->data == data) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SinglistDestory(Singlist* sl) {
	Node* cur = sl->head;
	while (cur) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}