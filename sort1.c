#include "sort.h"

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

//hora����
int partion(int* array, int begin, int end)
{
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