#pragma once

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
void BinaryTreePrevOrderNoR(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
void BinaryTreeInOrderNoR(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
void BinaryTreePostOrderNoR(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);