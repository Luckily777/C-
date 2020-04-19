#include "sort.h"

void heapSort(int* array, int n)
{
	//����  O(n)
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(array, n, i);
	}
	//����: ѭ��βɾ �� nlogn
	int size = n;
	while (size > 1)
	{
		//ѭ��βɾ
		Swap(array, 0, size - 1);
		--size;
		shiftDown(array, size, 0);
	}	
}