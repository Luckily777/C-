#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "BinaryTreeUp.h"
//顺序表实现栈
typedef BTNode* Type;

// 栈

//栈结构
typedef struct Stack {
	Type* array;
	size_t size;
	size_t capacity;
}Stack;

//栈的初始化函数
void StackInit(Stack* st, size_t n);

//栈的入栈操作函数
void StackPush(Stack* st, Type data);

//栈的出栈操作函数
void StackPop(Stack* st);

//获取栈的栈顶元素函数
Type StackTop(Stack* st);

//获取栈的大小函数
size_t StackSize(Stack* st);

//判断栈是否为空函数
int StackEmpty(Stack* st);

//栈的销毁函数
void StackDestory(Stack* st);
