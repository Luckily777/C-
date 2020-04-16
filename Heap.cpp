#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	//动态数组
	int _size;
	//大小
	int _capacity;
	//容量
}Heap;

//交换函数
void Swap(HPDataType* array, int left, int right) {
	int temp = array[left];
	//将左边值赋给中间变量
	array[left] = array[right];
	//右边值赋给左边
	array[right] = temp;
	//中间变量赋给右边
}


//向下调整函数
void shiftDown(HPDataType* array, int size, int parent) {
	int child = 2 * parent + 1;
	//子节点等于二倍的父节点+1
	while (child < size) {
		if (child + 1 < size && array[child + 1] < array[child]) {
			//若右边的子节点小于左边的子节点，则将child++
			child++;
		}
		if (array[child] < array[parent]) {
			//若子节点比父节点小
			Swap(array, child, parent);
			//交换子节点和父节点
			parent = child;
			//将子节点赋给父节点
			child = 2 * parent + 1;
			//重新计算子节点
		}
		else {
			break;
		}
	}

}

//向上调整函数
void shiftUp(HPDataType* array, int child) {
	int parent = (child - 1) / 2;
	//父节点等于子节点减一除2
	while (child > 0) {
		if (array[child] < array[parent]){
			//若子节点比父节点小，则交换两者的位置
			Swap(array,child,parent);
			child=parent;
			//之后将父节点赋给子节点
			parent=(child-1)/2;
			//重新寻找下一个父节点
			}
		else {
			break;
		}
	}
}


//创建堆函数
void heapCreat(Heap* hp, HPDataType* array, int size) {
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	//为堆申请数组空间
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	//将数组中的内容拷贝到堆的数组之中
	hp->_capacity = hp->_size = size;
	//给大小和容量赋值
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		//从最后一层非叶子节点开始进行向下调整
		shiftDown(hp->_array, size, parent);
	}
}

//堆打印函数
void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
		//逐个进行打印
	}
	printf("\n");
}


void test()
{
	//大堆数组
	int array[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;
	heapCreat(&hp, array, 11);
	heapPrint(&hp);

}

int main()
{
	test();
	return 0;
}