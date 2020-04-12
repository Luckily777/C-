#include "Queue.h"


//初始化函数
void queueInit(Queue* q) {
	q->front = q->rear = NULL;
	//使得其头和尾全部指向空
	q->size = 0;
	//其中的元素为0
}

//创建队列节点函数
QNode* creatNode(int data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	//申请新的节点空间
	node->data = data;
	//将所要赋值的数据data赋予给node的data
	node->next = NULL;
	//将node的next指向空
	return node;
	//返回所申请到的node指针
}

//队尾入队函数
void queuePush(Queue* q, int data) {
	QNode* node=creatNode(data);
	//判空，若为空队列
	if (q->front = NULL) {
		q->front = q->rear = node;
		//若为空队列，则直接让头front和尾rear指向node
	}
	else {
		//否则
		q->rear->next = node;
		//将node链接到rear的next上
		q->rear = node;
		//使得rear重新指向node
		//也就是在原本的尾后面续接上一个node，使得node成为新的rear
	}

}

//对头出队函数
void queuePop(Queue* q) {
	if (q->front) {
		//申请中间变量next，将q的front的next地址赋给next
		QNode* next = q->front->next;
		free(q->front);
		//之后释放头部的位置
		q->front = next;
		//之后将next赋给q的front
		//也就是使得front往后移动一位，将原本的front释放
		if (q->front = NULL) {
			//释放后再次判空，判断是否为空列表
			q->rear = NULL;
			//若为空列表，将尾也指向空
		}
		q->size--;
		//头部出队后，数据量减少1
	}
}


//获取队头元素的函数
int queueFront(Queue* q) {
	return q->front->data;
	//直接返回q的队头的数据
}

//获取队尾元素的函数
int queueBack(Queue* q) {
	return q->rear->data;
	//直接返回q的队尾的数据
}

int queueSize(Queue* q) {
	return q->size;
	//直接返回数据size的大小

	//若是没有size的话则进行遍历
	int num = 0;
	QNode* cur = q->front;
	//创建中间变量指针cur 指向q的头地址
	while (cur) {
		//进行遍历，num++ 逐渐后移，直到cur指向空为止
		num++;
		cur = cur->next;
	}
	return num;
	//最终返回num
}

//判空函数
int queueEmpty(Queue* q) {
	if (q->front == NULL) {
		return 1;
		///若指向空，则返回1
	}
	return 0;
	//否则返回0
}

//队列销毁函数
void queueDestory(Queue* q) {
	QNode* cur = q->front;
	//创建中间变量指针cur 指向q的头地址
	while (cur) {
		//进行遍历，逐渐后移，直到cur指向空为止
		QNode* next = cur->next;
		//创建中间变量next指向cur的next
		free(cur);
		//释放cur
		cur = next;
		//使得cur重新指向next
	}
	q->front = q->rear = NULL;
	//头和尾全部指向null
	q->size = 0;
	//size归零
}




