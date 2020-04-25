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
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
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
	//将指向root的指针传进cur
	if (cur)
	{
		BinaryTreeDestory(&cur->_left);
		//销毁左子树
		BinaryTreeDestory(&cur->_right);
		//销毁右子树
		free(cur);
		//释放根节点的指针
		*root = NULL;
		//将指针root中所指向的地址置空
		//保证了将二叉树中的所有节点清空后，并将指向二叉树的指针也指向空防止野指针的出现
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
		//以计数的模式来进行节点个数的计算
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
	//每一层逐次减一 俩进行递归查找
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
