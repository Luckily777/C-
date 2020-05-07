//交换函数
void Swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*
	时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n)
	空间复杂度：O(1)
	稳定性：稳定
	数据敏感：敏感
*/

void insertSort(int* array, int n) {
	//进行遍历
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		//有序序列得最后一个位置
		int key = array[end + 1];
		//待插入得一个数据
		while (end >= 0 && array[end] > key) {
			//找到第一个小于等于key的位置
			array[end + 1] = array[end];
			//将当前数据向后移动
			--end;
		}
		array[end + 1] = key;
		//将key数据存放在当前位置
	}
}