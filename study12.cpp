//√∞≈›≈≈–Ú

void BubbleSort(int* array, int n) {
	while (n) {
		int flag = 1;
		int end = n;
		for (int i = 1; i < end; i++) {
			if (array[i - 1] > array[i]) {
				Swap(array, i - 1, i);
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
		n--;
	}
}


//πÈ≤¢≈≈–Ú
void Merge(int* array, int begin, int mid, int end, int* tmp) {
	int begin1 = begin, end1 = mid, begin2 = mid + 1, int end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		if (array[begin1] <= array[begin2]) {
			tmp[idx++] = array[begin1++];
		}
		else {
			tmp[idx++] = array[begin2++];
		}
	}

	if (begin1 <= end1) {
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	}
	if (begin2 <= end2) {
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));
	}
	memcpy(,array+begin,tmp + begin, sizeof(int) * (end - begin + 1));

}


void MergeSrotR(int* array, int begin, int end, int* tmp) {
	if (begin >= end) {
		return;
	}
	int mid = begin + (end - begin) / 2;
	MergeSrotR(array, begin, mid, tmp);
	MergeSrotR(array, mid + 1, end, tmp);
	Merge(array, begin, mid, end, tmp);

}


void MergeSrot(int* array, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	MergeSrotR(array, 0, n - 1, temp);
	free(tmp);
}