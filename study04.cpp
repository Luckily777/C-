//ջ


typedef struct Stack {
	int* array;
	size_t size;
	size_t capacity;
}Stack;

void stackinit(Stack* st, size_t n) {
	st->array = (int*)malloc(sizeof(int) * n);
	st->size = 0;
	st->capacity = n;
}


void stackpush(Stack* st, int data) {
	if (st->size == st->capacity) {
		st->capacity *= 2;
		st->array = (int*)realloc(st->array, st->capacity * sizeof(int));
	}
	st->array[st->size++] = data;
}

void stackpop(Stack* st) {
	if (st->size) {
		st->size--;
	}
}

int stacktop(Stack* st) {
	return st->array[st->size-1];
}

int stackSize(Stack* st) {
	return st->size;
}

int stackempty(Stack* st) {
	if (st->size == 0) {
		return 1;
	}
	return 0;
}

void Stackdestory(Stack* st) {
	free(st->array);
	st->array = NULL;
	st->capacity = 0;
	st->size = 0;
}

