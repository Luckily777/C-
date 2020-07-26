//线程
#include <thread>

void tfunc1()
{
	cout << "tfunc1()" << endl;
}

void tfunc2(int a)
{
	cout << "tfunc2(int)" << endl;
}

void tfunc3(int a, int b, int c)
{
	cout << "tfunc3(int, int,int)" << endl;
}



void testThread()
{
	//thread t1;

	thread t1(tfunc1);
	thread t2(tfunc2, 1);
	thread t3(tfunc3, 1, 2, 3);
	return;
	cout << "线程等待" << endl;
	t1.join();
	t2.join();
	t3.join();
}

//RAII: 资源获取立即初始化
//  在构造函数中初始化资源
//  在析构函数中销毁资源
class ThreadManage
{
public:
	ThreadManage(thread& t)
		:_thread(t)
	{}

	~ThreadManage()
	{
		if (_thread.joinable())
			_thread.join();
	}
private:
	thread& _thread;
};

void testThread2()
{
	//thread t1;

	thread t1(tfunc1);
	thread t2(tfunc2, 1);
	thread t3(tfunc3, 1, 2, 3);
	ThreadManage tm1(t1);
	ThreadManage tm2(t2);
	ThreadManage tm3(t3);

	return;
	/*cout << "线程等待" << endl;
	t1.join();
	t2.join();
	t3.join();*/
}

class ThreadClass
{
public:
	void funcT(int a)
	{
		cout << a << endl;
	}
};

void testClassFunc()
{
	ThreadClass tc;
	//如果函数为成员函数，则需要写完整作用域，并且需要显示取地址，参数需要加上this指向的对象
	thread t1(&ThreadClass::funcT, &tc, 10);
	t1.join();
}

void func2(int& a)
{
	a += 10;
}

void func3(int* a)
{
	*a += 10;
}

void testThreadRef()
{
	int a = 0;
	cout << a << endl;
	//如果函数参数类型为引用，在线程中需要修改原始的变量，则需要通过ref转换
	thread t1(func2, ref(a));
	t1.join();
	cout << a << endl;

	thread t2(func3, &a);
	t2.join();
	cout << a << endl;
}