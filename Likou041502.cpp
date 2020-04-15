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
	//��ʼ���ն���
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
//��β���
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//�ն���
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}

//��ͷ����
void queuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//ɾ��֮���Ƿ�Ϊ�ձ�
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}

//��ȡ��ͷԪ��
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}
//��ȡ��βԪ��
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
	//����һ������
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	//����һ���ռ�
	queueInit(&ms->q);
	//���г�ʼ��
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//���е���Ӳ���
	queuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret;
	//�����м����
	int size = queueSize(&obj->q);
	//������е�size
	while (size > 1) {
		//֮����ó�ջ��ջ��������Ҫȡ����Ԫ�����ڶ��еĶ�ͷλ��
		int front = queueFront(&obj->q);
		//����ͷԪ�ط���front
		queuePop(&obj->q);
		//֮����г�ջ
		queuePush(&obj->q, front);
		//���н�ջ
		size--;
	}
	ret = queueFront(&obj->q);
	//����ͷԪ�ط������м����ret֮��
	queuePop(&obj->q);
	//֮��ִ�г�ջ����
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->q);
	//����β��Ԫ��
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
	//�пղ���
}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->q);
	//���ٺ���
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