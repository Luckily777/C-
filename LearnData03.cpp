//Õ»

typedef struct Stack {
	int* array;
	size_t size;
	size_t capacity;
};

//¶ÓÁĞ

typedef struct QNode {
	int data;
	struct QNode* next;
};

typedef struct Queue {
	QNode* front;
	QNode* rear;
	int size;

};

void Init(Queue* q) {
	q->front = q->rear = null;
	q->size = 0;
}

void QueuePush(Queue* q, int data) {
	QNode* node = CreatNode(data);
	if (q->front = null) {
		q->front = q->rear = node;
	}
	else {
		q->rear->next = node;
		q->rear = node;
	}
}

int QueueSize(Queue* q) {
	int num = 0;
	QNode* cur = q->front;
	while (cur) {
		num++;
		cur = cur->next;
	}
	return num;
}