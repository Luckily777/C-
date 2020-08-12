//¼ÆÊıÅÅĞò
#include <stdio.h>
#include <stdlib.h>

void countsort(int* array, int n) {
	int min = array[0], max = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] < min) {
			min = array[i];
		}
		if (array[i] > max) {
			max = array[i];
		}
	}

	int range = max - min + 1;
	int* countarray = (int*)calloc(sizeof(int) * range,0);
	for (int i = 0; i < n; i++) {
		countarray[array[i] - min]++;
	}
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (countarray[i]--) {
			array[idx++] = i + min;
		}
	}
	free(countarray);
}