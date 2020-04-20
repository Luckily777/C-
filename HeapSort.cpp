
推排序

void heapSort(int* array, int n)
{
	//建堆  O(n)
	for (int i = (n - 2) / 2; i >= 0; --i)
		//先找到父节点，以此为根找到其中较大或较小的值放置在根部
	{
		shiftDown(array, n, i);
	}
	//排序: 循环尾删 ： nlogn
	int size = n;
	while (size > 1)
	{
		//循环尾删
		Swap(array, 0, size - 1);
		//将最顶部的跟和最后一个叶子进行交换
		--size;
		//size减减
		shiftDown(array, size, 0);
		//再次进行下调操作
	}
}