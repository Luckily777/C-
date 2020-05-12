//计数排序


/*
时间复杂度：O(max(n,范围))
空间复杂度：O(范围)
稳定：一般教材认为是稳定的(欠妥)
数据敏感：不敏感
计数排序： 只适合小范围数据， 如果范围大，空间复杂度较高
*/

void SortCount(int* array, int n) {
	//统计范围
	int min = array[0], max = array[0];
	//找到最大值和最小值
	for (int i = 1; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	//确定准确的范围
	int range = max - min + 1;
	//开放辅助空间，进行计数
	int* countArr = (int*)malloc(sizeof(int*)range);
	//将申请的辅助空间全部初始化为零
	memset(countArr, 0, sizeof(int) * range);
	//开始统计数据出现的个数
	for (int i = 0; i < n; i++) {
		//出现一次则加一次
		countArr[array[i] - min]++;
	}
	//设置中间量
	int idx = 0;
	//恢复数据，遍历计数数组
	for (int i = 0; i < range; i++) {
		while (countArr[i]--) {
			array[idx++] = i + min;
		}
	}
	//释放辅助空间
	free(countArr);
}