#include "StackUp.h"

//ջ�ĳ�ʼ������
void StackInit(Stack* st, size_t n) {
	st->array = (Type*)malloc(sizeof(Type) * n);
	st->capacity = n;
	st->size = 0;
}

//ջ����ջ��������
void StackPush(Stack* st, Type data) {
	if (st->capacity == st->size) {
		st->capacity *= 2;
		st->array = (Type*)realloc(st->array, st->capacity * sizeof(Type));
	}
	st->array[st->size++] = data;
}

//ջ�ĳ�ջ��������
void StackPop(Stack* st) {
	if (st->size) {
		st->size--;
	}
}

//��ȡջ��ջ��Ԫ�غ���
Type StackTop(Stack* st) {
	return st->array[st->size - 1];
}

//��ȡջ�Ĵ�С����
size_t StackSize(Stack* st) {
	return st->size;
}

//�ж�ջ�Ƿ�Ϊ�պ���
int StackEmpty(Stack* st) {
	if (st->size == 0) {
		return 1;
	}
	return 0;
}

//ջ�����ٺ���
void StackDestory(Stack* st) {
	free(st->array);
	st->array == NULL;
	st->capacity = st->size = 0;
}
