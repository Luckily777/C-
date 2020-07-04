//单继承和多继承
#include <iostream>
using namespace std;

class Base {
	public:
		
		virtual void func1() { cout << "Base::func1" << endl; }
		virtual void func2() { cout << "Base::func2" << endl; }
	private:
		int a;
	};
	class Derive :public Base {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
		virtual void func4() { cout << "Derive::func4" << endl; }
	private:
		int b;
	};

	class Base1 {
	public:
		virtual void func1() { cout << "Base1::func1" << endl; }
		virtual void func2() { cout << "Base1::func2" << endl; }
	private:
		int b1;
	};
	class Base2 {
	public:
		virtual void func1() { cout << "Base2::func1" << endl; }
		virtual void func2() { cout << "Base2::func2" << endl; }
	private:
		int b2;
	};
	
	class Derive : public Base1, public Base2 {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
	private:
		int d1;
	};
	
	//定义 函数指针： void 函数()
	typedef void(*vfPtr)();
	
	void doVF(vfPtr* vftable)
	{
		cout << "虚表地址:" << vftable << endl;
		//nullptr： 结束
		for (int i = 0; vftable[i] != nullptr; ++i)
		{
			//获取当前虚表位置的函数指针
			vfPtr func = vftable[i];
			//执行指向的函数
			func();
		}
	}
	
	void test()
	{
		Base1 b;
		Base2 b2;
		Derive d;
		cout << "Base1:" << &b << endl;
		vfPtr* vftable = (vfPtr*)(*((int*)&b));
		doVF(vftable);
	
		cout << "Base2:" << &b2 << endl;
		vftable = (vfPtr*)(*((int*)&b2));
		doVF(vftable);
		
		//访问Derive的第一个虚表
		vftable = (vfPtr*)(*((int*)&d));
		cout << "Derive first vftable:" << &d << endl;
		doVF(vftable);
	
		//访问Derive的第二个虚表: 地址偏移
		vftable = (vfPtr*)(*((int*)((char*)&d + sizeof(Base1))));
		cout << "Derive second vftable:" << (int*)((char*)&d + sizeof(Base1)) << endl;
		doVF(vftable);
	}
	
	int main()
	{
		test();
		return 0;
	}