//Ö±½Ó²åÈëÅÅĞò

void insertsort(int* array, int n) {
	for (int i = 0; i < n; i++) {
		int end = i;
		int key = array[end + 1];
		while (end >= 0 && array[end] > key) {
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}


//Ï£¶ûÅÅĞò
void shellsort(int* array, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key) {
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}