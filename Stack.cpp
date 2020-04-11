#include <stdlib.h>
#include <stdio.h>


//˳���ʵ��ջ


typedef struct Stack
{
	int* array;
	size_t size;
	size_t capacity;
}Stack;

//ջ�ĳ�ʼ��
void stackInit(Stack* st, size_t n) {
	st->array = (int*)malloc(sizeof(int) * n);
	//Ϊ��̬��������ռ�
	st->capacity = n;
	//����������Ϊn
	st->size = 0;
	//size����Ϊ0
}

//��ջ����
void stackPush(Stack* st, int data) {
	if (st->size == st->capacity) {
		st->capacity *= 2;
		st->array = (int*)realloc(st->array, st->capacity * sizeof(int));
	}

	st->array[st->size++] = data;
}

//��ջ����
void stackPop(Stack* st) {
	if (st->size) {
		//��size������0
		st->size--;
		//���м�����������
	}
}

//��ѯ���ϲ�����
int stackTop(Stack* st) {
	return st->array[st->size - 1];
	//ֱ�ӷ���size-1������
}

//��ѯ��������
size_t stackSize(Stack* st) {
	return st->size;
	//ֱ�ӷ���size��ֵ

}

//�пղ�������
int stackEmpty(Stack* st) {
	if (st->size == 0) {
		//�����ڿգ��򷵻�1
		return 1;
	}
	return 0;
	//���򷵻�0
}

//�ͷź���
void stackDestory(Stack* st) {
	//�ͷ�
	free(st->array);
	//������array�ͷ�
	st->array = NULL;
	//����ָ��kong
	st->size = 0;
	//size��capacityȫ������
	st->capacity = 0;
}