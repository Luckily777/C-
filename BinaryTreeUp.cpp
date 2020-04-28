#include "BinaryTreeUp.h"
#include "QueueUp.h"
#include "StackUp.h"
#include <stdio.h>
#include <stdlib.h>

//�������Ĵ���
BTNode* BinaryTreeCreate(BTdataTyde* a, int* pi) {
	if (a[*pi] != '#') {
		//���ڵ�ֵ��Ϊ��
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		//������ڵ�ռ�
		root->data = a[*pi];
		//������ֵ��ֵ�����ڵ�
		(*pi)++;
		//֮�������ַ++
		root->left = BinaryTreeCreate(a, pi);
		//���������еݹ鸳ֵ
		(*pi)++;
		//�����ַ��Ȼ++
		root->right = BinaryTreeCreate(a, pi);
		//���������еݹ鸳ֵ
		//���������֮���õ�ַ++����Ϊ���������֮�󷵻ظ��ڵ�
		return root;
	}
	else {
		return NULL;
		//������ֵΪ�գ��򷵻ؿ�
	}
}

//���������ٺ���
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	//����һ��ָ��
	if (cur) {
		BinaryTreeDestory(&cur->left);
		//���������ĵ�ַ�ݹ鴫�����ٺ���
		BinaryTreeDestory(&cur->right);
		//���������ĵ�ַ�ݹ鴫�ݽ����ٺ���
		free(cur);
		//�ͷ�curָ��
		*root = NULL;
		//��*rootָ��ָ���
	}
}

//�������ڵ����ͳ�ƺ���1
//���������Ľڵ�+1 

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


//�������ڵ����ͳ�ƺ���2
void BinaryTreeSize2(BTNode* root, int* num) {
	if (root)
	{
		++(*num);
		BinaryTreeSize2(root->left, num);
		BinaryTreeSize2(root->right, num);
	}
}

//��������Ҷ�ӽڵ����ͳ�ƺ���
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

//��������K��ڵ����ͳ�ƺ���
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
		//��������Ϊ�գ���ڵ����Ϊ0
	}
	if (k == 1) {
		return 1;
		//���ǵ�һ�㣬��ڵ���Ϊ1
	}
	return BinaryTreeLevelKSize(root->left, k - 1) 
		+ BinaryTreeLevelKSize(root->right, k - 1);
	//������½��У���k��μ�һ���еݹ����
}


//����������ֵΪx�Ľڵ㺯��
BTNode* BinaryTreeFind(BTNode* root, BTdataTyde x) {
	BTNode* ret;
	if (root == NULL) {
		//��������Ϊ�գ���λ��Ϊ��
		return NULL;
	}
	if (root->data == x) {
		return root;
		//�����ڵ����x���򷵻ظ��ڵ�
	}
	ret = BinaryTreeFind(root->left, x);
	//��������������ı���
	if (ret) {
		return ret;
		//���������ܹ��ҵ����򷵻�������
	}
	return BinaryTreeFind(root->right, x);
	//����ֱ�ӷ���������
}

//��������ǰ������������ݹ飩
void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c", root->data);
		//�ȴ�ӡ���ڵ�
		BinaryTreePrevOrder(root->left);
		//�������ݹ�
		BinaryTreePrevOrder(root->right);
		//�������ݹ�
	}
}
//��������ǰ������������ǵݹ飩
void BinaryTreePrevOrderNoR(BTNode* root) {
	//����ջ������ģ��ݹ�Ĺ���ʵ��ǰ�����
	Stack st;
	//����ջ
	StackInit(&st, 10);
	//ջ���г�ʼ��
	BTNode* cur = root;
	//ָ�����ָ��root
	BTNode* top;
	//��������
	while (cur || StackEmpty(&st) != 1) {
		//��cur��ջ����Ϊ��
		while (cur) {
			printf("%c", cur->data);
			//��ӡ���ڵ��ֵ
			StackPush(&st, cur);
			//������ջ
			cur = cur->left;
			//���뵽������֮��
		}
		top = StackTop(&st);
		//ȡ��ջ��Ԫ��
		StackPop(&st);
		//ɾ��ջ��Ԫ��
		cur = top->right;
		//ָ��������
	}
	printf("\n");

}


//����������������������ݹ飩
void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreeInOrder(root->left);
		//���еݹ�������
		printf("%c", root->data);
		//��ӡ���ڵ�
		BinaryTreeInOrder(root->right);
		//�ٵݹ�������
	}
}

