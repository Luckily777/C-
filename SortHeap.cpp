void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/*
时间复杂度：O(nlogn)
空间复杂度：O(1)
稳定性：不稳定  --> 调整的过程中相对位置可能会发生变化
数据敏感：不敏感
*/

void ShiftDown(int* array, int n, int parent) {
	int child = 2 * parent + 1;
	//寻找孩子位置
	while (child < n) {
		if (child + 1 < n && array[child + 1] > array[child]) {
			//判断在满足条件的情况下，左右孩子两者的较大值
			child++;
			//若右边孩子比左边孩子大，则将child位置加1
		}
		if (array[child] > array[parent]) {
			//若孩子比父亲的值大，则交换父亲和孩子的位置
			Swap(array, child, parent);
			parent = child;
			//交换后重新将孩子位置赋予给父亲
			child = 2 * parent + 1;
			//重新计算新的孩子位置
		}
		else {
			break;
			//如果孩子值小于父亲，则跳出
		}
	}
}

void SortHeap(int* array, int n) {
	//建堆的过程
	for (int i = (n - 2) / 2; i >= 0; i--) {
		ShiftDown(array, n, i);
		//从下最后一个父节点开始进行建堆
	}
	//循环删除
	while (n) {
		Swap(array, 0, n - 1);
		n--;
		ShiftDown(array, n, 0);
	}
}