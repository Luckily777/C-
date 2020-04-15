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
	static char map[][2] = { {'[',']'},{'(',')'},{'{','}'} };
	//遍历所给出的括号元素，为方便后面进行比对
	Stcak st;
	//创建栈变量
	stackInit(&st, 10);
	//初始化栈变量
	while (*s) {
		//进行循环
		int flag = 0;
		//设置符号变量，来进行进出栈的表示
		for (int i = 0; i < 3; i++) {
			//三行两列，因此循环3次
			if (*s == map[i][0]) {
				//若字符串中等于左边字符
				flag = 1;
				//则代表入栈，接下来则再次进行循环操作
				stackPush(&st,*s);
				//入栈操作
				s++;
				//字符串后移
				break;
				//结束
			}
		}
		if (flag == 0) {
			//若未进栈操作，则进行这一步操作
			if (stackEmpty(&st)) {
				//判空操作，若栈中是空，则跳出
				return false;
			}
			char Top = stackTop(&st);
			//栈顶元素
			for (int i = 0; i < 3; i++) {
				//依然是三次
				if (map[i][1] == *s) {
					//若字符串中的元素等于右括号
					if (Top == map[i][0]) {
						//则判断栈中顶部的元素是否等于与其相匹配的左括号
						s++;
						stackPop(&st);
						//出栈操作
						break;
					}
					else {
						return false;
					}
				}
			}

		}
	}
	if (stackEmpty(&st)) {
		//最后判断是否出完，若进出栈完成后，则将为空
		return true;
	}
	else {
		return false;
	}
}