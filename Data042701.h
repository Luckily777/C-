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
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
void BianryTreeSize2(BTNode* root, int* num);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreePrevOrderNoR(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
void BinaryTreeInOrderNoR(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
void BinaryTreePostOrderNoR(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);