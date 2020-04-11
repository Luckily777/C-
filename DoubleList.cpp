#include <stdlib.h>
#include <stdio.h>

//定义节点结构体
typedef struct Node
{
	int data;
	//存储的数据
	struct Node* next;
	//指向下一个节点
	struct Node* prev;
	//指向上一个节点

}Node;

//定义链表
typedef struct List
{
	Node* header;
	//头节点
}List;

// 打印函数
void printList(List* lst) {
	Node* cur;
	//创建节点变量
	cur = lst->header->next;
	//使其指向header的next地址
	while (cur != lst->header) {
		printf("%d ", cur->data);
		//打印其中的data
		cur = cur->next;
		//后移一位
	}
	printf("\n");
}

//初始化函数
void listInit(List* lst) {
	lst->header = creatNode(0);
	//使得header指向新创建的节点
	lst->header->next = lst->header;
	//使得其next和prev都指向其本身
	lst->header->prev = lst->header;
}

//创建新变量函数
Node* creatNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	//为node申请一个新的Node大小的空间
	node->data = data;
	//将所给予的data值赋值给node的data
	node->next = node->prev = NULL;
	//next和prev全部指向空
	return node;
	//返回node
}

//尾插函数
void listPushBack(List* lst, int data) {
	Node* last = lst->header->prev;
	//创建last指针指向header的前一个节点
	Node* node = creatNode(data);
	//为data创建新的节点准备进行插入
	last->next = node;
	//last的next中存放node的地址
	node->prev = last;

	//node的prev中存放last的地址
	node->next = lst->header;
	//将lst的header的地址放置到node的next中
	lst->header->prev = node;
	//将node的地址放置到header的prev中

	//使用随机插入函数
	listInsert(lst->header, data);
}


void listPopBack(List* lst) {
	if (lst->header->next == lst->header) {
		//不能删除header头，因此如果等于，则表示空链表
		return;
	}
	Node* last, * prev;
	//创建两个节点指针变量
	last = lst->header->prev;
	//last中存放header前一个节点的地址
	prev = last->prev;
	//prev中存放last前一个节点的地址
	prev->next = lst->header;
	//prev的next之中存放头节点的地址
	lst->header->prev = prev;
	//header的prev中存放prev的地址
	free(last);
	//释放last

	//使用随机删除函数
	listErase(lst->header->prev);
}

void listPushFront(List* lst, int data) {
	//
	Node* node = creatNode(data);
	//创建需要插入的节点
	Node* next;
	//创建新的next指针变量
	next = lst->header->next;
	//将header中的next地址存放在next之中
	lst->header->next = node;
	//将node存放在header的next之中
	node->prev = lst->header;
	//将header的地址存放在node的prev之中
	node->next = next;
	//将next存放在node的next之中
	next->prev = node;
	//将node存放在next的prev之中

	//使用随机插入函数
	listInsert(lst->header->next, data);
}
void listPopFront(List* lst) {
	if (lst->header->next = lst->header) {
		return;
		//若仅仅只有header，则表示空链，不进行删除
	}
	Node* next,*cur;
	//创建两个变量
	cur = lst->header->next;
	//将header的next地址保存在cur
	next = cur->next;
	//将cur的next给予到next之中
	lst->header->next = next;
	//将next的地址保存在header的next之中
	next->prev = lst->header;
	//将header存放在next的prev之中
	free(cur);
	//释放cur

	//使用随机删除函数
	listErase(lst->header->next);
}

void listInsert(Node* pos, int data) {
	//在pos位置之前插入节点
	Node* node = creatNode(data);
	//创建插入节点
	Node* front;
	//创建指针
	front = pos->prev;
	//将要插入位置的prev存放在front之中
	front->next = node;
	//将node的地址给与到front的next之中
	node->prev = front;
	//将front的地址保存在node的prev之中
	node->next = pos;
	//将pos保存在node的next之中
	pos->prev = node;
	//将node存放在pos的prev之中
}


void listErase(Node* pos) {
	//删除pos位置的节点
	Node* prev, * next;
	//创建两个指针
	if (pos->next == pos) {
		return; //空表不能删除
	}
	prev = pos->prev;
	//将prev的地址存放在prev之中
	next = pos->next;
	//将pos的next地址保存在next之中
	prev->next = next;
	//将next的地址保存在prev的next之中
	next->prev = prev;
	//将prev的地址保存在next的prev之中
	free(pos);
	//释放pos
}

void listDesroy(List* lst) {

	//释放
	Node* cur = lst->header->next;
	//让cur指向head的next所保存的地址
	while (cur != lst->header) {
		//若cur不等于header，则刚好循环一周
		Node* next = cur->next;
		//将cur的next地址存放在next之中
		free(cur);
		//释放cur
		cur = next;
		//重新让cur指向next
	}
	free(lst->header);
	//释放头指针
	lst->header = NULL;
	//使其指向空
}

