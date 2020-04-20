#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	//定义动态数组
	int _size;
	//个数
	int _capacity;
	//容量
}Heap;


void Swap(HPDataType* array, int left, int right)
{
	int tmp = array[left];

	array[left] = array[right];
	array[right] = tmp;
}


void heapCreat(Heap* hp, HPDataType* array, int size)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = size;

	//建堆, 从最后一个非叶子节点开始建堆  (size - 2) / 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, size, parent);
	}
}


//大堆的向下调整
// parent: 起始调整的位置
void shiftDown(HPDataType* array, int size, int parent)
{
	//左孩子位置
	int child = 2 * parent + 1;
	while (child < size)
	{
		//从左右孩子孩子中选一个最大
		if (child + 1 < size && array[child + 1] > array[child])
			++child;
		//和父节点比较
		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			//更新
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//大堆向上调整
void shiftUp(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			//结束调整
			break;
	}

}

void shiftDownL(HPDataType* array, int size, int parent)
{
	//左孩子位置
	int child = 2 * parent + 1;
	while (child < size)
	{
		//从左右孩子孩子中选一个最小
		if (child + 1 < size && array[child + 1] < array[child])
			++child;
		//和父节点比较
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			//更新
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//小堆向上调整
void shiftUpL(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			//结束调整
			break;
	}

}

void heapPush(Heap* hp, HPDataType data)
{
	//检查容量
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		//进行扩容
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		//数组续接
	}
	//尾插
	hp->_array[hp->_size++] = data;
	//将元素插入到数组最后一个元素之中
	shiftUp(hp->_array, hp->_size - 1);
	//进行上调整
}
//删除堆顶元素，删除最值
void heapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		// 交换: 堆顶和最后一个叶子
		Swap(hp->_array, 0, hp->_size - 1);
		// 尾删： 实际上删除的即为堆顶元素
		hp->_size--;
		//向下调整
		shiftDown(hp->_array, hp->_size, 0);
	}
}

HPDataType heapTop(Heap* hp)
{
	return hp->_array[0];
}

int heapEmpty(Heap* hp)
//判空函数
{
	if (hp->_size == 0)
		return 1;
	return 0;
}


void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}