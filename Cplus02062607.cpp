//多态练习




class A
{
public:
	void printV()
	{
		cout << "A::printV()" << endl;
	}
};

class B : public A
{
public:
	//新定义的虚函数
	virtual void printV()
	{
		cout << "B::printV()" << endl;
		A::printV();
	}

	//继承自A的普通函数printV
};

class C : public B
{
public:
	//接口完全一致，虚函数重写
	virtual void printV()
	{
		cout << "C::printV()" << endl;
	}
};

void func(A& A)
{
	A.printV();
}

void fund(B& b)
{
	b.printV();
}

void test()
{
	A a;
	B b;
	C c;

	/*func(a);
	func(b);*/

	/*fund(b);
	fund(c);*/

	b.printV();
}

int main()
{
	test();
	return 0;
}