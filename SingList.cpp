#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//实现不带头单向非循环链表
typedef struct SingList
{
	Node* head; // head: 表示链表真正的头结点，即第一个有效的数据的位置
}SingList;


//SingListInit 初始化函数
void SingListInit(SingList* Sl) {
	Sl->head = NULL;
	//设置空链表
}

//CrearNode 创建节点
Node* CrearNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	//申请空间
	node->data = data;
	//将所给的data赋值到节点之中的数据上
	node->next = NULL;
	//将指向下一个节点的指针赋空
	return node;
	//返回所创建的node
}


// SingListPrint 打印链表之中的数组
void SingListPrint(SingList* Sl) {
	Node* cur = Sl->head;
	//将头链表的指针赋值给cur
	while (cur) {
		printf("%d ", cur->data);
		//打印所指向的第一个节点之中的数据
		cur = cur->next;
		//将此节点之中指向下一个节点的指针重新赋值给cur
	}
	printf("\n");
}


//SingListPushFront 头插函数
void SingListPushFront(SingList* Sl, int data) {
	Node* node = CrearNode(data);
	//创建一个节点
	if (Sl->head == NULL) {
		//如果是空链表
		Sl->head = node;
		//直接将创建出来的node地址赋给头链表的指针位置
	}
	else {
		node->next = Sl->head;
		//将头链表之中的位置给所创建的节点的指针
		Sl->head = node;
		//将所创建的节点的地址给头指针
	}
}



//SingListPopFront 头删函数
void SingListPopFront(SingList* Sl) {
	if (Sl->head) {
		//先进行判空
		Node* cur = Sl->head;
		//将头链表的位置给予Cur指针

		Sl->head = cur->next;
		//将头节点之中的指针所指向的地址给头节点
		free(cur);
		//释放头节点的空间
	}
}


//SingListPushBack 尾部插入函数 
void SingListPushBack(SingList* Sl, int data) {
	Node* node = CrearNode(data);
	//创建需要插入的节点
	if (Sl->head = NULL) {
		Sl->head = node;
		//如果链表为空，则直接将头链表的指针指向所创建链表的位置
	}
	else {
		Node* last = Sl->head;
		//将链表首地址赋给所创建的新last指针
		while (last->next) {
			//循环找到next指针为空的那个
			last = last->next;
		}
		last->next = node;
		//将所创建的节点位置给予所查找到的那个next指针
	}
}


//SingListPopBack 尾删函数
void SingListPopBack(SingList* Sl) {
	//找到最后一个节点，并且修改删除节点之前的前驱节点的执行
	if (Sl->head) {
		//头链表指针若不为零
		Node* prev = NULL;
		//prev节点为空
		Node* tail = Sl->head;
		//将头指针的位置给tail
		while (tail->next) {
			//当指针不为NULL
			prev = tail;
			//将此节点赋给prev
			tail = tail->next;
			//将指向下一个结点的指针给tail
		}
		if (tail == Sl->head) {
			//如果只有一个头链表
			Sl->head = NULL;
			//则头链表指向空
		}
		else {
			prev->next = NULL;
			//否则上一个前驱结点指向空
		}
		free(tail);
		//释放最后一个节点的空间

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