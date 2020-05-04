#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "sort.h"

void printArray(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void test()
{
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	int* copy = (int*)malloc(sizeof(int)* size);
	memcpy(copy, array, sizeof(int)* size);

	int* copy2 = (int*)malloc(sizeof(int)* size);
	memcpy(copy2, array, sizeof(int)* size);

	int* copy3 = (int*)malloc(sizeof(int)* size);
	memcpy(copy3, array, sizeof(int)* size);

	printArray(array, size);
	insertSort(array, size);
	printf("insertSort: \n");
	printArray(array, size);

	shellSort(copy, size);
	printf("shellSort: \n");
	printArray(copy, size);

	selectSort(copy2, size);
	printf("selectSort: \n");
	printArray(copy2, size);

	selectSort2(copy3, size);
	printf("selectSort2: \n");
	printArray(copy3, size);
	
}

void testTime()
{
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)* n);
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand();
	}

	int* copy = (int*)malloc(sizeof(int)* n);
	memcpy(copy, array, sizeof(int)* n);

	int* copy2 = (int*)malloc(sizeof(int)* n);
	memcpy(copy2, array, sizeof(int)* n);

	int* copy3 = (int*)malloc(sizeof(int)* n);
	memcpy(copy3, array, sizeof(int)* n);

	size_t begin = clock();
	insertSort(array, n);
	size_t end = clock();
	printf("insertSort: %d\n", end - begin);

	begin = clock();
	insertSort(array, n);
	end = clock();
	printf("sorted insertSort: %d\n", end - begin);

	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("shellSort: %d\n", end - begin);

	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("sorted shellSort: %d\n", end - begin);

	begin = clock();
	selectSort(copy2, n);
	end = clock();
	printf("selectSort: %d\n", end - begin);

	begin = clock();
	selectSort(copy2, n);
	end = clock();
	printf("sorted selectSort: %d\n", end - begin);

	begin = clock();
	selectSort2(copy3, n);
	end = clock();
	printf("selectSort2: %d\n", end - begin);

}

int main()
{
	//test();
	testTime();
	return 0;
}