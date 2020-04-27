#include "binaryTree.h"
#include "Stack.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
		return NULL;
}

void BinaryTreeDestory(BTNode** root)
{
	BTNode* cur = *root;
	if (cur)
	{
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
		*root = NULL;
	}
}
/*
// 二叉树节点个数: 左右子树的节点 + 1
// 遍历， 累加计数器
// int BinaryTreeSize(BTNode* root);
*/
void BianryTreeSize2(BTNode* root, int* num)
{
	if (root)
	{
		++(*num);
		BianryTreeSize2(root->_left, num);
		BianryTreeSize2(root->_right, num);
	}
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//空树
	if (root == NULL)
		return 0;
	//叶子节点
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//空树： 0
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	//空树找不到
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	//查找左右子树
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;

	return BinaryTreeFind(root->_right, x);

}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreePrevOrderNoR(BTNode* root)
{
	//借助栈模拟递归过程
	Stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			//前序遍历，访问当前节点
			printf("%c ", cur->_data);
			//当前节点入栈
			stackPush(&st, cur);
			cur = cur->_left;
		}

		//获取栈顶元素
		top = stackTop(&st);
		stackPop(&st);
		//访问右子树
		cur = top->_right;
	}
	printf("\n");
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
void BinaryTreeInOrderNoR(BTNode* root)
{
	//借助栈模拟递归过程
	Stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			//当前节点入栈
			stackPush(&st, cur);
			cur = cur->_left;
		}

		//获取栈顶元素
		top = stackTop(&st);
		stackPop(&st);
		//中序遍历，访问当前节点
		printf("%c ", top->_data);
		//访问右子树
		cur = top->_right;
	}
	printf("\n");
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}
void BinaryTreePostOrderNoR(BTNode* root)
{
	//借助栈模拟递归过程
	Stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	//prev: 最后一次访问的位置
	BTNode* prev = NULL;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			//当前节点入栈
			stackPush(&st, cur);
			cur = cur->_left;
		}
		//获取栈顶元素
		top = stackTop(&st);
		//判断右子树是否访问完成
		//没有右子树或者右子树已经访问完成
		if (top->_right == NULL || top->_right == prev)
		{
			//访问当前节点
			printf("%c ", top->_data);
			stackPop(&st);
			//更新最后一次访问的位置
			prev = top;
		}
		else
			cur = top->_right;  //右子树还没有访问，需要先访问右子树
		
	}
	printf("\n");
}

void BinaryTreeLevelOrder(BTNode* root)
{
	//队列从左向后，从上到下，保存每一层的节点
	Queue q;
	queueInit(&q);
	//根元素入队
	if (root)
		queuePush(&q, root);
	//队列不为空，继续遍历
	while (queueEmpty(&q) != 1)
	{
		//获取队头元素
		BTNode* front = queueFront(&q);
		queuePop(&q);
		//访问队头元素
		printf("%c ", front->_data);
		//孩子入队, 先左后右
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (queueEmpty(&q) != 1)
	{
		//队头出队
		BTNode* front = queueFront(&q);
		queuePop(&q);
		//如果队头不为空，孩子直入队
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break; //停止入队
	}
	//判断队列中剩余元素是否都为空节点
	while (queueEmpty(&q) != 1)
	{
		BTNode* front = queueFront(&q);
		queuePop(&q);
		if (front)
		{
			//剩余元素中有非空节点，说明不是一棵完全二叉树
			return 0;
		}
	}
	//剩余元素都为空节点,是一棵完全二叉树
	return 1;
}