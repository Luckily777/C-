#include "BinaryTreeUp.h"
#include "QueueUp.h"
#include "StackUp.h"
#include <stdio.h>
#include <stdlib.h>

//二叉树的创建
BTNode* BinaryTreeCreate(BTdataTyde* a, int* pi) {
	if (a[*pi] != '#') {
		//若节点值不为空
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		//申请根节点空间
		root->data = a[*pi];
		//将数组值赋值给根节点
		(*pi)++;
		//之后数组地址++
		root->left = BinaryTreeCreate(a, pi);
		//左子树进行递归赋值
		(*pi)++;
		//数组地址依然++
		root->right = BinaryTreeCreate(a, pi);
		//右子树进行递归赋值
		//右子树完毕之后不用地址++，因为右子树完毕之后返回根节点
		return root;
	}
	else {
		return NULL;
		//若数组值为空，则返回空
	}
}

//二叉树销毁函数
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	//传进一级指针
	if (cur) {
		BinaryTreeDestory(&cur->left);
		//将左子树的地址递归传进销毁函数
		BinaryTreeDestory(&cur->right);
		//将右子树的地址递归传递进销毁函数
		free(cur);
		//释放cur指针
		*root = NULL;
		//将*root指针指向空
	}
}

//二叉树节点个数统计函数1
//左右子树的节点+1 

int BinaryTreeSize1(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return BinaryTreeSize1(root->left) +
		BinaryTreeSize1(root->right) + 1;
}


//二叉树节点个数统计函数2
void BinaryTreeSize2(BTNode* root, int* num) {
	if (root)
	{
		++(*num);
		BinaryTreeSize2(root->left, num);
		BinaryTreeSize2(root->right, num);
	}
}

//二叉树的叶子节点个数统计函数
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->left) +
		BinaryTreeLeafSize(root->right);
}

//二叉树第K层节点个数统计函数
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
		//若二叉树为空，则节点个数为0
	}
	if (k == 1) {
		return 1;
		//若是第一层，则节点数为1
	}
	return BinaryTreeLevelKSize(root->left, k - 1) 
		+ BinaryTreeLevelKSize(root->right, k - 1);
	//逐次往下进行，则k逐次减一进行递归计算
}


//二叉树查找值为x的节点函数
BTNode* BinaryTreeFind(BTNode* root, BTdataTyde x) {
	BTNode* ret;
	if (root == NULL) {
		//若二叉树为空，则位置为空
		return NULL;
	}
	if (root->data == x) {
		return root;
		//若根节点等于x，则返回根节点
	}
	ret = BinaryTreeFind(root->left, x);
	//否则进行左子树的遍历
	if (ret) {
		return ret;
		//若左子树能够找到，则返回左子树
	}
	return BinaryTreeFind(root->right, x);
	//否则直接返回右子树
}

//二叉树的前序遍历函数（递归）
void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c", root->data);
		//先打印根节点
		BinaryTreePrevOrder(root->left);
		//左子树递归
		BinaryTreePrevOrder(root->right);
		//右子树递归
	}
}
//二叉树的前序遍历函数（非递归）
void BinaryTreePrevOrderNoR(BTNode* root) {
	//借助栈来进行模拟递归的过程实现前序遍历
	Stack st;
	//创建栈
	StackInit(&st, 10);
	//栈进行初始化
	BTNode* cur = root;
	//指针变量指向root
	BTNode* top;
	//顶部变量
	while (cur || StackEmpty(&st) != 1) {
		//若cur和栈都不为空
		while (cur) {
			printf("%c", cur->data);
			//打印根节点的值
			StackPush(&st, cur);
			//将其入栈
			cur = cur->left;
			//进入到左子树之中
		}
		top = StackTop(&st);
		//取出栈中元素
		StackPop(&st);
		//删除栈顶元素
		cur = top->right;
		//指向右子树
	}
	printf("\n");

}


