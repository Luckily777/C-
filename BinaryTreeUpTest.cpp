#include <stdio.h>
#include "StackUp.h"
#include "BinaryTreeUp.h"

void testPre()
{
	char str[] = { "abc##de#g##f###" };
	int idx = 0;
	int num = 0;
	int num1 = 0;
	BTNode* root = BinaryTreeCreate(str, &idx);
	BinaryTreeSize2(root, &num);
	printf("%d", num);
	printf("\n");
	num1=BinaryTreeSize1(root);
	printf("%d", num1);
	printf("\n");




	//printf("pre :\n");
	//BinaryTreePrevOrder(root);
	//printf("\n");
	//printf("pre NoR: \n");
	//BinaryTreePrevOrderNoR(root);

	//printf("inO :\n");
	//BinaryTreeInOrder(root);
	//printf("\n");
	//printf("inO NoR: \n");
	//BinaryTreeInOrderNoR(root);

	//printf("post :\n");
	//BinaryTreePostOrder(root);
	//printf("\n");
	//printf("post NoR: \n");
	//BinaryTreePostOrderNoR(root);

	//printf("lever : ");
	//BinaryTreeLevelOrder(root);

	//int ret = BinaryTreeComplete(root);

}

void test2()
{
	char str[] = { "ABD##E##CF##G##" };
	int idx = 0;
	int num = 0;
	BTNode* root = BinaryTreeCreate(str, &idx);
	int ret = BinaryTreeComplete(root);
}

int main()
{
	testPre();
	/*test2();*/
	return 0;
}