//����������������������ǵݹ飩
void BinaryTreeInOrderNoR(BTNode* root) {
	//����ջ������ģ��ݹ�Ĺ���ʵ���������
	Stack st;
	//����ջ
	StackInit(&st, 10);
	//ջ���г�ʼ��
	BTNode* cur = root;
	//ָ�����ָ��root
	BTNode* top;
	//��������
	while (cur || StackEmpty(&st) != 1) {
		//��cur��ջ����Ϊ��
		while (cur) {
			StackPush(&st, cur);
			//������ջ
			cur = cur->left;
			//���뵽������֮��
		}
		top = StackTop(&st);
		//ȡ��ջ��Ԫ��
		StackPop(&st);
		//ɾ��ջ��Ԫ��
		printf("%c", top->data);
		//��ӡ���ڵ��ֵ
		cur = top->right;
		//ָ��������
	}
	printf("\n");
}


//�������ĺ�������������ݹ飩
void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		BinaryTreePostOrder(root->left);
		BinaryTreePostOrder(root->right);
		printf("%c", root->data);

	}
}
//�������ĺ�������������ǵݹ飩
void BinaryTreePostOrderNoR(BTNode* root) {
	//����ջ������ģ��ݹ�Ĺ���ʵ�ֺ������
	Stack st;
	//����ջ
	StackInit(&st, 10);
	//ջ���г�ʼ��
	BTNode* cur = root;
	//ָ�����ָ��root
	BTNode* top;
	//��������
	BTNode* prev = NULL;
	//�����м�������Կ���ջ��Ԫ���ǵڼ��η���
	while (cur || StackEmpty(&st) != 1) {
		//��cur��ջ����Ϊ��
		while (cur) {
			StackPush(&st, cur);
			//������ջ
			cur = cur->left;
			//���뵽������֮��
		}
		top = StackTop(&st);
		//ȡ��ջ��Ԫ��
		if (top->right == NULL || top->right == prev) {
			//��������Ϊ�գ������Ѿ����ʹ�һ��������
			printf("%c", top->data);
			//��ӡ��ǰ�ڵ�
			StackPop(&st);
			//ɾ��ջ��Ԫ��
			prev = top;
			//��prev��ָ�����
		}
		else {
			cur = top->right;
			//ָ��������
		}
	}
	printf("\n");
}

//�������
void BinaryTreeLevelOrder(BTNode* root) {
	//һ���������ң����ϵ��µĶ��У�����ÿһ��Ľڵ���
	Queue q;
	//��������
	QueueInit(&q);
	//��ʼ������
	if (root) {
		QueuePush(&q, root);
		//���������ڵ����
	}
	while (QueueEmpty(&q) != 1) {
		//��������Ϊ��
		BTNode* front = QueueFront(&q);
		//����ָ�����ָ����ж�ͷԪ��
		QueuePop(&q);
		//���г��Ӳ���
		printf("%c", front->data);
		//����ͷ�ڵ�Ԫ�ش�ӡ����
		if (front->left) {
			QueuePush(&q, front->left);
			//��ͷ��������ջ
		}
		if (front->right) {
			QueuePush(&q, front->right);
			//��ͷ��������ջ
		}
	}
	printf("\n");
}

//�ж϶������Ƿ���ȫ������
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	//��������
	QueueInit(&q);
	//��ʼ������
	if (root) {
		QueuePush(&q, root);
		//���������ڵ����
	}
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		//ָ��ָ����ж�ͷԪ��
		QueuePop(&q);
		//���г��Ӳ���
		if (front) {
			QueuePush(&q, front->left);
			//������
			QueuePush(&q, front->right);
			//�ұ����
		}
		else {
			break;
		}
	}
	while (QueueEmpty(&q) != 1) {
		BTNode* front = QueueFront(&q);
		//��ȡ��ͷԪ��
		QueuePop(&q);
		//���Ӳ���
		if (front) {
			//ʣ��Ԫ��֮�д����κ�һ���ǿսڵ㣬��˵������һ����ȫ������
			return 0;
			//��ָ��Ϊ�գ���Ϊ0
		}
	}
	//ʣ��ڵ�ȫ��Ϊ�սڵ㣬��Ϊ��ȫ������
	return 1;
}