//非递归的归并排序

//合并函数 前提是需要知道两个有序子序列的区间 [begin ,mid ][mid+1 end]
void Merge(int* array, int begin, int mid, int end, int* tmp) {
	int begin1 = begin, end1 = end, begin2 = mid + 1, end2 = end;
	int idx = begin;

	//两个有序序列进行排序
	while (begin1 <= end1 && begin2 <= end2) {
		if (array[begin1] <= array[begin2]) {
			//将两个序列之中较小的值放入到tmp之中
			tmp[idx++] = array[begin1++];
		}
		else {
			tmp[idx++] = array[begin2++];
		}
	}
	//将剩余的数据直接拷贝到当前的空间之中
	if (begin1 < end1) {
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	}
	if (begin2 < end2) {
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));
	}
	//之后将tem之中的数据拷贝到原始空间之中
	memcpy(array + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void SortMergeNoR(int* array, int n) {
	//申请新的空间
	int* tmp = (int*)malloc(sizeof(int) * n);
	//设置跨度
	int k = 1;

	//开始多轮的合并
	while (k < n) {
		//一轮合并
		for (int i = 0; i < n; i += 2 * k) {
			int begin = i;
			int mid = i + k - 1;

			//若中间值大于最大位置则继续进行
			if (mid >= n - 1) {
				continue;
			}
			int end = i + 2 * k - 1;
			
			//若末尾值大于最大位置时，则将末尾值置到最后一个位置
			if (end >= n) {
				end = n - 1;
			}
			//合并
			Merge(array, begin, mid, end, tmp);
		}
		//跨度扩大2倍
		k *= 2;
	}
}