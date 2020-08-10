//╤сап

typedef struct Qnode {
	struct Qnode* next;
	int data;
}Qnode;

typedef struct Queue {
	Qnode* front;
	Qnode* rear;
	int size;
}Queue;

void queueinit(Queue* q) {
	q->front = q->rear = NULL;
	q->size = 0;
}

Qnode* creatnode(int data) {
	Qnode* node = (Qnode*)malloc(sizeof(Qnode));
	node->data = data;
	node->next = null;
	return node;
}

void queuepushback(Queue* q, int data) {
	Queue* node = creatnode(data);
	if (q->front = NULL) {
		q->rear = q->front = node;
	}
	else {
		q->rear->next = node;
		q->rear = node;
	}
}

void queuepop(Queue* q) {
	if (q->front) {
		Qnode* next = q->front->next;
		free(q->front);
		q->front = next;
		if (q->front == NULL) {
			q->rear = NULL;
		}
		q->size--;
	}
}


int queueFRONT(Queue* q) {
	return q->front->data;
}

int queueback(Queue* q) {
	return q->rear->data;
}

int queuesize(Queue* q) {
	return q->size;
}

int queueempty(Queue* q) {
	if (q->front == NULL) {
		return 1;
	}

	return 0;
}

void queuedestory(Queue* q) {
	Qnode* cur = q->front;
	while (cur) {
		Qnode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}

