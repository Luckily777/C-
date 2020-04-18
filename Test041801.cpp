#include <stdio.h>
#include "heap.h"
#include "sort.h"
void test()
{
	Heap hp;
	int array[] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	heapCreat(&hp, array, sizeof(array) / sizeof(array[0]));
	heapPrint(&hp);
	heapPush(&hp, 80);
	heapPrint(&hp);
	printf("heapPop:\n");
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPush(&hp, 8);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPush(&hp, 100);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
}

void test2()
{
	Heap hp;
	int array[] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	heapCreat(&hp, array, sizeof(array) / sizeof(array[0]));
	heapPrint(&hp);

	while (heapEmpty(&hp) != 1)
	{
		printf("%d\n", heapTop(&hp));
		heapPop(&hp);
	}

}

void testSort()
{
	int array[] = { 30, 45, 15, 35, 36, 18,45, 45, 53, 72, 48, 93 };
	int n = sizeof(array) / sizeof(array[0]);
	heapSort(array, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	//test();
	//test2();
	testSort();
	return 0;
}
