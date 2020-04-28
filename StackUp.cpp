#include "StackUp.h"

//栈的初始化函数
void StackInit(Stack* st, size_t n) {
	st->array = (Type*)malloc(sizeof(Type) * n);
	st->capacity = n;
	st->size = 0;
}

//栈的入栈操作函数
void StackPush(Stack* st, Type data) {
	if (st->capacity == st->size) {
		st->capacity *= 2;
		st->array = (Type*)realloc(st->array, st->capacity * sizeof(Type));
	}
	st->array[st->size++] = data;
}

//栈的出栈操作函数
void StackPop(Stack* st) {
	if (st->size) {
		st->size--;
	}
}

//获取栈的栈顶元素函数
Type StackTop(Stack* st) {
	return st->array[st->size - 1];
}

//获取栈的大小函数
size_t StackSize(Stack* st) {
	return st->size;
}

//判断栈是否为空函数
int StackEmpty(Stack* st) {
	if (st->size == 0) {
		return 1;
	}
	return 0;
}

//栈的销毁函数
void StackDestory(Stack* st) {
	free(st->array);
	st->array == NULL;
	st->capacity = st->size = 0;
}
