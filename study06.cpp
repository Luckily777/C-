//Ñ­»·¶ÓÁÐ

typedef struct mycq {
	int front;
	int rear;
	int k;
	int* array;
}mycq;

mycq* creat(int k) {
	mycq* cq = (mycq*)malloc(sizeof(mycq));
	cq->array = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = cq->rear = 0;
	cq->k = k;
	return cq;
}

void cqpushback(mycq* cq, int value) {
	if ((cq->rear + 1) % (cq->k + 1) == cq->front) {
		return false;
	}
	cq->array[cq->rear++] = value;
	if (cq->rear == cq->k + 1) {
		cq->rear = 0;
	}
}

bool popfront(mycq* cq) {
	if (cq->front == cq->rear) {
		return false;
	}
	++cq->front;
	if (cq->front == cq->k + 1) {
		cq->front = 0;
	}
	return true;
}

int frontnum(mycq* cq) {
	if (cq->front == cq->rear) {
		return -1;
	}
	return cq->array[cq->front];
}

int myrear(mycq* cq) {
	if (cq->front == cq->rear) {
		return -1;
	}
	if (cq->rear == 0) {
		return cq->array[cq->k];
	}
	return cq->array[cq->rear-1];
}

void myfree(mycq* cq) {
	free(cq->array);
	free(cq);
}