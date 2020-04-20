#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	//���嶯̬����
	int _size;
	//����
	int _capacity;
	//����
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

	//����, �����һ����Ҷ�ӽڵ㿪ʼ����  (size - 2) / 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, size, parent);
	}
}


//��ѵ����µ���
// parent: ��ʼ������λ��
void shiftDown(HPDataType* array, int size, int parent)
{
	//����λ��
	int child = 2 * parent + 1;
	while (child < size)
	{
		//�����Һ��Ӻ�����ѡһ�����
		if (child + 1 < size && array[child + 1] > array[child])
			++child;
		//�͸��ڵ�Ƚ�
		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			//����
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//������ϵ���
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
			//��������
			break;
	}

}

void shiftDownL(HPDataType* array, int size, int parent)
{
	//����λ��
	int child = 2 * parent + 1;
	while (child < size)
	{
		//�����Һ��Ӻ�����ѡһ����С
		if (child + 1 < size && array[child + 1] < array[child])
			++child;
		//�͸��ڵ�Ƚ�
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			//����
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//С�����ϵ���
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
			//��������
			break;
	}

}

void heapPush(Heap* hp, HPDataType data)
{
	//�������
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		//��������
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		//��������
	}
	//β��
	hp->_array[hp->_size++] = data;
	//��Ԫ�ز��뵽�������һ��Ԫ��֮��
	shiftUp(hp->_array, hp->_size - 1);
	//�����ϵ���
}
//ɾ���Ѷ�Ԫ�أ�ɾ����ֵ
void heapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		// ����: �Ѷ������һ��Ҷ��
		Swap(hp->_array, 0, hp->_size - 1);
		// βɾ�� ʵ����ɾ���ļ�Ϊ�Ѷ�Ԫ��
		hp->_size--;
		//���µ���
		shiftDown(hp->_array, hp->_size, 0);
	}
}

HPDataType heapTop(Heap* hp)
{
	return hp->_array[0];
}

int heapEmpty(Heap* hp)
//�пպ���
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