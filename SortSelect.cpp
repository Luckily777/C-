//交换函数
void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
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
			if (array[j] < array[min]) {
				min = j;
				//将j赋值给min位置
			}

		}
		Swap(array, start, min);
	}
}

