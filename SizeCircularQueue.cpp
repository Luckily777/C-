#include <stdio.h>
#include <stdlib.h>


//自创size版本的循环队列接口实现
typedef struct {
	int front;
	int rear;
	int size;
	int k;
	int* array;	
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

//队列的创建函数
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//申请新的变量
	mq->array = (int*)malloc(sizeof(int) * k);
	//给队列之中的数组开辟k个大小
	mq->front = mq->rear = 0;
	//头和尾全部为0
	mq->size=0;
	//元素个数为0
	mq->k = k;
	//总长度为k
	return mq;
}


//循环队列尾插函数
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->k)
		//判断是否满
		return false;
	//尾插
	obj->array[obj->rear++] = value;
	//进行尾插操作
	//保证循环结构
	if (obj->rear == obj->k)
		//若插入之后满了，则让其移动到原点位置，保证循环结构
		obj->rear = 0;
	obj->size++;
	//插入后元素个数加1
	return true;
}


//循环队列头删函数
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->size == 0)
		//若元素个数为零，则删除失败
		return false;
	//头删
	++obj->front;
	//头往后移动一位
	if (obj->front == obj->k)
		//若移动后为最后元素，则重新循环
		obj->front = 0;
	//将原有的size减1
	--obj->size;
	return true;
}


//获取循环队列队头元素
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->size == 0)
		//若元素个数不为零
		return -1;
	return obj->array[obj->front];
	//则直接返回队头元素
}

//获取循环队列队尾元素
/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->size == 0)
		//若为零，则返回-1
		return -1;
	if (obj->rear == 0)
		//若队尾在零位置，则返回之前的最后元素
		return obj->array[obj->k - 1];
	return obj->array[obj->rear - 1];
	//两者都不满足的话，则直接返回尾部之前的一个元素
}

//循环队列判空操作函数
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->size == 0)
		//若size为零，则代表队列里无元素
		return true;
	return false;
}

//循环队列判断满溢函数
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj->size == obj->k)
		//若size等于最大长度，则代表满溢
		return true;
	return false;
}

//循环队列空间释放函数
void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	//释放数组
	free(obj);
	//释放队列
}
