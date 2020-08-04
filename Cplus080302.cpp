//智能指针

#include <thread>
#include <mutex>
#include <memory>
#include <iostream>
using namespace std;
//智能指针：  1. 实现RAII思想   2. 实现指针的功能

template <class T>
class smartPtr
{
public:
	smartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~smartPtr()
	{

		if (_ptr)
		{
			delete _ptr;
			cout << "~smartPtr delete" << endl;
		}

	}

	//管理权转移
	smartPtr(smartPtr<T>& sp)
		:_ptr(sp._ptr)
	{
		sp._ptr = nullptr;
	}

	smartPtr<T>& operator=(smartPtr<T>& sp)
	{
		if (this != &sp)
		{
			//释放原有资源
			if (_ptr)
				delete _ptr;
			//管理权转移
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

class Date
{
public:
	int _year = 1;
};
void testPtr()
{
	/*int* ptr = new int;
	smartPtr<int> sp(ptr);
	smartPtr<int> sp2(ptr);*/

	smartPtr<int> sp3(new int);

	smartPtr<Date> sp4(new Date);
	(*sp4)._year = 100;
	cout << sp4->_year << endl;
	sp4->_year = 200;
	cout << (*sp4)._year << endl;
}

void testPtr2()
{
	smartPtr<Date> sp(new Date);
	smartPtr<Date> copy = sp;  // sp: nullptr    

	smartPtr<Date> sp2(new Date);
	sp2 = copy;  // copy: nullptr

	/*Date* ptr = new Date;
	Date* ptr2 = ptr;

	delete ptr;*/
}

void testAutoPtr()
{
	//auto_ptr: 一般禁止使用， 有解引用异常的风险
	auto_ptr<Date> ap(new Date);
	cout << ap->_year << endl;
	//拷贝时发生管理权转移
	auto_ptr<Date> copy = ap;
	//发生管理权转移之后，智能指针不再拥有资源，故不能访问资源
	//cout << ap->_year << endl;
	cout << copy->_year << endl;
}

void testUniquePtr()
{
	unique_ptr<Date> up(new Date);
	//unique_ptr: 防拷贝-->拷贝构造和赋值运算符定义为delete函数
	/*unique_ptr<Date> copy = up;
	unique_ptr<Date> up2(new Date);
	up2 = up;*/
}

template <class T>
class uniquePtr
{
	uniquePtr(T* ptr)
		:_ptr(ptr)
	{}

	~uniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	//防拷贝
	uniquePtr(const uniquePtr<T>& up) = delete;
	uniquePtr<T>& operator=(const uniquePtr<T>& up) = delete;
private:
	T* _ptr;
};

void testSharedPtr()
{
	shared_ptr<Date>  sp(new Date);
	cout << sp->_year << endl;
	cout << sp.use_count() << endl;
	shared_ptr<Date> copy(sp);
	cout << sp->_year << endl;
	cout << sp.use_count() << endl;
	shared_ptr<Date> sp2(new Date);
	sp2 = sp;
	cout << sp->_year << endl;
	cout << sp.use_count() << endl;

}

//
template <class T, class deletor>
class sharedPtr
{
public:
	sharedPtr(T* ptr, deletor del)
		:_ptr(ptr)
		, _useCount(new int(1))
		, _mtx(new mutex)
		, _del(del)
	{}

	~sharedPtr()
	{
		//引用计数自减
		//if (--(*_useCount) == 0)
		if (subRef() == 0)
		{
			//delete _ptr;
			//定制删除器进行空间释放
			del(_ptr);
			delete _useCount;
			delete _mtx;
			cout << "~sharedPtr" << endl;
		}
	}

	sharedPtr(const sharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
		, _mtx(sp._mtx)
	{
		//++(*_useCount);
		addRef();
	}

	sharedPtr<T>& operator=(const sharedPtr<T>& sp)
	{
		//if (this != &sp)
		//判断管理的资源是否相同
		if (_ptr != sp._ptr)
		{
			//判断当前管理的资源是否需要释放
			//if (--(*_useCount) == 0)
			if (subRef() == 0)
			{
				delete _ptr;
				delete _useCount;
				delete _mtx;
			}
			//赋值
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			_mtx = sp._mtx;
			//++(*_useCount);
			addRef();
		}
		return *this;
	}

	int getUseCount()
	{
		return *_useCount;
	}

	int addRef()
	{
		_mtx->lock();
		++(*_useCount);
		_mtx->unlock();
		return *_useCount;
	}

	int subRef()
	{
		_mtx->lock();
		--(*_useCount);
		_mtx->unlock();
		return *_useCount;
	}

private:
	T* _ptr;
	int* _useCount;
	mutex* _mtx;
	deletor _del;
};

void testSharedPtr2()
{
	sharedPtr<Date> sp(new Date);

	sharedPtr<Date> copy(sp);

	sharedPtr<Date> sp2(new Date);
	sp2 = sp;

	copy = sp2;
}

void func(sharedPtr<Date> sp, int n)
{
	for (int i = 0; i < n; ++i)
	{
		sharedPtr<Date> copy(sp);
	}
}

void testSharedPtr3()
{
	sharedPtr<Date> sp(new Date);
	cout << sp.getUseCount() << endl;
	int n;
	cin >> n;
	thread t1(func, sp, n);
	thread t2(func, sp, n);


	t1.join();
	t2.join();

	cout << sp.getUseCount() << endl;

}


void func2(shared_ptr<Date> sp, int n)
{
	for (int i = 0; i < n; ++i)
	{
		shared_ptr<Date> copy(sp);
	}
}

void testSharedPtr4()
{
	shared_ptr<Date> sp(new Date);
	cout << sp.use_count() << endl;
	int n;
	cin >> n;
	thread t1(func2, sp, n);
	thread t2(func2, sp, n);


	t1.join();
	t2.join();

	cout << sp.use_count() << endl;

}

template <class T>
struct ListNode
{
	/*shared_ptr<ListNode<T>> _prev;
	shared_ptr<ListNode<T>> _next;*/

	weak_ptr<ListNode<T>> _prev;
	weak_ptr<ListNode<T>> _next;

	~ListNode()
	{
		cout << "~ListNode" << endl;
	}
};

void testSharedPtr5()
{
	shared_ptr<ListNode<int>> sp(new ListNode<int>);
	shared_ptr<ListNode<int>> sp2(new ListNode<int>);

	cout << sp.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp->_next = sp2;
	sp2->_prev = sp;

	cout << sp.use_count() << endl;
	cout << sp2.use_count() << endl;

	//weak_ptr: 不能直接使用，需要用shared_ptr进行初始化， 专门解决特殊场景下shared_ptr循环引用的问题
	//weak_ptr<ListNode<int>> wp(new ListNode<int>);
}

class A
{
public:
	A()
	{}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//定制删除器
template <class T>
struct deleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
		cout << "delete Array" << endl;
	}
};

template <class T>
struct freeM
{
	void operator()(T* ptr)
	{
		free(ptr);
		cout << "free" << endl;
	}
};

void testSharedPtr6()
{

	/*deleteArray<A> da;
	shared_ptr<A> sp(new A[100], da);*/

	freeM<int> fm;
	shared_ptr<int> sp((int*)malloc(sizeof(int)), fm);
}

int main()
{
	//testPtr();
	//testPtr2();
	//testAutoPtr();
	//testUniquePtr();
	//testSharedPtr();
	//testSharedPtr2();
	//testSharedPtr3();
	//testSharedPtr4();
	//testSharedPtr5();
	testSharedPtr6();

	return 0;
}