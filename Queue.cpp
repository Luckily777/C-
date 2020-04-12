#include "Queue.h"


//��ʼ������
void queueInit(Queue* q) {
	q->front = q->rear = NULL;
	//ʹ����ͷ��βȫ��ָ���
	q->size = 0;
	//���е�Ԫ��Ϊ0
}

//�������нڵ㺯��
QNode* creatNode(int data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	//�����µĽڵ�ռ�
	node->data = data;
	//����Ҫ��ֵ������data�����node��data
	node->next = NULL;
	//��node��nextָ���
	return node;
	//���������뵽��nodeָ��
}

//��β��Ӻ���
void queuePush(Queue* q, int data) {
	QNode* node=creatNode(data);
	//�пգ���Ϊ�ն���
	if (q->front = NULL) {
		q->front = q->rear = node;
		//��Ϊ�ն��У���ֱ����ͷfront��βrearָ��node
	}
	else {
		//����
		q->rear->next = node;
		//��node���ӵ�rear��next��
		q->rear = node;
		//ʹ��rear����ָ��node
		//Ҳ������ԭ����β����������һ��node��ʹ��node��Ϊ�µ�rear
	}

}

//��ͷ���Ӻ���
void queuePop(Queue* q) {
	if (q->front) {
		//�����м����next����q��front��next��ַ����next
		QNode* next = q->front->next;
		free(q->front);
		//֮���ͷ�ͷ����λ��
		q->front = next;
		//֮��next����q��front
		//Ҳ����ʹ��front�����ƶ�һλ����ԭ����front�ͷ�
		if (q->front = NULL) {
			//�ͷź��ٴ��пգ��ж��Ƿ�Ϊ���б�
			q->rear = NULL;
			//��Ϊ���б���βҲָ���
		}
		q->size--;
		//ͷ�����Ӻ�����������1
	}
}


//��ȡ��ͷԪ�صĺ���
int queueFront(Queue* q) {
	return q->front->data;
	//ֱ�ӷ���q�Ķ�ͷ������
}

//��ȡ��βԪ�صĺ���
int queueBack(Queue* q) {
	return q->rear->data;
	//ֱ�ӷ���q�Ķ�β������
}

int queueSize(Queue* q) {
	return q->size;
	//ֱ�ӷ�������size�Ĵ�С

	//����û��size�Ļ�����б���
	int num = 0;
	QNode* cur = q->front;
	//�����м����ָ��cur ָ��q��ͷ��ַ
	while (cur) {
		//���б�����num++ �𽥺��ƣ�ֱ��curָ���Ϊֹ
		num++;
		cur = cur->next;
	}
	return num;
	//���շ���num
}

//�пպ���
int queueEmpty(Queue* q) {
	if (q->front == NULL) {
		return 1;
		///��ָ��գ��򷵻�1
	}
	return 0;
	//���򷵻�0
}

//�������ٺ���
void queueDestory(Queue* q) {
	QNode* cur = q->front;
	//�����м����ָ��cur ָ��q��ͷ��ַ
	while (cur) {
		//���б������𽥺��ƣ�ֱ��curָ���Ϊֹ
		QNode* next = cur->next;
		//�����м����nextָ��cur��next
		free(cur);
		//�ͷ�cur
		cur = next;
		//ʹ��cur����ָ��next
	}
	q->front = q->rear = NULL;
	//ͷ��βȫ��ָ��null
	q->size = 0;
	//size����
}




