//lambda���ʽ

class A
{
public:
	A(int a = 0)
		:_a(a)
	{}

	bool operator<(const A& a) const
	{
		return _a < a._a;
	}

	bool operator>(const A& a) const
	{
		return _a > a._a;
	}
	//private:
public:
	int _a;
};

struct LessA
{
	bool operator()(const A& a1, const A& a2)
	{
		return a1 < a2;
	}
};

struct GreaterA
{
	bool operator()(const A& a1, const A& a2)
	{
		return a1 > a2;
	}
};


void testSort()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };
	// Ĭ�ϰ���С�ڱȽϣ��ų������������
	std::sort(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
	for (auto& e : array)
	{
		cout << e << " ";
	}
	cout << endl;
}

void testSort2()
{
	A array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::sort(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : array)
	{
		cout << e._a << " ";
	}
	cout << endl;
	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<A>());
	for (auto& e : array)
	{
		cout << e._a << " ";
	}
	cout << endl;
	std::sort(array, array + sizeof(array) / sizeof(array[0]), LessA());
	for (auto& e : array)
	{
		cout << e._a << " ";
	}
	cout << endl;
	std::sort(array, array + sizeof(array) / sizeof(array[0]), GreaterA());
	for (auto& e : array)
	{
		cout << e._a << " ";
	}
	cout << endl;

	cout << "lambda:" << endl;
	std::sort(array, array + sizeof(array) / sizeof(array[0]), [](const A& a1, const A& a2)->bool
		{
			return a1 < a2;
		});

	for (auto& e : array)
	{
		cout << e._a << " ";
	}
	cout << endl;

}

void testLambda2()
{

	int a = 10;
	int b = 5;
	//��򵥵�lambda���ʽ
	[] {};
	//mutable: �Ѳ�׽�б��еı������Ը�Ϊ��const(Ĭ����const���ԣ�
	[a, b]()mutable {a = 100; b = 200; return a + b; };
	auto func = [](int a, int b)->int {a = 1; b = 2; return a + b; };
	//lambda���ʽʹ��
	func(a, b);
}

void testLambda3()
{
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	//[=]:�Դ�ֵ��ʽ��׽��������������б���
	auto func1 = [=](int num)mutable->int {
		a = 5;
		b = 10;
		//c���ܲ�׽�� c��û�ж���
		//return a + b +c + num;
		return a + b + num;
	};

	func1(300);
	cout << a << " " << b << endl;
	//����Ǵ����õ���ʽ������ҪmutableҲ�����޸Ĳ�׽�б��еı���
	auto func2 = [&](int num)->int {
		a = 5;
		b = 10;
		//c���ܲ�׽�� c��û�ж���
		//return a + b +c + num;
		return a + b + num;
	};

	func2(300);
	cout << a << " " << b << endl;

	int c = 3;

	//[=,&a]����a֮�⣬ ����������ֵ����ʽ��׽��a�����õ���ʽ��׽
	//[=,a]: ����д��
	auto func3 = [=, &a](int num)->int {
		return a + b + num;
	};
	//[&,a]: ����a֮�⣬ �������������õ���ʽ��׽��a��ֵ����ʽ��׽
	auto func4 = [&, a](int num)->int {
		return a + b + num;
	};
}

class C
{
public:
	void printC()
	{
		int a = 1;
		int b = 2;
		//����������һ������ֱ�Ӹ���������Ҳ������Ƕ�׸���
		auto func1 = [=](int num)->void {
			//a,b����C::printC�����ľֲ���
			cout << a << " " << b << " " << this->_c << endl;
			//_c��������C
			cout << _c << endl;
		};
		func1(30);
	}
public:
	int _c = 5;
};

void testLambda4()
{
	C c;
	c.printC();
}

int global = 10;

//������Ǿֲ��򣬲�׽�б��в���ָ������ı��������ǿ���д=��&
auto funcG = [=](int a, int b)->void {

	cout << global << endl;
};

void func()
{
	auto funcG = [=](int a, int b)->void {

		cout << global << endl;
	};
}

typedef int(*fptr)(int a, int b);
typedef void(*fptr2)();

void testLambda5()
{
	auto fun1 = [](int a, int b)->int {return a + b; };
	auto fun2 = [](int a, int b)->int {return a + b; };
	//lambda���ʽ֮�䲻�ܸ�ֵ
	//fun2 = fun1;
	//���ǿ��Կ���
	auto fun3(fun2);
	auto fun4 = fun2;
	fptr ptr;
	//���԰�lambda���ʽ����һ������ָ��
	ptr = fun1;

	//�ӿڲ�һ��
	//fptr2 ptr2 = fun1;
}

struct Add
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void testLambda6()
{
	Add add;
	add(1, 2);

	//C++ʵ��lambda���ʽ�� ����һ���º�����
	auto func = [](int a, int b)->int {return a + b; };
	func(1, 2);
}