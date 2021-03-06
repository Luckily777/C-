20. ��Ч������


//˳���ʵ��ջ
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

bool isValid(char* s) {
    //�������ŵ�ӳ��
    static char map[][2] = { {'(', ')'},
     {'[', ']'}, {'{', '}'} };
    Stack st;
    stackInit(&st, 10);

    //�����ַ����� ��������ջ�� ������ƥ��
    while (*s)
    {
        int i = 0;
        //flag: �Ƿ��ҵ�һ��������
        int flag = 0;
        //�ж��Ƿ�Ϊ������
        for (; i < 3; ++i)
        {
            if (*s == map[i][0])
            {
                //��������ջ
                stackPush(&st, *s);
                ++s;
                flag = 1;
                break;
            }
        }
        //ѭ�����꣬˵������һ��������
        //if(i == 3)
        if (flag == 0)
        {
            //�õ�ǰ��������ƥ��ջ��Ԫ��
            if (stackEmpty(&st))
                return false;
            char topChar = stackTop(&st);


            //�ҳ���Ӧ����������map��λ��
            for (int j = 0; j < 3; ++j)
            {
                if (*s == map[j][1])
                {
                    if (topChar == map[j][0])
                    {
                        //����ƥ��
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