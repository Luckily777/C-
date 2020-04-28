#include "QueueUp.h"



//队列初始化函数
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
	//队头和队尾全部指向空
	q->size = 0;
	//队列size置空
}

//队列节点创建函数
QNode* CreatNode(BTNode* data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	//申请队列节点空间
	node->data = data;
	//将所传输的数据data传给节点data
	node->next = NULL;
	//next指针指向空
	return node;
}

//队列队尾入队函数
void QueuePush(Quene* q, BTNode* data) {
	QNode* node=CreatNode(data);
	if (q->front == NULL) {
		q->front = q->rear = node;
	}
	else {
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}

//队列队头出队函数
void QueuePop(Quene* q) {
	if (q->front) {
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
		if (q->front == NULL) {
			q->rear = NULL;
		}
		q->size--;
	}
}

//获取队列队头元素函数
QDataType QueueFront(Queue* q) {
	return q->front->data;
}

//获取队列队尾元素函数
QDataType QueueBack(Quene* q) {
	return q->rear->data;
}

//获取队列大小函数
int QueueSize(Quene* q) {
	return q->size;
}

//判断队列是否为空函数
int QueueEmpty(Quene* q) {
	if (q->front == NULL) {
		return 1;
	}
	return 0;
}

//队列销毁函数
void QueueDestory(Queue* q) {
	QNode* cur = q->front;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}

