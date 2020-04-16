#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	//��̬����
	int _size;
	//��С
	int _capacity;
	//����
}Heap;

//��������
void Swap(HPDataType* array, int left, int right) {
	int temp = array[left];
	//�����ֵ�����м����
	array[left] = array[right];
	//�ұ�ֵ�������
	array[right] = temp;
	//�м���������ұ�
}


//���µ�������
void shiftDown(HPDataType* array, int size, int parent) {
	int child = 2 * parent + 1;
	//�ӽڵ���ڶ����ĸ��ڵ�+1
	while (child < size) {
		if (child + 1 < size && array[child + 1] < array[child]) {
			//���ұߵ��ӽڵ�С����ߵ��ӽڵ㣬��child++
			child++;
		}
		if (array[child] < array[parent]) {
			//���ӽڵ�ȸ��ڵ�С
			Swap(array, child, parent);
			//�����ӽڵ�͸��ڵ�
			parent = child;
			//���ӽڵ㸳�����ڵ�
			child = 2 * parent + 1;
			//���¼����ӽڵ�
		}
		else {
			break;
		}
	}

}

//���ϵ�������
void shiftUp(HPDataType* array, int child) {
	int parent = (child - 1) / 2;
	//���ڵ�����ӽڵ��һ��2
	while (child > 0) {
		if (array[child] < array[parent]){
			//���ӽڵ�ȸ��ڵ�С���򽻻����ߵ�λ��
			Swap(array,child,parent);
			child=parent;
			//֮�󽫸��ڵ㸳���ӽڵ�
			parent=(child-1)/2;
			//����Ѱ����һ�����ڵ�
			}
		else {
			break;
		}
	}
}


//�����Ѻ���
void heapCreat(Heap* hp, HPDataType* array, int size) {
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	//Ϊ����������ռ�
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	//�������е����ݿ������ѵ�����֮��
	hp->_capacity = hp->_size = size;
	//����С��������ֵ
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		//�����һ���Ҷ�ӽڵ㿪ʼ�������µ���
		shiftDown(hp->_array, size, parent);
	}
}

//�Ѵ�ӡ����
void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
		//������д�ӡ
	}
	printf("\n");
}


void test()
{
	//�������
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