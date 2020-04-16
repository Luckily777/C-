��ջ��ʵ�ֶ���

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
    //�������
    if (st->_size == st->_capacity)
    {
        st->_capacity *= 2;
        st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
    }
    //β��
    st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
    //βɾ
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
    Stack Push;
    //һ��pushջ
    Stack Pop;
    //һ��popջ
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* ms = (MyQueue*)malloc(sizeof(MyQueue));
    //����ռ�
    stackInit(&ms->Push, 10);
    //������ջȫ�����г�ʼ��
    stackInit(&ms->Pop, 10);
    return ms;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(&obj->Push, x);
    //������ջ����
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ret;
    if (stackEmpty(&obj->Pop)) {
        //�ж�popջ�Ƿ�Ϊ�գ���Ϊ�շ���1
        while (stackEmpty(&obj->Push) != 1) {
            //pushջ����Ϊ��
            ret = stackTop(&obj->Push);
            //��pushջ����Ԫ�ط�����ret��
            stackPop(&obj->Push);
            //��push���г�ջ����
            stackPush(&obj->Pop, ret);
            //��ret��ջ��pop
        }
    }
    ret = stackTop(&obj->Pop);
    //��popջ���˵�Ԫ�ظ�ֵ��ret
    stackPop(&obj->Pop);
    //�����г�ջ����
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(&obj->Pop)) {
        while (stackEmpty(&obj->Push) != 1) {
            int ret = stackTop(&obj->Push);
            stackPop(&obj->Push);
            stackPush(&obj->Pop, ret);
        }
        //ͬ�� 
    }
    return stackTop(&obj->Pop);
    //����pop������
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->Push) && stackEmpty(&obj->Pop);
    //�пղ������ж�����ջ��Ϊ�գ����ܵ�Ϊ��

}

void myQueueFree(MyQueue* obj) {
    stackDestory(&obj->Pop);
    //��������ջ
    stackDestory(&obj->Push);
    free(obj);
    //�ͷ�ָ�����
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/