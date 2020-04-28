#include "QueueUp.h"



//���г�ʼ������
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
	//��ͷ�Ͷ�βȫ��ָ���
	q->size = 0;
	//����size�ÿ�
}

//���нڵ㴴������
QNode* CreatNode(BTNode* data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	//������нڵ�ռ�
	node->data = data;
	//�������������data�����ڵ�data
	node->next = NULL;
	//nextָ��ָ���
	return node;
}

//���ж�β��Ӻ���
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

//���ж�ͷ���Ӻ���
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

//��ȡ���ж�ͷԪ�غ���
QDataType QueueFront(Queue* q) {
	return q->front->data;
}

//��ȡ���ж�βԪ�غ���
QDataType QueueBack(Quene* q) {
	return q->rear->data;
}

//��ȡ���д�С����
int QueueSize(Quene* q) {
	return q->size;
}

//�ж϶����Ƿ�Ϊ�պ���
int QueueEmpty(Quene* q) {
	if (q->front == NULL) {
		return 1;
	}
	return 0;
}

//�������ٺ���
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

