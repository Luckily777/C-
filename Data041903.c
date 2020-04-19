#include "sort.h"

void heapSort(int* array, int n)
{
	//½¨¶Ñ  O(n)
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(array, n, i);
	}
	//ÅÅÐò: Ñ­»·Î²É¾ £º nlogn
	int size = n;
	while (size > 1)
	{
		//Ñ­»·Î²É¾
		Swap(array, 0, size - 1);
		--size;
		shiftDown(array, size, 0);
	}	
}