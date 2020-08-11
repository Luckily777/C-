//—°‘Ò≈≈–Ú

void Selectsort(int* array, int n) {
	for (int i = 0; i < n; i++) {
		int start = i;
		int min = start;
		for (int j = start + 1; j < n; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		Swap(array, start, min);
	}
}

//∂—≈≈–Ú

void ShiftDown(int* array, int n, int parent) {
	int child = (parent * 2) + 1;
	while (child < n) {
		if (child + 1 < n && array[child + 1] > array[child]) {
			child++;
		}

		if (array[child] > array[parent]) {
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}


void Heapsort(int* array, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--) {
		ShiftDown(array, n, i);
	}

	while (n) {
		Swap(array, 0, n - 1);
		n--;
		ShiftDown(array, n, 0);
	}
}