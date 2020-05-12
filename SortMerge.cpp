//归并排序


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


void SortMergeR(int* array, int begin, int end, int* tmp) {
	if (begin >= end) {
		//若Begin和end之间没有任何数据，则直接返回
		return;
	}
	//查找中间位置
	int mid = begin + (end - begin) / 2;

	//先进行子区间的排序
	SortMergeR(array, begin, mid, tmp);
	SortMergeR(array, mid + 1, end, tmp);

	//最后合并有序的子区间
	Merge(array, begin, mid, end, tmp);
}

/*
时间复杂度：O(nlogn)
空间复杂度：O(n)
稳定：稳定
数据敏感：不敏感
*/
void SortMerge(int* array, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	SortMergeR(array, 0, n - 1, tmp);
	free(tmp);
}