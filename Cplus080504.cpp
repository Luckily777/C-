//����ת��

typedef void(*fptr)();

int func(int a)
{
	cout << "func(int)" << a << endl;
	return 0;
}

class A
{
public:
	virtual void func() {};
};

class B : public A
{
public:
	int _b = 10;
};

void testCast()
{
	//��ʽ����ת��������ȽϽӽ�
	char c = 'a';
	int a = c;
	float f = 1.2f;
	int d = f;

	//ǿ������:������Ƚϴ�
	int* ptr = &a;
	int e = (int)ptr;
	int* ptr2 = (int*)a;

	//C++����������ת����static_cast   reinterpret_cast  const_cast  dynamic_cast

	//static_cast: ֧��������ʽ����ת��
	int m = static_cast<int>(c);
	int d2 = static_cast<int>(f);

	//reinterpret_cast: ֧��ǿ������ת��
	int* ptr3 = reinterpret_cast<int*> (a);

	fptr fp = reinterpret_cast<fptr> (func);
	//fp();

	//const_cast: ȥ��const����
	const int ca = 10;
	cout << "ca: " << ca << endl;
	int* ptrca = const_cast<int*> (&ca);
	*ptrca = 20;
	/*cout << ptrca << endl;
	cout << &ca << endl;
	cout << "ca: " << ca << endl;*/

	//dynamic_cast: ֻ�����ڶ�̬, ��������ת��: ���а�ȫת�������ת�����ɹ������ؿ�ָ��

	A* pa = new A;
	A* pb = new B;

	B* pb2 = (B*)pa;
	//static_cast: ����ת���࣬�����а�ȫ�ж�
	B* pb5 = static_cast<B*> (pa);
	cout << pb2->_b << endl;
	B* pb3 = dynamic_cast<B*> (pa);

	B* pb4 = dynamic_cast<B*> (pb);


}


int main()
{
	//testSingleton();
	//testThread();
	testCast();
	return 0;
}