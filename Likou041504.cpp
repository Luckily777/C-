#include <stdio.h>
#include <stdlib.h>


typedef int QDataType;

typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;

void queueInit(Queue* q);

QNode* creatNode(QDataType data);

void queuePush(Queue* q, QDataType data);

void queueFrontPush(Queue* q, QDataType data);

void queuePop(Queue* q);

QDataType queueFront(Queue* q);

QDataType queueBack(Queue* q);

int queueSize(Queue* q);

int queueEmpty(Queue* q);

void queueDestory(Queue* q);

void queueInit(Queue* q)
{
	//��ʼ���ն���
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

QNode* creatNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}


//���ж�ͷ���
void queueFrontPush(Queue* q, QDataType data) {
	QNode* node = creatNode(data);
	//�ն���
	if (q->_front == NULL) {
		//�ж�Ϊ�գ���ͷ��βȫ��ָ��node
		q->_front = q->_rear = node;
	}
	else {
		//������front֮ǰ����node
		node->_next = q->_front;
		q->_front = node;
	}
	++q->_size;
	//size++
}

//��ͷ����
void queuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//ɾ��֮���Ƿ�Ϊ�ձ�
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}

//��ȡ��ͷԪ��
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}
//��ȡ��βԪ��
QDataType queueBack(Queue* q)
{
	return q->_rear->_data;
}

int queueSize(Queue* q)
{
	/*
	int num = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		++num;
		cur = cur->_next;
	}
	return num;
	*/
	return q->_size;
}

int queueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

void queueDestory(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}


typedef struct {
	Queue q;
	//����ջ
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	//����ռ䣬���ҽ��г�ʼ��
	queueInit(&ms->q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//����ջ��β�壬Ҳ���Ƕ��е�ͷ�����
	queueFrontPush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret;
	//�����м����
	ret = queueFront(&obj->q);
	//��ͷ����������ret
	queuePop(&obj->q);
	//���г��Ӳ���
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueFront(&obj->q);
	//����ջ�Ķ��������Ƕ��е�ͷ��
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
	//�����пղ���

}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->q);
	//���ٺ���
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/


int main() {
	MyStack *obj=myStackCreate();
	myStackPush(obj, 1);
	myStackPop(obj);
	myStackPush(obj, 2);
	myStackPop(obj);
	myStackPush(obj, 3);
	myStackPop(obj);
	myStackTop(obj);
	myStackEmpty(obj);
	system("pasue");
	return 0;
}