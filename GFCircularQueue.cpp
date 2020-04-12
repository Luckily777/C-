#include <stdio.h>
#include <stdlib.h>

//�ٷ��汾��ѭ�����нӿ�ʵ��
typedef struct {
	int front;
	int rear;
	int k;
	int* array;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

//ѭ�����д�������
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//����mqָ�룬ָ��������Ķ��пռ�
	mq->array = (int*)malloc(sizeof(int) * (k + 1));
	//Ϊ��̬��������ռ� ��k+1�� �������һ����λ��
	mq->front = mq->rear = 0;
	//ͷ��βȫ����ֵ0
	mq->k = k;
	//����βk
	return mq;
}

//ѭ�����е�β�庯��
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
		//��������������β��ʧ��
		return false;
	obj->array[obj->rear++] = value;
	//����β�����
	if (obj->rear == obj->k + 1)
		//����ѭ���ṹ��
		obj->rear = 0;
	return true;
}

//����ͷɾ����
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		//������Ϊ�գ���ɾ��ʧ��
		return false;
	++obj->front;
	//��ͷָ������ƶ�һλ
	if (obj->front == obj->k + 1)
		//��ͷָ�����Ŀ�λ�ã�����㱣��ѭ��
		obj->front = 0;
	return true;
}

//����ѭ�����еĶ�ͷԪ��
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		//�п��Ƿ�Ϊ�գ���Ϊ�գ��򷵻�-1
		return -1;
	return obj->array[obj->front];
	//�����򷵻ض�ͷԪ��
}


//����ѭ�����еĶ�βԪ��
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		//��Ϊ�գ�ͬ��
		return -1;
	if (obj->rear == 0)
		//��βָ��ͷ0���򷵻ص�k��Ԫ��
		return obj->array[obj->k];
	return obj->array[obj->rear - 1];
	//���򷵻�β֮ǰ���Ǹ�Ԫ��
}

//ѭ�������пպ���
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return true;
	//��Ϊ�շ���true
	return false;
}

//ѭ�����������жϺ���
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
		//��β+1����Ա���ĳ��Ⱥ������������front���ʾ����״̬
		return true;
	return false;
}

//ѭ�����е��ͷź���
void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	//�ͷ�����
	free(obj);
	//�ͷŶ���
}