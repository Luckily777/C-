#pragma once
#include <stdlib.h>
#include <stdio.h>

//二叉树

typedef char BTdataTyde;

//二叉树结点
typedef struct BinaryTreeNode {
	BTdataTyde data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//二叉树的创建
BTNode* BinaryTreeCreate(BTdataTyde* a, int* pi);

//二叉树销毁函数
void BinaryTreeDestory(BTNode** root);

//二叉树节点个数统计函数1
int BinaryTreeSize1(BTNode* root);


//二叉树节点个数统计函数2
void BinaryTreeSize2(BTNode* root, int* num);

//二叉树的叶子节点个数统计函数
int BinaryTreeLeafSize(BTNode* root);

//二叉树第K层节点个数统计函数
int BinaryTreeLevelKSize(BTNode* root, int k);


//二叉树查找值为x的节点函数
BTNode* BinaryTreeFind(BTNode* root, BTdataTyde x);

//二叉树的前序遍历函数（递归）
void BinaryTreePrevOrder(BTNode* root);
//二叉树的前序遍历函数（非递归）
void BinaryTreePrevOrderNoR(BTNode* root);


//二叉树的中序遍历函数（递归）
void BinaryTreeInOrder(BTNode* root);
//二叉树的中序遍历函数（非递归）
void BinaryTreeInOrderNoR(BTNode* root);


//二叉树的后序遍历函数（递归）
void BinaryTreePostOrder(BTNode* root);
//二叉树的后序遍历函数（非递归）
void BinaryTreePostOrderNoR(BTNode* root);

//层序遍历
void BinaryTreeLevelOrder(BTNode* root);

//判断二叉树是否完全二叉树
int BinaryTreeComplete(BTNode* root);