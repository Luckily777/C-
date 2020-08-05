//类型转换

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
	//隐式类型转换：意义比较接近
	char c = 'a';
	int a = c;
	float f = 1.2f;
	int d = f;

	//强制类型:意义差别比较大
	int* ptr = &a;
	int e = (int)ptr;
	int* ptr2 = (int*)a;

	//C++新增的类型转换：static_cast   reinterpret_cast  const_cast  dynamic_cast

	//static_cast: 支持所有隐式类型转换
	int m = static_cast<int>(c);
	int d2 = static_cast<int>(f);

	//reinterpret_cast: 支持强制类型转换
	int* ptr3 = reinterpret_cast<int*> (a);

	fptr fp = reinterpret_cast<fptr> (func);
	//fp();

	//const_cast: 去掉const属性
	const int ca = 10;
	cout << "ca: " << ca << endl;
	int* ptrca = const_cast<int*> (&ca);
	*ptrca = 20;
	/*cout << ptrca << endl;
	cout << &ca << endl;
	cout << "ca: " << ca << endl;*/

	//dynamic_cast: 只能用于多态, 进行向下转型: 进行安全转换，如果转换不成功，返回空指针

	A* pa = new A;
	A* pb = new B;

	B* pb2 = (B*)pa;
	//static_cast: 父类转子类，不进行安全判断
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