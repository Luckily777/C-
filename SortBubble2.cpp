#include <stdio.h>
#include <stdlib.h>

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/*
时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n^2)
空间复杂度：O(1)
稳定性：稳定
数据敏感：敏感
*/

void BubbleSort(int* array,int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i] > array[j]) {
				Swap(array, i, j);
			}
		}
		printf("%d ", array[i]);
	}
	system("pause");
}

int main() {
	int array[] = { 1,3,4,5,8,9,6,7,2,0 };
	int n = 10;
	BubbleSort(array,n);
	system("pause");
	return 0;
}