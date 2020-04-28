#pragma once
#include <stdlib.h>
#include <stdio.h>

//������

typedef char BTdataTyde;

//���������
typedef struct BinaryTreeNode {
	BTdataTyde data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//�������Ĵ���
BTNode* BinaryTreeCreate(BTdataTyde* a, int* pi);

//���������ٺ���
void BinaryTreeDestory(BTNode** root);

//�������ڵ����ͳ�ƺ���1
int BinaryTreeSize1(BTNode* root);


//�������ڵ����ͳ�ƺ���2
void BinaryTreeSize2(BTNode* root, int* num);

//��������Ҷ�ӽڵ����ͳ�ƺ���
int BinaryTreeLeafSize(BTNode* root);

//��������K��ڵ����ͳ�ƺ���
int BinaryTreeLevelKSize(BTNode* root, int k);


//����������ֵΪx�Ľڵ㺯��
BTNode* BinaryTreeFind(BTNode* root, BTdataTyde x);

//��������ǰ������������ݹ飩
void BinaryTreePrevOrder(BTNode* root);
//��������ǰ������������ǵݹ飩
void BinaryTreePrevOrderNoR(BTNode* root);


//����������������������ݹ飩
void BinaryTreeInOrder(BTNode* root);
//����������������������ǵݹ飩
void BinaryTreeInOrderNoR(BTNode* root);


//�������ĺ�������������ݹ飩
void BinaryTreePostOrder(BTNode* root);
//�������ĺ�������������ǵݹ飩
void BinaryTreePostOrderNoR(BTNode* root);

//�������
void BinaryTreeLevelOrder(BTNode* root);

//�ж϶������Ƿ���ȫ������
int BinaryTreeComplete(BTNode* root);