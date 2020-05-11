#include <stdlib.h>
#include <memory.h>

#include "sort.h"
#include "Stack.h"
#include "queue.h"

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


/*
	ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
	�������У�����
*/

void insertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//�����ݲ���
		//end: �������е����һ��λ��
		int end = i;
		//key: �����������
		int key = array[end + 1];
		//�ҵ���һ��С�ڵ���key��λ��
		while (end >= 0 && array[end] > key)
		{
			//��ǰ��������ƶ�
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

/*
ʱ�临�Ӷȣ��O(n^1.3) ƽ��O(n^1.3)  ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�  ---> ����ʱ��ֵͬ��Ԫ�ز�һ�����Էֵ�ͬһ�飬Ԥ�����ǿ��ܵ������λ�÷����仯
�������У�����
*/
void shellSort(int* array, int n)
{
	//gap: ����
	int gap = n;
	//���ֲ�������
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// gap = gap / 2;
		//һ�ֲ�������
		for (int i = 0; i < n - gap; ++i)
		{
			//ͨ������gap�����߼�����
			//���ڽ��в�������
			//��ͬ���Ԫ�ؽ����������
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}	
}

/*
ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
�������У�������
*/
void selectSort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		//start:δ�������ݵ������
		int start = i;
		//min: ��Сֵ��λ��
		int min = start;
		//��δ���������������Сֵ
		for (int j = start + 1; j < n; ++j)
		{
			if (array[j] < array[min])    //12   19   5  100  20  30     5
				min = j;
		}
		Swap(array, start, min);
	}
}

void selectSort2(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//ÿһ��ѡ�����ֵ����Сֵ
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (array[i] >= array[max])   //  100  3   5  100  10
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		//��Сֵ����begin
		Swap(array, begin, min);
		//������ֵλ�÷����˱仯����Ҫ����
		if (max == begin)
			max = min;
		//���ֵ����end
		Swap(array, end, max);

		/*
		Swap(array, max, end);
		if (min == end)
			min = max;
		Swap(array, min, begin);
		*/
		++begin;
		--end;
	}
}

/*
ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
�������У�����
*/
void bubbleSort(int* array, int n)
{
	while (n)
	{
		//�����Ѿ���������У�ͨ����ǩ��ǰ�����������
		// flag: 1 ---> һ��ð�����������û�з���Ԫ�ؽ���
		int flag = 1;
		int end = n;
		//һ��ð������
		//for (int i = 0; i < end - 1; ++i)
		for (int i = 1; i < end; ++i)
		{
			//����Ԫ�ؽ��бȽ�, �������ƶ�
			//if (array[i] > array[i + 1])
			if (array[i - 1] > array[i])
			{
				Swap(array, i, i - 1);
				flag = 0;
			}
		}
		//û�з���Ԫ�ؽ����������Ѿ�����
		if (flag)
			break;
		--n;
	}
}

/*
ʱ�临�Ӷȣ�O(nlogn)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�  --> �����Ĺ��������λ�ÿ��ܻᷢ���仯
�������У�������
*/
//��ѵĵ���
void shiftDown(int* array, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void heapSort(int* array, int n)
{
	//����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(array, n, i);
	}
	//ѭ��ɾ��
	while (n)
	{
		Swap(array, 0, n - 1);
		--n;
		shiftDown(array, n, 0);
	}
}

