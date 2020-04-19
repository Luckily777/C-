#pragma once
#include <stdlib.h>
#include <memory.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* array, int left, int right);

void heapCreat(Heap* hp, HPDataType* array, int size);

void shiftDown(HPDataType* array, int size, int parent);

void shiftUp(HPDataType* array, int child);

void shiftDownL(HPDataType* array, int size, int parent);

void shiftUpL(HPDataType* array, int child);

void heapPop(Heap* hp);

void heapPush(Heap* hp, HPDataType data);

HPDataType heapTop(Heap* hp);

int heapEmpty(Heap* hp);

void heapPrint(Heap* hp);
