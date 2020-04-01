#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//ʵ�ֲ���ͷ�����ѭ������
typedef struct SingList
{
	Node* head; // head: ��ʾ����������ͷ��㣬����һ����Ч�����ݵ�λ��
}SingList;


//SingListInit ��ʼ������
void SingListInit(SingList* Sl) {
	Sl->head = NULL;
	//���ÿ�����
}

//CrearNode �����ڵ�
Node* CrearNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	//����ռ�
	node->data = data;
	//��������data��ֵ���ڵ�֮�е�������
	node->next = NULL;
	//��ָ����һ���ڵ��ָ�븳��
	return node;
	//������������node
}


// SingListPrint ��ӡ����֮�е�����
void SingListPrint(SingList* Sl) {
	Node* cur = Sl->head;
	//��ͷ�����ָ�븳ֵ��cur
	while (cur) {
		printf("%d ", cur->data);
		//��ӡ��ָ��ĵ�һ���ڵ�֮�е�����
		cur = cur->next;
		//���˽ڵ�֮��ָ����һ���ڵ��ָ�����¸�ֵ��cur
	}
	printf("\n");
}


//SingListPushFront ͷ�庯��
void SingListPushFront(SingList* Sl, int data) {
	Node* node = CrearNode(data);
	//����һ���ڵ�
	if (Sl->head == NULL) {
		//����ǿ�����
		Sl->head = node;
		//ֱ�ӽ�����������node��ַ����ͷ�����ָ��λ��
	}
	else {
		node->next = Sl->head;
		//��ͷ����֮�е�λ�ø��������Ľڵ��ָ��
		Sl->head = node;
		//���������Ľڵ�ĵ�ַ��ͷָ��
	}
}



//SingListPopFront ͷɾ����
void SingListPopFront(SingList* Sl) {
	if (Sl->head) {
		//�Ƚ����п�
		Node* cur = Sl->head;
		//��ͷ�����λ�ø���Curָ��

		Sl->head = cur->next;
		//��ͷ�ڵ�֮�е�ָ����ָ��ĵ�ַ��ͷ�ڵ�
		free(cur);
		//�ͷ�ͷ�ڵ�Ŀռ�
	}
}


//SingListPushBack β�����뺯�� 
void SingListPushBack(SingList* Sl, int data) {
	Node* node = CrearNode(data);
	//������Ҫ����Ľڵ�
	if (Sl->head = NULL) {
		Sl->head = node;
		//�������Ϊ�գ���ֱ�ӽ�ͷ�����ָ��ָ�������������λ��
	}
	else {
		Node* last = Sl->head;
		//�������׵�ַ��������������lastָ��
		while (last->next) {
			//ѭ���ҵ�nextָ��Ϊ�յ��Ǹ�
			last = last->next;
		}
		last->next = node;
		//���������Ľڵ�λ�ø��������ҵ����Ǹ�nextָ��
	}
}


//SingListPopBack βɾ����
void SingListPopBack(SingList* Sl) {
	//�ҵ����һ���ڵ㣬�����޸�ɾ���ڵ�֮ǰ��ǰ���ڵ��ִ��
	if (Sl->head) {
		//ͷ����ָ������Ϊ��
		Node* prev = NULL;
		//prev�ڵ�Ϊ��
		Node* tail = Sl->head;
		//��ͷָ���λ�ø�tail
		while (tail->next) {
			//��ָ�벻ΪNULL
			prev = tail;
			//���˽ڵ㸳��prev
			tail = tail->next;
			//��ָ����һ������ָ���tail
		}
		if (tail == Sl->head) {
			//���ֻ��һ��ͷ����
			Sl->head = NULL;
			//��ͷ����ָ���
		}
		else {
			prev->next = NULL;
			//������һ��ǰ�����ָ���
		}
		free(tail);
		//�ͷ����һ���ڵ�Ŀռ�

	}
}


//
int main() {
	SingList sl;
	SingListInit(&sl);
	SingListPushBack(&sl, 1);
	SingListPushFront(&sl, 2);
	SingListPushFront(&sl, 3);
	SingListPushFront(&sl, 4);
	SingListPushFront(&sl, 5);
	SingListPushFront(&sl, 6);
	SingListPushBack(&sl, 2);
	SingListPushBack(&sl, 3);
	SingListPushBack(&sl, 4);
	SingListPushBack(&sl, 5);
	SingListPushBack(&sl, 6);
	SingListPushBack(&sl, 7);  // 6 5 4 3 2 1 2 3 4 5 6 7
	SingListPrint(&sl);

	//2.
	SingListPopFront(&sl);
	SingListPrint(&sl);
	SingListPopFront(&sl);
	SingListPrint(&sl);
	SingListPopFront(&sl);
	SingListPrint(&sl);
	SingListPopFront(&sl);
	SingListPrint(&sl);
	SingListPopFront(&sl);
	SingListPrint(&sl);
	SingListPopFront(&sl);
	SingListPrint(&sl);
	SingListPopFront(&sl);
	SingListPrint(&sl);

	//3.
	SingListPushBack(&sl, 1);
	SingListPushFront(&sl, 2);
	SingListPushFront(&sl, 3);
	SingListPushFront(&sl, 4);
	SingListPushFront(&sl, 5);
	SingListPushFront(&sl, 6);
	SingListPushBack(&sl, 2);
	SingListPushBack(&sl, 3);
	SingListPushBack(&sl, 4);
	SingListPushBack(&sl, 5);
	SingListPushBack(&sl, 6);
	SingListPushBack(&sl, 7);  // 6 5 4 3 2 1 2 3 4 5 6 7
	SingListPrint(&sl);

	//4.
	SingListInit(&sl);
	SingListPushBack(&sl, 1);
	SingListPushBack(&sl, 2);
	SingListPushBack(&sl, 3);
	SingListPushBack(&sl, 4);
	SingListPushBack(&sl, 5);
	SingListPushBack(&sl, 6);
	SingListPushBack(&sl, 7);  // 6 5 4 3 2 1 2 3 4 5 6 7
	SingListPrint(&sl);


	//5.
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	SingListPopBack(&sl);
	SingListPrint(&sl);
	system("pause");
	return 0;
}