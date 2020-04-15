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
	static char map[][2] = { {'[',']'},{'(',')'},{'{','}'} };
	//����������������Ԫ�أ�Ϊ���������бȶ�
	Stcak st;
	//����ջ����
	stackInit(&st, 10);
	//��ʼ��ջ����
	while (*s) {
		//����ѭ��
		int flag = 0;
		//���÷��ű����������н���ջ�ı�ʾ
		for (int i = 0; i < 3; i++) {
			//�������У����ѭ��3��
			if (*s == map[i][0]) {
				//���ַ����е�������ַ�
				flag = 1;
				//�������ջ�����������ٴν���ѭ������
				stackPush(&st,*s);
				//��ջ����
				s++;
				//�ַ�������
				break;
				//����
			}
		}
		if (flag == 0) {
			//��δ��ջ�������������һ������
			if (stackEmpty(&st)) {
				//�пղ�������ջ���ǿգ�������
				return false;
			}
			char Top = stackTop(&st);
			//ջ��Ԫ��
			for (int i = 0; i < 3; i++) {
				//��Ȼ������
				if (map[i][1] == *s) {
					//���ַ����е�Ԫ�ص���������
					if (Top == map[i][0]) {
						//���ж�ջ�ж�����Ԫ���Ƿ����������ƥ���������
						s++;
						stackPop(&st);
						//��ջ����
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
		//����ж��Ƿ���꣬������ջ��ɺ���Ϊ��
		return true;
	}
	else {
		return false;
	}
}