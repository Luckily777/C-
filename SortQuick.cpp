void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}



//Hore分割法
int PartionHora(int* array, int begin, int end) {
	//选择基准值
	int key = array[begin];
	int start = begin;
	//开始划分
	while (begin < end) {
		//从后向前，找第一个小于key的值
		while (begin < end && array[end] >= key) {
			end--;
		}
		//从前向后，找第一个大于key的值
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		//交换找到的两者值得位置
		Swap(array, begin, end);
	}
	//最后将基准值和相遇位置得值进行交换
	Swap(array, start, begin);
	//返回基准值交换后的位置
	return begin;
}

//挖坑分割法
int PartionHole(int* array, int begin, int end) {
	//基准值取出来，空出这个坑
	int key = array[begin];
	//开始划分
	while (begin < end) {
		//从后找第一个小于key的位置
		while (begin < end && array[end] >= key) {
			end--;
		}
		//将找到的此位置值填到基准值的坑里，空出一个新的坑
		array[begin] = array[end];
		//从前向后找到第一个大于key的位置
		while (begin < end && array[begin] >= key) {
			begin++;
		}
		//将找到的位置的值取出，填到之前的坑之中，又空出另一个新坑
		array[end] = array[begin];
	}
	//直到相遇之后，将最早的基准值放在最后空出来的坑之中
	array[begin] = key;
	//返回基准值此时的位置
	return begin;
}

//前后指针分割法
int PartionHand(int* array, int begin, int end) {
	//最后一个小于基准值的位置
	int last = begin;
	//新发现的下一个小于基准值的位置
	int next = last + 1;
	//基准值
	int key = array[begin];
	//开始划分
	while (next <= end) {
		//若next所指的数据小于基准值，但last和next之间还存在其他数据
		//则代表两者之间还包含着大于基准值的数据存在，进行交换
		//大的数据向后移动，小的数据向前移动
		if (array[next] < key && ++last != next) {
			Swap(array, last, next);
			next++;
		}
	}
	//最后当next走完之后，将last的位置和最开始的基准值位置进行交换
	Swap(array, begin, last);
	return last;
	//返回基准值的位置
}


void QuichSort(int* array, int begin, int end) {
	if (begin >= end) {
		//若begin和end之间没有其他元素，则表示两者是有序的
		return;
	}
	int keyPos = PartionHora(array, begin, end);
	//以此基准值，来划分当前区域

	QuichSort(array, begin, keyPos - 1);
	//递归法划分左边子区域
	QuichSort(array, keyPos + 1, end);
	//递归法划分右边子区域

}