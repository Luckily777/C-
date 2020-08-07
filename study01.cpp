#include <iostream>
using namespace std;


//¶þ·Ö²éÕÒ
//int OrderFind(int arr[], int left, int right, int key) {
//	int mid = 0;
//	while (left <= right) {
//		int mid = (left + right) >> 1;
//		if (arr[mid] > key) {
//			right = mid - 1;
//		}
//		else if (arr[mid] < key) {
//			left = mid + 1;
//		}
//		else {
//			return arr[mid];
//		}
//	}
//	return -1;
//}


typedef struct Seqlist {
	int* num;
	size_t size;
	size_t capacity;
}Seqlist;

void Seqlistinit(Seqlist* sl) {
	sl->num = (int*)malloc(sizeof(int) * 4);
	sl->size = 0;
	sl->capacity = 4;
}

void CheckCapacity(Seqlist* sl) {
	if (sl->size == sl->capacity) {
		sl->capacity *= 4;
		sl->num = (int*)realloc(sl->num, sizeof(int) * sl->capacity);
	}
}

void Pushback(Seqlist* sl, int value) {
	CheckCapacity(sl);
	sl->num[sl->size++] = value;
}


void Popback(Seqlist* sl) {
	if (sl->size) {
		sl->size -= 1;
	}
}

void Pushfront(Seqlist* sl, int value) {
	CheckCapacity(sl);
	size_t end = sl->size;
	while (end > 0) {
		sl->num[end] = sl->num[end - 1];
		end--;
	}
	sl->num[0] = value;
	sl->size++;
}

void Popfront(Seqlist* sl) {
	if (sl->size) {
		size_t start = 1;
		while (start < sl->size) {
			sl->num[start - 1] = sl->num[start];
			start++;
		}
	}
	sl->size--;
}

void Seqlistinsert(Seqlist* sl, size_t pos, int value) {
	if (pos < sl->size) {
		CheckCapacity(sl);
		size_t end = sl->size;
		while (end > pos) {
			sl->num[end] = sl->num[end - 1];
			end--;
		}
		sl->num[pos] = value;
		sl->size++;
	}
}

void Seqlistearse(Seqlist* sl, size_t pos) {
	if (pos < sl->size) {
		size_t start = pos + 1;
		while (start < sl->size) {
			sl->num[start - 1] = sl->num[start];
			start++;
		}
		sl->size--;
	}
}

int Seqlistfind(Seqlist* sl, int value) {
	for (int i = 0; i < sl->size; i++) {
		if (sl->num[i] == value) {
			return i;
		}
	}
	return -1;
}


void SeqlistPrintf(Seqlist* sl) {
	for (size_t i = 0; i < sl->size; i++) {
		cout << sl->num[i];
	}
	cout << endl;
}
void Test() {
	Seqlist sl;

}


int main() {
	/*int arr[7] = { 0,1,2,4,6,8,9 };
	OrderFind(arr, 0, 6, 2);*/
	return 0;

}