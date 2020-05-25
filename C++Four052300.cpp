//如果没有volatile的话，c++编译会认为a是常量，将其放在存储器中，因此指针更改了a的值之后，*pa会变为20，但a只会从存储器中去取出所存入的10；
//而如果加上volatile的话会阻止优化，不会在更新之前将a放入存储器，因此所打印出来的值，a和*pa都是20；

void test2()
{
	const volatile int a = 10;
	int* pa = (int*)&a;
	*pa = 20;
	cout << a << endl;
	cout << *pa << endl;
}

int main()
{
	//test1();
	////test2();
	//test3();
	//test4();
	test5();
	return 0;
}
