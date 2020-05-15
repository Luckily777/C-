//静态数组
#define N 100
typedef int SLDataType
typedef struct SeqList {
	SLDataType array[N];
	size_t size;
}SeqListJ;


//动态数组
typedef struct SeqList {
	SLDataType* array;
	size_t size;
	size_t capacity;
}SeqListD;


void Init(SeqListD* SL) {
	SL->array = (int*)malloc(sizeof(int) * 4);
	SL->capacity = 4;
	SL->size = 0;
}

void CheckCapacity(SeqListD* SL) {
	if (SL->capacity == SL->size) {
		SL->capacity *= 4;
		SL->array = (int*)realloc(SL->array, sizeof(int) * SL->capacity);
	}

}

void PushBack(SeqListD* SL, int vaule) {
	CheckCapacity(SL);
	SL->array[SL->size++] = vaule;
}

void SeqListInsert(SeqListD* SL, size_t pos, int vaule) {
	if (pos < SL->size) {
		CheckCapacity(SeqListD * SL);
		size_t end = SL->size;
		while (end > pos) {
			SL->array[end] = SL->array[end - 1];
			end--;
		}
		SL->array[pos] = vaule;
	}
	SL->size++;
}


void SeqListErase(SeqListD* sl, size_t pos) {
	if (pos < sl->size) {
		size_t start = pos + 1;
		while (start < sl->size) {
			sl->array[start - 1] = sl->array[start];
			start++;
		}
		sl->size--;
	}
}

void SeqListfind(SeqListD* sl, int value) {
	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] == value) {
			return i;
		}
	}
	return -1;
}