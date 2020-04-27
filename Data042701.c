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
// �������ڵ����: ���������Ľڵ� + 1
// ������ �ۼӼ�����
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

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	//����
	if (root == NULL)
		return 0;
	//Ҷ�ӽڵ�
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//������ 0
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	//�����Ҳ���
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	//������������
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
	//����ջģ��ݹ����
	Stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			//ǰ����������ʵ�ǰ�ڵ�
			printf("%c ", cur->_data);
			//��ǰ�ڵ���ջ
			stackPush(&st, cur);
			cur = cur->_left;
		}

		//��ȡջ��Ԫ��
		top = stackTop(&st);
		stackPop(&st);
		//����������
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
	//����ջģ��ݹ����
	Stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			//��ǰ�ڵ���ջ
			stackPush(&st, cur);
			cur = cur->_left;
		}

		//��ȡջ��Ԫ��
		top = stackTop(&st);
		stackPop(&st);
		//������������ʵ�ǰ�ڵ�
		printf("%c ", top->_data);
		//����������
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
	//����ջģ��ݹ����
	Stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* top;
	//prev: ���һ�η��ʵ�λ��
	BTNode* prev = NULL;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			//��ǰ�ڵ���ջ
			stackPush(&st, cur);
			cur = cur->_left;
		}
		//��ȡջ��Ԫ��
		top = stackTop(&st);
		//�ж��������Ƿ�������
		//û�������������������Ѿ��������
		if (top->_right == NULL || top->_right == prev)
		{
			//���ʵ�ǰ�ڵ�
			printf("%c ", top->_data);
			stackPop(&st);
			//�������һ�η��ʵ�λ��
			prev = top;
		}
		else
			cur = top->_right;  //��������û�з��ʣ���Ҫ�ȷ���������
		
	}
	printf("\n");
}

void BinaryTreeLevelOrder(BTNode* root)
{
	//���д�����󣬴��ϵ��£�����ÿһ��Ľڵ�
	Queue q;
	queueInit(&q);
	//��Ԫ�����
	if (root)
		queuePush(&q, root);
	//���в�Ϊ�գ���������
	while (queueEmpty(&q) != 1)
	{
		//��ȡ��ͷԪ��
		BTNode* front = queueFront(&q);
		queuePop(&q);
		//���ʶ�ͷԪ��
		printf("%c ", front->_data);
		//�������, �������
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
		//��ͷ����
		BTNode* front = queueFront(&q);
		queuePop(&q);
		//�����ͷ��Ϊ�գ�����ֱ���
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break; //ֹͣ���
	}
	//�ж϶�����ʣ��Ԫ���Ƿ�Ϊ�սڵ�
	while (queueEmpty(&q) != 1)
	{
		BTNode* front = queueFront(&q);
		queuePop(&q);
		if (front)
		{
			//ʣ��Ԫ�����зǿսڵ㣬˵������һ����ȫ������
			return 0;
		}
	}
	//ʣ��Ԫ�ض�Ϊ�սڵ�,��һ����ȫ������
	return 1;
}