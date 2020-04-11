#include <stdlib.h>
#include <stdio.h>

//����ڵ�ṹ��
typedef struct Node
{
	int data;
	//�洢������
	struct Node* next;
	//ָ����һ���ڵ�
	struct Node* prev;
	//ָ����һ���ڵ�

}Node;

//��������
typedef struct List
{
	Node* header;
	//ͷ�ڵ�
}List;

// ��ӡ����
void printList(List* lst) {
	Node* cur;
	//�����ڵ����
	cur = lst->header->next;
	//ʹ��ָ��header��next��ַ
	while (cur != lst->header) {
		printf("%d ", cur->data);
		//��ӡ���е�data
		cur = cur->next;
		//����һλ
	}
	printf("\n");
}

//��ʼ������
void listInit(List* lst) {
	lst->header = creatNode(0);
	//ʹ��headerָ���´����Ľڵ�
	lst->header->next = lst->header;
	//ʹ����next��prev��ָ���䱾��
	lst->header->prev = lst->header;
}

//�����±�������
Node* creatNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	//Ϊnode����һ���µ�Node��С�Ŀռ�
	node->data = data;
	//���������dataֵ��ֵ��node��data
	node->next = node->prev = NULL;
	//next��prevȫ��ָ���
	return node;
	//����node
}

//β�庯��
void listPushBack(List* lst, int data) {
	Node* last = lst->header->prev;
	//����lastָ��ָ��header��ǰһ���ڵ�
	Node* node = creatNode(data);
	//Ϊdata�����µĽڵ�׼�����в���
	last->next = node;
	//last��next�д��node�ĵ�ַ
	node->prev = last;

	//node��prev�д��last�ĵ�ַ
	node->next = lst->header;
	//��lst��header�ĵ�ַ���õ�node��next��
	lst->header->prev = node;
	//��node�ĵ�ַ���õ�header��prev��

	//ʹ��������뺯��
	listInsert(lst->header, data);
}


void listPopBack(List* lst) {
	if (lst->header->next == lst->header) {
		//����ɾ��headerͷ�����������ڣ����ʾ������
		return;
	}
	Node* last, * prev;
	//���������ڵ�ָ�����
	last = lst->header->prev;
	//last�д��headerǰһ���ڵ�ĵ�ַ
	prev = last->prev;
	//prev�д��lastǰһ���ڵ�ĵ�ַ
	prev->next = lst->header;
	//prev��next֮�д��ͷ�ڵ�ĵ�ַ
	lst->header->prev = prev;
	//header��prev�д��prev�ĵ�ַ
	free(last);
	//�ͷ�last

	//ʹ�����ɾ������
	listErase(lst->header->prev);
}

void listPushFront(List* lst, int data) {
	//
	Node* node = creatNode(data);
	//������Ҫ����Ľڵ�
	Node* next;
	//�����µ�nextָ�����
	next = lst->header->next;
	//��header�е�next��ַ�����next֮��
	lst->header->next = node;
	//��node�����header��next֮��
	node->prev = lst->header;
	//��header�ĵ�ַ�����node��prev֮��
	node->next = next;
	//��next�����node��next֮��
	next->prev = node;
	//��node�����next��prev֮��

	//ʹ��������뺯��
	listInsert(lst->header->next, data);
}
void listPopFront(List* lst) {
	if (lst->header->next = lst->header) {
		return;
		//������ֻ��header�����ʾ������������ɾ��
	}
	Node* next,*cur;
	//������������
	cur = lst->header->next;
	//��header��next��ַ������cur
	next = cur->next;
	//��cur��next���赽next֮��
	lst->header->next = next;
	//��next�ĵ�ַ������header��next֮��
	next->prev = lst->header;
	//��header�����next��prev֮��
	free(cur);
	//�ͷ�cur

	//ʹ�����ɾ������
	listErase(lst->header->next);
}

void listInsert(Node* pos, int data) {
	//��posλ��֮ǰ����ڵ�
	Node* node = creatNode(data);
	//��������ڵ�
	Node* front;
	//����ָ��
	front = pos->prev;
	//��Ҫ����λ�õ�prev�����front֮��
	front->next = node;
	//��node�ĵ�ַ���뵽front��next֮��
	node->prev = front;
	//��front�ĵ�ַ������node��prev֮��
	node->next = pos;
	//��pos������node��next֮��
	pos->prev = node;
	//��node�����pos��prev֮��
}


void listErase(Node* pos) {
	//ɾ��posλ�õĽڵ�
	Node* prev, * next;
	//��������ָ��
	if (pos->next == pos) {
		return; //�ձ���ɾ��
	}
	prev = pos->prev;
	//��prev�ĵ�ַ�����prev֮��
	next = pos->next;
	//��pos��next��ַ������next֮��
	prev->next = next;
	//��next�ĵ�ַ������prev��next֮��
	next->prev = prev;
	//��prev�ĵ�ַ������next��prev֮��
	free(pos);
	//�ͷ�pos
}

void listDesroy(List* lst) {

	//�ͷ�
	Node* cur = lst->header->next;
	//��curָ��head��next������ĵ�ַ
	while (cur != lst->header) {
		//��cur������header����պ�ѭ��һ��
		Node* next = cur->next;
		//��cur��next��ַ�����next֮��
		free(cur);
		//�ͷ�cur
		cur = next;
		//������curָ��next
	}
	free(lst->header);
	//�ͷ�ͷָ��
	lst->header = NULL;
	//ʹ��ָ���
}

