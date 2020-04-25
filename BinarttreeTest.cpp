#include <stdio.h>
#include "binaryTree.h"

void test()
{
	char str[] = { "abc##de#g##f###" };
	int idx = 0;
	int num = 0;
	BTNode* root = BinaryTreeCreate(str, &idx);
	BianryTreeSize2(root, &num);
	printf("%d\n", num);
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root, 1));
	printf("%d\n", BinaryTreeLevelKSize(root, 2));
	printf("%d\n", BinaryTreeLevelKSize(root, 3));
	printf("%d\n", BinaryTreeLevelKSize(root, 4));
	printf("%d\n", BinaryTreeLevelKSize(root, 5));
	printf("%d\n", BinaryTreeLevelKSize(root, 6));
	printf("%d\n", BinaryTreeLevelKSize(root, 7));
	BTNode* ret = BinaryTreeFind(root, 'c');

	ret = BinaryTreeFind(root, 'h');

	BinaryTreeDestory(&root);
}

int main()
{
	test();
	return 0;
}