#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "BinaryTreeUp.h"
//˳���ʵ��ջ
typedef BTNode* Type;

// ջ

//ջ�ṹ
typedef struct Stack {
	Type* array;
	size_t size;
	size_t capacity;
}Stack;

//ջ�ĳ�ʼ������
void StackInit(Stack* st, size_t n);

//ջ����ջ��������
void StackPush(Stack* st, Type data);

//ջ�ĳ�ջ��������
void StackPop(Stack* st);

//��ȡջ��ջ��Ԫ�غ���
Type StackTop(Stack* st);

//��ȡջ�Ĵ�С����
size_t StackSize(Stack* st);

//�ж�ջ�Ƿ�Ϊ�պ���
int StackEmpty(Stack* st);

//ջ�����ٺ���
void StackDestory(Stack* st);
