//带头双向链表

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct Dlist {
	Node* head;
}Dlist;

void Pintf(Dlist* lst) {
	Node* cur;
	cur = lst->head->next;
	while (cur) {
		if (cur != lst->head) {
			cout << cur->data;
		}
		cur = cur->next;
	}
	cout << endl;
}

void Init(Dlist* lst) {
	Node* node = creatNode(0);
	lst->head->next = lst->head;
	lst->head->prev = lst->head;
}

Node* creatNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}

void ListPsuhBack(Dlist* lst, int data) {
	Node* last = lst->head->prev;
	Node* node = creatNode(data);
	last->next = node;
	node->next = lst->head;
	node->prev = last;
	lst->head->prev = node;
}


void LsitInsert(Node* pos, int data) {
	Node* node = creatNode(data);
	Node* front;
	front = pos->prev;
	front->next = node;
	node->prev = front;
	node->next = pos;
	pos->prev = node;
}

void ListErase(Node* pos) {
	Node* prev, * next;
	if (pos->next = pos) {
		return;
	}
	prev = pos->prev;
	next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

void ListDesory(Dlist* lst) {
	Node* cur = lst->head->next;
	while (cur != lst->head) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}

	free(lst->head);
	lst->head = NULL;
}