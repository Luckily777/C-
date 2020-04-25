#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
/*
typedef struct BinaryTree
{
	BTNode* root;
}BinaryTree;
*/

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
void BianryTreeSize2(BTNode* root, int* num);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);


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
	//��ָ��root��ָ�봫��cur
	if (cur)
	{
		BinaryTreeDestory(&cur->_left);
		//����������
		BinaryTreeDestory(&cur->_right);
		//����������
		free(cur);
		//�ͷŸ��ڵ��ָ��
		*root = NULL;
		//��ָ��root����ָ��ĵ�ַ�ÿ�
		//��֤�˽��������е����нڵ���պ󣬲���ָ���������ָ��Ҳָ��շ�ֹҰָ��ĳ���
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
		//�Լ�����ģʽ�����нڵ�����ļ���
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
	//ÿһ����μ�һ �����еݹ����
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
