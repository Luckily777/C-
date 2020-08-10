//堆


//向下调整
void Shiftdown(head* array, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && array[child + 1] < array[child]) {
			child++;
		}
		if (array[child] < array[parent]) {
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}


//向上调整

void headbackpush(head* array, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] < array[parent]) {
			Swap(array, child, parent);
			child = parent;
			parent = child - 1 / 2;
		}
		else {
			break;
		}
	}
}