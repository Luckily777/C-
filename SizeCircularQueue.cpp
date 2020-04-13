#include <stdio.h>
#include <stdlib.h>


//�Դ�size�汾��ѭ�����нӿ�ʵ��
typedef struct {
	int front;
	int rear;
	int size;
	int k;
	int* array;	
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

//���еĴ�������
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//�����µı���
	mq->array = (int*)malloc(sizeof(int) * k);
	//������֮�е����鿪��k����С
	mq->front = mq->rear = 0;
	//ͷ��βȫ��Ϊ0
	mq->size=0;
	//Ԫ�ظ���Ϊ0
	mq->k = k;
	//�ܳ���Ϊk
	return mq;
}


//ѭ������β�庯��
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->k)
		//�ж��Ƿ���
		return false;
	//β��
	obj->array[obj->rear++] = value;
	//����β�����
	//��֤ѭ���ṹ
	if (obj->rear == obj->k)
		//������֮�����ˣ��������ƶ���ԭ��λ�ã���֤ѭ���ṹ
		obj->rear = 0;
	obj->size++;
	//�����Ԫ�ظ�����1
	return true;
}


//ѭ������ͷɾ����
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->size == 0)
		//��Ԫ�ظ���Ϊ�㣬��ɾ��ʧ��
		return false;
	//ͷɾ
	++obj->front;
	//ͷ�����ƶ�һλ
	if (obj->front == obj->k)
		//���ƶ���Ϊ���Ԫ�أ�������ѭ��
		obj->front = 0;
	//��ԭ�е�size��1
	--obj->size;
	return true;
}


//��ȡѭ�����ж�ͷԪ��
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->size == 0)
		//��Ԫ�ظ�����Ϊ��
		return -1;
	return obj->array[obj->front];
	//��ֱ�ӷ��ض�ͷԪ��
}

//��ȡѭ�����ж�βԪ��
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->size == 0)
		//��Ϊ�㣬�򷵻�-1
		return -1;
	if (obj->rear == 0)
		//����β����λ�ã��򷵻�֮ǰ�����Ԫ��
		return obj->array[obj->k - 1];
	return obj->array[obj->rear - 1];
	//���߶�������Ļ�����ֱ�ӷ���β��֮ǰ��һ��Ԫ��
}

//ѭ�������пղ�������
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->size == 0)
		//��sizeΪ�㣬������������Ԫ��
		return true;
	return false;
}

//ѭ�������ж����纯��
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj->size == obj->k)
		//��size������󳤶ȣ����������
		return true;
	return false;
}

//ѭ�����пռ��ͷź���
void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	//�ͷ�����
	free(obj);
	//�ͷŶ���
}
