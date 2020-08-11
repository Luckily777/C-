//¿ìËÙÅÅĞò·¨

int Getmid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if (array[mid] > array[begin]) {
		if (array[mid] < array[end]) {
			return mid;
		}
		else {
			if (array[begin] > array[end]) {
				return begin;
			}
			else {
				return end;
			}
		}
	}
	else {
		if (array[mid] > array[end]) {
			return mid;
		}
		else {
			if (array[begin] < array[end]) {
				return begin;
			}
			else {
				return end;
			}
		}
	}
}


//hora

void horaSort(int* array, int begin, int end) {
	int mid = Getmid(array, begin, end);
	Swap(array, begin, mid);
	int key = array[begin];
	int start = begin;
	while (begin < end) {
		while (begin < end && array[end] >= key) {
			end--;
		}
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		Swap(array, end, begin);
	}
	Swap(array, atart, begin);
	return begin;
}


//wakeng

void Partionsort(int* array, int begin, int end) {
	int mid = Getmid(array, begin, end);
	Swap(array, begin, mid);

	int key = array[begin];
	while (begin < end) {
		while (begin < end && array[end] >= key) {
			end--;
		}
		array[begin] = array[end];
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		array[end] = array[end];
	}
	array[begin] = key;
	return begin;
}

//zhizhen
void DoubleSort(int* array, int begin, int end) {
	int mid = Getmid(array, begin, end);
	Swap(array, begin, mid);

	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end) {
		if (array[cur] < key && ++prev != cur) {
			Swap(array, cur, prev);
		}
		cur++;
	}
	Swap(array, begin, prev);
	return prev;
}

void QucikSort(int* array, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int Keypos = fangfa(array, begin, end);
	QucikSort(array, begin, Keypos);
	QucikSort(array, Keypos+1,end);

}