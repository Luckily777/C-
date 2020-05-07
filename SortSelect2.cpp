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


//第二种选择排序，从两边开始进行选择排序
void selectSort2(int* array, int n) {
	int begin = 0;
	//最左边的位置
	int end = n - 1;
	//最右边的位置
	while (begin < end) {
		//左边小于右边
		int min = begin, max = begin;
		//初始化min和max位置全部指向最开始
		for (int i = begin + 1; i < end; i++) {
			if (array[i] >= array[max]) {
				//找到最大的位置
				max = i;
			}
			if (array[i] <array[min]) {
				//找到最小的位置
				min = i;
			}
		}
		Swap(array, begin, min);
		//将最小的位置和最左边的数据交换
		if (max == begin) {
			//若最大的等于左边的数据时，则表示数据发生了变化
			max = min;
			//将min位置赋值给max
		}
		Swap(array, end, max);
		//进行最大值的交换
		begin++;
		end--;
	}
}
