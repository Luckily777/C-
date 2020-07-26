//lambda表达式

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
	// 默认按照小于比较，排出来结果是升序
	std::sort(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	// 如果需要降序，需要改变元素的比较规则
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
	//最简单的lambda表达式
	[] {};
	//mutable: 把捕捉列表中的变量属性改为非const(默认是const属性）
	[a, b]()mutable {a = 100; b = 200; return a + b; };
	auto func = [](int a, int b)->int {a = 1; b = 2; return a + b; };
	//lambda表达式使用
	func(a, b);
}

void testLambda3()
{
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	//[=]:以传值形式捕捉父类作用域的所有变量
	auto func1 = [=](int num)mutable->int {
		a = 5;
		b = 10;
		//c不能捕捉， c还没有定义
		//return a + b +c + num;
		return a + b + num;
	};

	func1(300);
	cout << a << " " << b << endl;
	//如果是传引用的形式，不需要mutable也可以修改捕捉列表中的变量
	auto func2 = [&](int num)->int {
		a = 5;
		b = 10;
		//c不能捕捉， c还没有定义
		//return a + b +c + num;
		return a + b + num;
	};

	func2(300);
	cout << a << " " << b << endl;

	int c = 3;

	//[=,&a]除过a之外， 其它变量以值的形式捕捉，a以引用的形式捕捉
	//[=,a]: 错误写法
	auto func3 = [=, &a](int num)->int {
		return a + b + num;
	};
	//[&,a]: 除过a之外， 其它变量以引用的形式捕捉，a以值的形式捕捉
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
		//父类作用域不一定就是直接父类作用域，也可以是嵌套父域
		auto func1 = [=](int num)->void {
			//a,b属于C::printC函数的局部域
			cout << a << " " << b << " " << this->_c << endl;
			//_c属于类域C
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

//如果不是局部域，捕捉列表中不能指定具体的变量，但是可以写=或&
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
	//lambda表达式之间不能赋值
	//fun2 = fun1;
	//但是可以拷贝
	auto fun3(fun2);
	auto fun4 = fun2;
	fptr ptr;
	//可以把lambda表达式赋给一个函数指针
	ptr = fun1;

	//接口不一致
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

	//C++实现lambda表达式： 创建一个仿函数类
	auto func = [](int a, int b)->int {return a + b; };
	func(1, 2);
}