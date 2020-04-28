#pragma once
#include <stdlib.h>
#include "BinaryTreeUp.h"
//����
typedef BTNode* QDataType;

//���нڵ�

typedef struct QNode {
	struct QNode* next;
	QDataType data;
}QNode;

//����
typedef struct Quene {
	QNode* front;
	QNode* rear;
	int size;
}Queue;

//���г�ʼ������
void QueueInit(Queue* q);

//���нڵ㴴������
QNode* CreatNode(BTNode* data);

//���ж�β��Ӻ���
void QueuePush(Quene* q, BTNode* data);

//���ж�ͷ���Ӻ���
void QueuePop(Quene* q);

//��ȡ���ж�ͷԪ�غ���
QDataType QueueFront(Queue* q);

//��ȡ���ж�βԪ�غ���
QDataType QueueBack(Quene* q);

//��ȡ���д�С����
int QueueSize(Quene* q);

//�ж϶����Ƿ�Ϊ�պ���
int QueueEmpty(Quene* q);

//�������ٺ���
void QueueDestory(Queue* q);

