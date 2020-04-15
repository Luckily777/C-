typedef int Type;

typedef struct Stack
{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Type data);
void stackPop(Stack* st);
Type stackTop(Stack* st);

size_t stackSize(Stack* st);
int stackEmpty(Stack* st);

void stackDestory(Stack* st);

void stackInit(Stack* st, size_t n)
{
	st->_array = (Type*)malloc(sizeof(Type) * n);
	st->_capacity = n;
	st->_size = 0;
}

void stackPush(Stack* st, Type data)
{
	//¼ì²éÈÝÁ¿
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
	//Î²²å
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
	//Î²É¾
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)
{
	return st->_array[st->_size - 1];
}

size_t stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)
{
	if (st->_size == 0)
		return 1;
	return 0;
}

void stackDestory(Stack* st)
{
	free(st->_array);
	st->_array = NULL;
	st->_size = st->_capacity = 0;
}



typedef struct {
    Stack pushST;
    Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&mq->pushST, 10);
    stackInit(&mq->popST, 10);
    return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ret;
    if (stackEmpty(&obj->popST))
    {
        while (stackEmpty(&obj->pushST) != 1)
        {
            int top = stackTop(&obj->pushST);
            stackPop(&obj->pushST);
            stackPush(&obj->popST, top);
        }
    }
    ret = stackTop(&obj->popST);
    stackPop(&obj->popST);
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(&obj->popST))
    {
        while (stackEmpty(&obj->pushST) != 1)
        {
            int top = stackTop(&obj->pushST);
            stackPop(&obj->pushST);
            stackPush(&obj->popST, top);
        }
    }
    return stackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
    stackDestory(&obj->pushST);
    stackDestory(&obj->popST);
    free(obj);
}