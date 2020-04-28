#pragma once
#include <stdlib.h>
#include "BinaryTreeUp.h"
//队列
typedef BTNode* QDataType;

//队列节点

typedef struct QNode {
	struct QNode* next;
	QDataType data;
}QNode;

//队列
typedef struct Quene {
	QNode* front;
	QNode* rear;
	int size;
}Queue;

//队列初始化函数
void QueueInit(Queue* q);

//队列节点创建函数
QNode* CreatNode(BTNode* data);

//队列队尾入队函数
void QueuePush(Quene* q, BTNode* data);

//队列队头出队函数
void QueuePop(Quene* q);

//获取队列队头元素函数
QDataType QueueFront(Queue* q);

//获取队列队尾元素函数
QDataType QueueBack(Quene* q);

//获取队列大小函数
int QueueSize(Quene* q);

//判断队列是否为空函数
int QueueEmpty(Quene* q);

//队列销毁函数
void QueueDestory(Queue* q);

