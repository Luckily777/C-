#pragma once
#include <stdio.h>
#include <stdlib.h>

//�������нڵ�
typedef struct QNode {
	struct QNode* next;
	int data;
};

//�������б�ͷ��β
typedef struct Queue {
	QNode* front;
	QNode* rear;
	int size;
}Queue;


void queueInit(Queue* q);

QNode* creatNode(int data);

void queuePush(Queue* q, int data);

void queuePop(Queue* q);

int queueFront(Queue* q);

int queueBack(Queue* q);

int queueSize(Queue* q);

int queueEmpty(Queue* q);

void queueDestory(Queue* q);


