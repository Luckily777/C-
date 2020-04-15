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
//队尾入队
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//空队列
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
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
	//创建一个队列
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	//申请一个空间
	queueInit(&ms->q);
	//进行初始化
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//队列的入队操作
	queuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret;
	//设置中间变量
	int size = queueSize(&obj->q);
	//求出队列的size
	while (size > 1) {
		//之后采用出栈进栈操作，将要取出的元素置于队列的队头位置
		int front = queueFront(&obj->q);
		//将队头元素放在front
		queuePop(&obj->q);
		//之后进行出栈
		queuePush(&obj->q, front);
		//进行进栈
		size--;
	}
	ret = queueFront(&obj->q);
	//将队头元素放置在中间变量ret之中
	queuePop(&obj->q);
	//之后执行出栈操作
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->q);
	//队列尾部元素
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
	//判空操作
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