用栈来实现队列

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
    //检查容量
    if (st->_size == st->_capacity)
    {
        st->_capacity *= 2;
        st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
    }
    //尾插
    st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
    //尾删
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
    //一个push栈
    Stack Pop;
    //一个pop栈
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* ms = (MyQueue*)malloc(sizeof(MyQueue));
    //申请空间
    stackInit(&ms->Push, 10);
    //对两个栈全部进行初始化
    stackInit(&ms->Pop, 10);
    return ms;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(&obj->Push, x);
    //进行入栈操作
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ret;
    if (stackEmpty(&obj->Pop)) {
        //判断pop栈是否为空，若为空返回1
        while (stackEmpty(&obj->Push) != 1) {
            //push栈若不为空
            ret = stackTop(&obj->Push);
            //将push栈顶的元素放置在ret中
            stackPop(&obj->Push);
            //将push进行出栈操作
            stackPush(&obj->Pop, ret);
            //将ret入栈到pop
        }
    }
    ret = stackTop(&obj->Pop);
    //将pop栈顶端的元素赋值给ret
    stackPop(&obj->Pop);
    //最后进行出栈操作
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
        //同理 
    }
    return stackTop(&obj->Pop);
    //返回pop最顶层变量
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&obj->Push) && stackEmpty(&obj->Pop);
    //判空操作，判断两个栈都为空，则总的为空

}

void myQueueFree(MyQueue* obj) {
    stackDestory(&obj->Pop);
    //销毁两个栈
    stackDestory(&obj->Push);
    free(obj);
    //释放指针变量
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