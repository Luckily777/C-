�������Ľ����ͱ���


#include <stdio.h>
#include <stdlib.h>

//�ѽڵ�Ľ���
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
//�������ڵ�
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
//����������
Node* creatTree(char** str)
{
	if (*(*str) != '#')
		//�ж�����Ϊ�սڵ�
	{
		//�������ڵ�
		Node* root = (Node*)malloc(sizeof(Node));
		//����ڵ�ռ�
		root->val = *(*str);
		//���ַ����е�ֵ�������ڵ�ֵ
		++(*str);
		//�ַ��������1
		root->left = creatTree(str);
		//�������ݹ�
		++(*str);
		//�ַ��������1
		root->right = creatTree(str);
		//�������ݹ�
		return root;
	}
	else
		return NULL;
}

void inOrder(Node* root)
{
	if (root)
	{
		//��ӡ
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