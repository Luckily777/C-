#include <stdlib.h>
#include <stdio.h>


//顺序表实现栈


typedef struct Stack
{
	int* array;
	size_t size;
	size_t capacity;
}Stack;

//栈的初始化
void stackInit(Stack* st, size_t n) {
	st->array = (int*)malloc(sizeof(int) * n);
	//为动态数组申请空间
	st->capacity = n;
	//将容量设置为n
	st->size = 0;
	//size设置为0
}

//进栈函数
void stackPush(Stack* st, int data) {
	if (st->size == st->capacity) {
		st->capacity *= 2;
		st->array = (int*)realloc(st->array, st->capacity * sizeof(int));
	}

	st->array[st->size++] = data;
}

//出栈函数
void stackPop(Stack* st) {
	if (st->size) {
		//若size不等于0
		st->size--;
		//进行减减操作即可
	}
}

//查询最上层数据
int stackTop(Stack* st) {
	return st->array[st->size - 1];
	//直接返回size-1的数据
}

//查询总数据量
size_t stackSize(Stack* st) {
	return st->size;
	//直接返回size的值

}

//判空操作函数
int stackEmpty(Stack* st) {
	if (st->size == 0) {
		//若等于空，则返回1
		return 1;
	}
	return 0;
	//否则返回0
}

//释放函数
void stackDestory(Stack* st) {
	//释放
	free(st->array);
	//将数组array释放
	st->array = NULL;
	//让其指向kong
	st->size = 0;
	//size和capacity全部置零
	st->capacity = 0;
}