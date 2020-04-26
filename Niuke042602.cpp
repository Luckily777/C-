二叉树的建立和遍历


#include <stdio.h>
#include <stdlib.h>

//堆节点的建立
typedef struct Node
{
	struct Node* left;
	struct Node* right;
	char val;
}Node;

/*
Node* creatTree(char* str, int* idx)
{
if(str[*idx] != '#')
{
//建立根节点
Node* root = (Node*) malloc(sizeof(Node));
root->val = str[*idx];
++(*idx);
root->left = creatTree(str, idx);
++(*idx);
root->right = creatTree(str, idx);
return root;
}
else
return NULL;
}
*/



abc##de#g##f###
//创建二叉树
Node* creatTree(char** str)
{
	if (*(*str) != '#')
		//判断若不为空节点
	{
		//建立根节点
		Node* root = (Node*)malloc(sizeof(Node));
		//申请节点空间
		root->val = *(*str);
		//将字符串中的值赋给根节点值
		++(*str);
		//字符串往后加1
		root->left = creatTree(str);
		//左子树递归
		++(*str);
		//字符串往后加1
		root->right = creatTree(str);
		//右子树递归
		return root;
	}
	else
		return NULL;
}

void inOrder(Node* root)
{
	if (root)
	{
		//打印
		inOrder(root->left);
		printf("%c ", root->val);
		inOrder(root->right);
	}
}

int main()
{
	//char str[101] = {0};
	char* str = (char*)malloc(sizeof(char) * 101);
	scanf("%s", str);
	int idx = 0;
	//Node* root = creatTree(str, &idx);
	Node* root = creatTree(&str);

	inOrder(root);
	printf("\n");
	return 0;
}