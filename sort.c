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