//二叉树的中序遍历函数（递归）
void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreeInOrder(root->left);
		//先行递归左子树
		printf("%c", root->data);
		//打印根节点
		BinaryTreeInOrder(root->right);
		//再递归右子树
	}
}

//二叉树的中序遍历函数（非递归）
void BinaryTreeInOrderNoR(BTNode* root) {
	//借助栈来进行模拟递归的过程实现中序遍历
	Stack st;
	//创建栈
	StackInit(&st, 10);
	//栈进行初始化
	BTNode* cur = root;
	//指针变量指向root
	BTNode* top;
	//顶部变量
	while (cur || StackEmpty(&st) != 1) {
		//若cur和栈都不为空
		while (cur) {
			StackPush(&st, cur);
			//将其入栈
			cur = cur->left;
			//进入到左子树之中
		}
		top = StackTop(&st);
		//取出栈中元素
		StackPop(&st);
		//删除栈顶元素
		printf("%c", top->data);
		//打印根节点的值
		cur = top->right;
		//指向右子树
	}
	printf("\n");
}


//二叉树的后序遍历函数（递归）
void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		BinaryTreePostOrder(root->left);
		BinaryTreePostOrder(root->right);
		printf("%c", root->data);

	}
}
//二叉树的后序遍历函数（非递归）
void BinaryTreePostOrderNoR(BTNode* root) {
	//借助栈来进行模拟递归的过程实现后序遍历
	Stack st;
	//创建栈
	StackInit(&st, 10);
	//栈进行初始化
	BTNode* cur = root;
	//指针变量指向root
	BTNode* top;
	//顶部变量
	BTNode* prev = NULL;
	//设置中间变量，以考察栈顶元素是第几次访问
	while (cur || StackEmpty(&st) != 1) {
		//若cur和栈都不为空
		while (cur) {
			StackPush(&st, cur);
			//将其入栈
			cur = cur->left;
			//进入到左子树之中
		}
		top = StackTop(&st);
		//取出栈中元素
		if (top->right == NULL || top->right == prev) {
			//若右子树为空，或者已经访问过一次右子树
			printf("%c", top->data);
			//打印当前节点
			StackPop(&st);
			//删除栈顶元素
			prev = top;
			//将prev的指针更新
		}
		else {
			cur = top->right;
			//指向右子树
		}
	}
	printf("\n");
}

//层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
	//一个从左向右，从上到下的队列，保护每一层的节点数
	Queue q;
	//创建队列
	QueueInit(&q);
	//初始化队列
	if (root) {
		QueuePush(&q, root);
		//二叉树根节点入队
	}
	while (QueueEmpty(&q) != 1) {
		//队列若不为空
		BTNode* front = QueueFront(&q);
		//设置指针变量指向队列队头元素
		QueuePop(&q);
		//队列出队操作
		printf("%c", front->data);
		//将队头节点元素打印出来
		if (front->left) {
			QueuePush(&q, front->left);
			//队头左子树入栈
		}
		if (front->right) {
			QueuePush(&q, front->right);
			//对头右子树入栈
		}
	}
	printf("\n");
}

//判断二叉树是否完全二叉树
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	//创建队列
	QueueInit(&q);
	//初始化队列
	if (root) {
		QueuePush(&q, root);
		//二叉树根节点入队
	}
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		//指针指向队列队头元素
		QueuePop(&q);
		//队列出队操作
		if (front) {
			QueuePush(&q, front->left);
			//左边入队
			QueuePush(&q, front->right);
			//右边入队
		}
		else {
			break;
		}
	}
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		//获取队头元素
		QueuePop(&q);
		//出队操作
		if (front) {
			//剩余元素之中存在任何一个非空节点，则说明不是一颗完全二叉树
			return 0;
			//若指针为空，则为0
		}
	}
	//剩余节点全部为空节点，则为完全二叉树
	return 1;
}