//����ȡ��
int getMid(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	// begin, mid, endѡ���м�ֵ��λ��
	if (array[begin] < array[mid])
	{
		// begin <  mid;
		if (array[mid] < array[end])
			return mid;
		else{
			// begin < mid,  end <= mid
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
	else
	{
		// begin >= mid;
		if (array[mid] > array[end])
			return mid;
		else
		{
			//begin >= mid, end >= mid
			if (array[begin] < array[end])
				return begin;
			else
				return end;
		}
	}
}


//hora����
int partion(int* array, int begin, int end)
{
	//����ȡ��
	int mid = getMid(array, begin, end);
	//���� mid -- begin
	Swap(array, begin, mid);

	//ѡ���׼ֵ
	int key = array[begin];
	int start = begin;
	//����
	while (begin < end)
	{
		
		//�Ӻ���ǰ�ҵ�һ��С��key��λ��
		while (begin < end && array[end] >= key)
			--end;

		//��ǰ����ҵ�һ������key��λ��
		while (begin < end && array[begin] <= key)
			++begin;
		
		//���� end, begin
		Swap(array, begin, end);
	}

	//key������λ�õ����ݽ���
	Swap(array, start, begin);
	//���ػ�׼ֵ��λ��
	return begin;
}

//�ڶ��ֻ��ַ����� �ڿӷ�
int partion2(int* array, int begin, int end)
{
	//����ȡ��
	int mid = getMid(array, begin, end);
	//���� mid -- begin
	Swap(array, begin, mid);

	int key = array[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ��
		while (begin < end && array[end] >= key)
			--end;
		//���: begin
		array[begin] = array[end];
		//��ǰ�����
		while (begin < end && array[begin] <= key)
			++begin;
		//��ӣ�end
		array[end] = array[begin];
	}
	//���һ���ӣ� ������λ��  --> ����׼ֵ
	array[begin] = key;
	//���ػ�׼ֵ��λ��
	return begin;
}

//ǰ��ָ�뷨
int partion3(int* array, int begin, int end)
{
	//����ȡ��
	int mid = getMid(array, begin, end);
	//���� mid -- begin
	Swap(array, begin, mid);

	//prev: ���һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//cur���·��ֵ���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end)
	{
		//�·��ֵ�С���ݺ�βָ��ָ���λ�ò����������м京�д��ڻ�׼ֵ�����ݣ��ʽ��н���
		//����������ƶ���С������ǰ�ƶ�
		if (array[cur] < key && ++prev != cur)
			Swap(array, prev, cur);
		++cur;
	}
	Swap(array, begin, prev);
	return prev;
}

/*
ʱ�临�Ӷȣ����O(n^2)-->�������   ���:O(nlogn)  ƽ����O(nlogn)
�ռ临�Ӷȣ�O(logn)  ��������ջ��  �������: O(n)-->�������
�ȶ��ԣ����ȶ�
�������У�����
*/
void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//���ֵ�ǰ����
	//int keyPos = partion(array, begin, end);
	//int keyPos = partion2(array, begin, end);
	int keyPos = partion3(array, begin, end);
	//����������
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}

//ջʵ�ַǵݹ�: ��������ֵ�����
void quickSortNoR(int* array, int n)
{
	Stack st;
	stackInit(&st, 10);
	//��ʼ������ջ: ���Һ���
	if (n > 1)
	{
		stackPush(&st, n - 1);
		stackPush(&st, 0);
	}
	//����ջ������ջ�е�ÿһ������
	while (stackEmpty(&st) != 1)
	{
		//��ȡջ������
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//����
		int keyPos = partion3(array, begin, end);
		//��������ջ�� ����������
		// �ң� keyPos + 1, end
		if (keyPos + 1 < end)
		{
			stackPush(&st, end);
			stackPush(&st, keyPos + 1);
		}
		//�� begin ,  keyPos - 1
		if (begin < keyPos - 1)
		{
			stackPush(&st, keyPos - 1);
			stackPush(&st, begin);
		}
	}
}

//���зǵݹ�: ��������ֵ�����
void quickSortNoR2(int* array, int n)
{
	Queue q;
	queueInit(&q);

	if (n > 1)
	{
		//�������
		queuePush(&q, 0);
		queuePush(&q, n - 1);
	}
	while (queueEmpty(&q) != 1)
	{
		//��ȡ��ͷ����
		int begin = queueFront(&q);
		queuePop(&q);
		int end = queueFront(&q);
		queuePop(&q);
		//����
		int keyPos = partion3(array, begin, end);
		//���������
		if (begin < keyPos - 1)
		{
			queuePush(&q, begin);
			queuePush(&q, keyPos - 1);
		}
		if (keyPos + 1 < end)
		{
			queuePush(&q, keyPos + 1);
			queuePush(&q, end);
		}
	}
}


//�ϲ��� ��Ҫ֪���������������е�����: [begin, mid]  [mid + 1, end]
void merge(int* array, int begin, int mid, int end, int* tmp)
{
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	//�ϲ�
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	//�鿴�Ƿ���ʣ��Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int)* (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int)* (end2 - begin2 + 1));
	//������ԭʼ�ռ�
	memcpy(array + begin, tmp + begin, sizeof(int)* (end - begin + 1));
}

void mergeSortR(int* array, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	//���ȱ�֤�������������������������
	mergeSortR(array, begin, mid, tmp);
	mergeSortR(array, mid + 1, end, tmp);

	//�ϲ�����������
	merge(array, begin, mid, end, tmp);
}

/*
ʱ�临�Ӷȣ�O(nlogn)
�ռ临�Ӷȣ�O(n)
�ȶ����ȶ�
�������У�������
*/
void mergeSort(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	mergeSortR(array, 0, n - 1, tmp);
	free(tmp);
}

void mergeSortNoR(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	//���ϲ������Ԫ�ظ���
	int k = 1;
	//���ֵĹ鲢
	while (k < n)
	{
		//һ�ֹ鲢
		for (int i = 0; i < n; i += 2 * k)
		{
			//[begin, mid]  [mid + 1, end]
			int begin = i;

			int mid = i + k - 1;
			//�ж�mid�Ƿ�Խ��
			if (mid >= n - 1)
				continue;

			int end = i + 2 * k - 1;
			//�ж�end�Ƿ�Խ��
			if (end >= n)
				end = n - 1;
			merge(array, begin, mid, end, tmp);
		}
		k *= 2;
	}
	
	
}
/*
ʱ�临�Ӷȣ�O(max(n,��Χ))
�ռ临�Ӷȣ�O(��Χ)
�ȶ���һ��̲���Ϊ���ȶ���(Ƿ��)
�������У�������
�������� ֻ�ʺ�С��Χ���ݣ� �����Χ�󣬿ռ临�ӶȽϸ�
*/
void countSort(int* array, int n)
{
	// 1, 2, 3,   1000000
	//ͳ�Ʒ�Χ
	int min = array[0], max = array[0];
	for (int i = 1; i < n; ++i)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	int range = max - min + 1;
	//�������ռ䣬���м���
	int* countArr = (int*)malloc(sizeof(int)* range);
	//��ʼ��Ϊ0
	memset(countArr, 0, sizeof(int)* range);
	//ͳ�ƴ���
	for (int i = 0; i < n; ++i)
	{
		countArr[array[i] - min]++;
	}
	//�ָ����ݣ� ������������
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			array[idx++] = i + min;
		}
	}

	free(countArr);
}