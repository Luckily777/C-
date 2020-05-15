//Á´±í

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct SingList {
	Node* head;
}SingList;


void Init(SingList* si) {
	si->head = null;
}

Node* Crear(int data) {
	Node* node = (int*)malloc(sizeof(Node));

	node->data = data;
	node->next = null;
	return node;
}

void Printf(SingList* sl) {
	Node* cur = sl->head;
	while (cur) {
		printf("%d ",cur->data);
		cur = cur->next;
	}
}

void SingListInsert(Node* pos, int data) {
	if (pos == null) {
		return;
	}
	Node* newNode = Crear(data);
	newNode->next = pos->next;
	pos->next = newNode;

}

void SingListErase(Node* pos) {
	if (pos == NULL) {
		return;
	}
	Node* next;
	next = pos->next;
	if(next){
		pos->next = next->next;
		free(next);
	}
}

void SingListDestory(SingList* sl) {
	Node* cur = sl->head;
	while (cur) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}



//Ë«ÏòÁ´±í

typedef struct Node {
	int data;
	struct Node* next;
	strcut Node* prev;
}Node;

typedef struct List {
	Node* header;
}List;


void Printf(List* si) {
	Node* cur;
	cur = si->header->next;
	while (cur != si->header) {
		printf();
		cur = cur->next;
	}
	printf("\n");
}

void CreatNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = null;
	return node;
}

void Init(List* si) {
	si->header = CreatNode(0);
	si->header->next = si->header;
	si->header->prev = si->header;
}


void ListIntsert(Node* pos, int data) {
	Node* node = CreatNode(data);
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
	perv = pos->prev;
	next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}


void ListDesroy(List* si) {
	Node* cur = si->header->next;
	while (cur != si->header) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(si->header);
	si->header = null;
}