#include "sort.h"

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


/*
	时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n)
	空间复杂度：O(1)
	稳定性：稳定
	数据敏感：敏感
*/

void insertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//新数据插入
		//end: 有序序列的最后一个位置
		int end = i;
		//key: 待插入的数据
		int key = array[end + 1];
		//找到第一个小于等于key的位置
		while (end >= 0 && array[end] > key)
		{
			//当前数据向后移动
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

/*
时间复杂度：最坏O(n^1.3) 平均O(n^1.3)  最好O(n)
空间复杂度：O(1)
稳定性：不稳定  ---> 分组时相同值的元素不一定可以分到同一组，预排序是可能导致相对位置发生变化
数据敏感：敏感
*/
void shellSort(int* array, int n)
{
	//gap: 步长
	int gap = n;
	//多轮插入排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// gap = gap / 2;
		//一轮插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			//通过步长gap进行逻辑分组
			//组内进行插入排序
			//不同组的元素交替进行排序
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
时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n^2)
空间复杂度：O(1)
稳定性：稳定
数据敏感：不敏感
*/
void selectSort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		//start:未排序数据的最左边
		int start = i;
		//min: 最小值的位置
		int min = start;
		//从未排序的数据中找最小值
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
		//每一次选择最大值和最小值
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (array[i] >= array[max])   //  100  3   5  100  10
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		//最小值放在begin
		Swap(array, begin, min);
		//如果最大值位置发生了变化，需要更新
		if (max == begin)
			max = min;
		//最大值放在end
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

