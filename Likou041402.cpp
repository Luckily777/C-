20. 有效的括号


//顺序表实现栈
typedef char Type;

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

bool isValid(char* s) {
    //左右括号的映射
    static char map[][2] = { {'(', ')'},
     {'[', ']'}, {'{', '}'} };
    Stack st;
    stackInit(&st, 10);

    //遍历字符串， 左括号入栈， 右括号匹配
    while (*s)
    {
        int i = 0;
        //flag: 是否找到一个左括号
        int flag = 0;
        //判断是否为左括号
        for (; i < 3; ++i)
        {
            if (*s == map[i][0])
            {
                //左括号入栈
                stackPush(&st, *s);
                ++s;
                flag = 1;
                break;
            }
        }
        //循环走完，说明不是一个左括号
        //if(i == 3)
        if (flag == 0)
        {
            //让当前的右括号匹配栈顶元素
            if (stackEmpty(&st))
                return false;
            char topChar = stackTop(&st);


            //找出对应的右括号在map的位置
            for (int j = 0; j < 3; ++j)
            {
                if (*s == map[j][1])
                {
                    if (topChar == map[j][0])
                    {
                        //左右匹配
                        stackPop(&st);
                        ++s;
                        break;
                    }
                    else
                        return false;
                }
            }

        }

    }

    if (stackEmpty(&st))
        return true;
    return false;
}