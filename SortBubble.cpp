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

void bubbleSort(int* array, int n) {
	while (n) {
		//循环n次 
		int flag = 1;
		//设置标识符，若标识符改变，则意味着此数组已经是有序序列
		int end = n;
		//最后的位置
		for (int i = 1; i < end; i++) {
			if (array[i - 1] > array[i]) {
				//若前一项大于后一项，则进行交换
				Swap(array, i, i - 1);
				//之后将标识符置零
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
		n--;
	}
}