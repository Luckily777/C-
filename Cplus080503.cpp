//单例模式

#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

//饿汉模式
// 1. 构造函数私有
// 2. 提供一个静态的方法返回单例
// 3. 声明一个静态的单例成员
// 4. 拷贝构造和赋值声明为delete函数

// 特点： 实现简单， 多线程情景下效率高
// 缺点： 程序启动慢， 多个单例对象初始化的顺序无法控制
class singleton
{
public:
	static singleton* getInstance()
	{
		return &_single;
	}
private:
	//构造函数私有
	singleton() {};

	//防拷贝
	singleton(const singleton& s) = delete;
	singleton& operator=(const singleton& s) = delete;

	static singleton _single;
};

//静态成员的初始化
singleton singleton::_single;


//懒汉模式
// 1. 构造函数私有
// 2. 提供一个静态的方法返回单例: 第一次调用， 创建对象， 后续调用直接返回
// 3. 声明一个静态的单例指针， 指针初始化为nullptr
// 4. 拷贝构造和赋值声明为delete函数
// 5. 保证线程安全(修改指针), 双检查提高效率

// 特点： 延迟加载，程序启动块， 可以指定多个单例对象的初始化顺序
// 实现复杂
class singleton2
{
public:
	static singleton2* getInstance()
	{
		//双检查
		if (_ptr == nullptr)
		{
			_mtx.lock();
			if (_ptr == nullptr)
			{
				//第一次调用，创建对象
				_ptr = new singleton2;
			}
			_mtx.unlock();
		}
		return _ptr;
	}

	//可写可不写
	class GC
	{
	public:
		~GC()
		{
			if (_ptr)
				delete _ptr;
		}
	};

private:
	singleton2() {};

	//防拷贝
	singleton2(const singleton2&) = delete;
	singleton2& operator=(const singleton2&) = delete;

	static singleton2* _ptr;
	static mutex _mtx;
	static GC _gc;
};

singleton2* singleton2::_ptr = nullptr;
mutex singleton2::_mtx;
singleton2::GC singleton2::_gc;

void testSingleton()
{
	singleton* s1 = singleton::getInstance();
	singleton2* s2 = singleton2::getInstance();
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "---------------------------------" << endl;
		s1 = singleton::getInstance();
		s2 = singleton2::getInstance();
		cout << "s1:" << s1 << endl;
		cout << "s2:" << s2 << endl;
	}
}


//void testSingleton2(int n)
//{
//	cout << singleton2::getInstance() << endl;
//}

void testSingleton2(int n)
{
	for (int i = 0; i < n; ++i)
		//cout << singleton2::getInstance() << endl;
		singleton2::getInstance();
}

void testThread()
{
	int n;
	cin >> n;
	thread t1(testSingleton2, n);
	thread t2(testSingleton2, n);
	thread t3(testSingleton2, n);
	thread t4(testSingleton2, n);
	thread t5(testSingleton2, n);
	thread t6(testSingleton2, n);
	thread t7(testSingleton2, n);
	thread t8(testSingleton2, n);
	thread t9(testSingleton2, n);
	thread t10(testSingleton2, n);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
}