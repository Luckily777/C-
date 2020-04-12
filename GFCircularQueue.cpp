#include <stdio.h>
#include <stdlib.h>

//官方版本的循环队列接口实现
typedef struct {
	int front;
	int rear;
	int k;
	int* array;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

//循环队列创建函数
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//创建mq指针，指向新申请的队列空间
	mq->array = (int*)malloc(sizeof(int) * (k + 1));
	//为动态数组申请空间 （k+1） 最后留出一个空位置
	mq->front = mq->rear = 0;
	//头和尾全部赋值0
	mq->k = k;
	//容量尾k
	return mq;
}

//循环队列的尾插函数
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
		//若队列已满，则尾插失败
		return false;
	obj->array[obj->rear++] = value;
	//进行尾插操作
	if (obj->rear == obj->k + 1)
		//保持循环结构，
		obj->rear = 0;
	return true;
}

//队列头删函数
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		//若队列为空，则删除失败
		return false;
	++obj->front;
	//将头指针向后移动一位
	if (obj->front == obj->k + 1)
		//若头指向最后的空位置，则归零保持循环
		obj->front = 0;
	return true;
}

//查找循环队列的队头元素
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		//判空是否为空，若为空，则返回-1
		return -1;
	return obj->array[obj->front];
	//否则则返回队头元素
}


//查找循环队列的队尾元素
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		//若为空，同理
		return -1;
	if (obj->rear == 0)
		//若尾指向头0，则返回第k个元素
		return obj->array[obj->k];
	return obj->array[obj->rear - 1];
	//否则返回尾之前的那个元素
}

//循环队列判空函数
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return true;
	//若为空返回true
	return false;
}

//循环队列满溢判断函数
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
		//若尾+1后除以本身的长度后所余的数等于front则表示满溢状态
		return true;
	return false;
}

//循环队列的释放函数
void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	//释放数组
	free(obj);
	//释放队列
}