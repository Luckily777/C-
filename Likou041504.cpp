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
	//初始化空队列
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


//队列队头入队
void queueFrontPush(Queue* q, QDataType data) {
	QNode* node = creatNode(data);
	//空队列
	if (q->_front == NULL) {
		//判断为空，则将头和尾全部指向node
		q->_front = q->_rear = node;
	}
	else {
		//否则，在front之前插入node
		node->_next = q->_front;
		q->_front = node;
	}
	++q->_size;
	//size++
}

//队头出队
void queuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//删除之后是否为空表
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}

//获取队头元素
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}
//获取队尾元素
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
	//创建栈
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	//申请空间，并且进行初始化
	queueInit(&ms->q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//进行栈的尾插，也就是队列的头插操作
	queueFrontPush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret;
	//创建中间变量
	ret = queueFront(&obj->q);
	//将头部变量给予ret
	queuePop(&obj->q);
	//进行出队操作
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueFront(&obj->q);
	//返回栈的顶部，则是队列的头部
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
	//进行判空操作

}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->q);
	//销毁函数
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