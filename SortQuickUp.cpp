//优化下得快速排序 ——三数取中

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


//三数取中法则
int GetMid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	//选择begin，和end的中间位置
	if (array[begin] < array[mid]) {
		//若起始位置的值小于中间位置
		if (array[mid] < array[end]) {
			//且中间位置的值小于尾部位置的值
			return mid;
			//则返回中间的值
		}
		else {
			if (array[begin] > array[end]) {
				//否则，若起始位置的值也大于尾部位置的值
				return begin;
				//则返回开始位置
			}
			else {
				return end;
				//否则返回尾部位置
			}
		}
	}
	else {
		//若中间位置的值不大于起始位置的值
		if (array[begin] < array[end]) {
			//开始位置小于尾部位置的值
			return mid;
			//则返回中间位置
		}
		else {
			if (array[begin] < array[end]) {
				//在中间位置不大于起始位置，且开始位置不小于尾部位置的值
				return begin;
				//则返回开始位置
			}
			else {
				return end;
				//否则返回尾部位置
			}
		}
	}
}


//hora法
int PartionOne(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	//三数取中 找到mid值
	Swap(array, begin, mid);
	//进行交换

	//确定基准值
	int key = array[begin];
	//开始位置
	int start = begin;


	while (begin < end) {
		//从后向前，找第一个小于基准值的位置
		while (begin < end && array[end] >= key) {
			end--;
		}
		//从前向后，找第一个大于基准值的位置
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//两者进行交换
		Swap(array, begin, end);
	}
	//最后将相遇的位置和初始位置进行交换
	Swap(array, start, begin);

	//返回基准值位置
	return begin;
}


//挖坑法
int PartionTwo(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	//三数取中 找到mid值
	Swap(array, begin, mid);
	//进行交换

	//确定基准值
	int key = array[begin];
	while (begin < end) {
		//从后向前找第一个小于基准值的位置
		while (begin < end && array[end] >= key) {
			end--;
		}
		//将此位置的值，填入一开始的基准值坑之中
		array[begin] = array[end];
		//从前向后找第一个大于基准值的位置
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//将此位置的值填入之前找到的小于基准值的位置
		array[end] = array[begin];
	}
	//最后将key的值填入相遇的位置
	array[begin] = key;
	//返回基准值位置
	return begin;
}


//前后指针法
int PartionThree(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	//三数取中 找到mid值
	Swap(array, begin, mid);
	//进行交换

	//最后一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = prev + 1;
	//基准值
	int key = array[begin];
	while (cur <= end) {
		//若下一个基准值位置和最后一个基准值位置之间不连续
		if (array[cur] < key && ++prev != cur) {
			//则进行交换
			Swap(array, prev, cur);
		}
		cur++;
	}
	//交换最后基准值和基准值的位置
	Swap(array, begin, prev);
	return prev;
}


/*
时间复杂度：最坏：O(n^2)-->不会出现   最好:O(nlogn)  平均：O(nlogn)
空间复杂度：O(logn)  函数调用栈，  极端情况: O(n)-->不会出现
稳定性：不稳定
数据敏感：敏感
*/

void SortQucik(int* array, int begin, int end) {
	if (begin >= end) {
		//下h只剩下最后一个元素时，则直接返回
		return;
	}
	int keyPos = PartionOne(array, begin, end);
	//寻找第一个基准值
	SortQucik(array, begin, keyPos);
	//左边分
	SortQucik(array, keyPos+1,end);
	//右边分
}