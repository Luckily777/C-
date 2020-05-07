//交换函数
void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*
时间复杂度：最坏O(n^1.3) 平均O(n^1.3)  最好O(n)
空间复杂度：O(1)
稳定性：不稳定  ---> 分组时相同值的元素不一定可以分到同一组，预排序是可能导致相对位置发生变化
数据敏感：敏感
*/

void shellSort(int* array, int n) {
	int gap = n;
	//步长
	while (gap > 1) {
		gap = gap / 3 + 1;
		//步长缩减 通过不同的gap来进行逻辑分组
		//在组内进行插入排序 不同组的元素交替进行排序

		for (int i = 0; i < n - gap; i++) {
			//一轮插入排序
			int end = i;
			//排序的最后一个位置
			int key = array[end + gap];
			//同分组之中第一个要插入的数据
			while (end >= 0 && array[end] > key) {
				//找到第一个小于等于的数据
				array[end + gap] = array[end];
				//将数据向后瞬移
				end -= gap;
				//end重新赋值
			}
			array[end + gap] = key;
			//将所需要插入的数据插入到新的位置
		}
	}
}