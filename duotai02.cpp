#include <iostream>
using namespace std;

//class Car
//{
//public:
//	//final定义的函数不能被重写， 体现实现继承
//	/*virtual void Drive() final {}*/
//	virtual void Drive() {}
//};
//class Benz :public Car
//{
//public:
//	//override: 强制子类重写父类的某一个虚函数， 体现接口继承
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//	virtual void Drive(int a = 10){ cout << "Benz-舒适-(int)" << endl; }
//};
//
//
//void test()
//{
//	Car* ptr = new Benz;
//	ptr->Drive();
//}
//
////抽象类：包含纯虚函数的类
////抽象类不能实例化对象
////意义： 实现多态
////体现：接口继承
//class A
//{
//public:
//	//纯虚函数： 没有函数体的虚函数
//	virtual void fun() = 0;
//};
//
//class B : public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//};
//
//void test2()
//{
//	/*A a;
//	a.fun();*/
//
//	B b;
//	A* pb = &b;
//	b.fun();
//	pb->fun();
//}

//class D
//{};
//
//class Car
//{
//public:
//	virtual void Drive() {}
//	//包含隐含成员变量：虚函数表指针
//};
//
//void test()
//{
//	D d;
//	Car car;
//	cout << sizeof(Car) << endl;   // A: 1   B:0   C: 4    D:8
//}

//class Base
//{
//public:
//	
//
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	//虚表：存放函数指针的数组
//	//     
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//void test()
//{
//	Base b;
//	Derive d;
//
//	Base& rb = b;
//	Base& rd = d;
//
//	rb.Func1();
//	rd.Func1();
//	rd.Func2();
//
//	d.Func1();
//}

//class Base {
//public:
//	
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
////定义 函数指针： void 函数()
//typedef void(*vfPtr)();
//
//void doVF(vfPtr* vftable)
//{
//	cout << "虚表地址:" << vftable << endl;
//	//nullptr： 结束
//	for (int i = 0; vftable[i] != nullptr; ++i)
//	{
//		//获取当前虚表位置的函数指针
//		vfPtr func = vftable[i];
//		//执行指向的函数
//		func();
//	}
//}
//
//void test()
//{
//	Base1 b;
//	Base2 b2;
//	Derive d;
//	cout << "Base1:" << &b << endl;
//	vfPtr* vftable = (vfPtr*)(*((int*)&b));
//	doVF(vftable);
//
//	cout << "Base2:" << &b2 << endl;
//	vftable = (vfPtr*)(*((int*)&b2));
//	doVF(vftable);
//	
//	//访问Derive的第一个虚表
//	vftable = (vfPtr*)(*((int*)&d));
//	cout << "Derive first vftable:" << &d << endl;
//	doVF(vftable);
//
//	//访问Derive的第二个虚表: 地址偏移
//	vftable = (vfPtr*)(*((int*)((char*)&d + sizeof(Base1))));
//	cout << "Derive second vftable:" << (int*)((char*)&d + sizeof(Base1)) << endl;
//	doVF(vftable);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//class B :/*virtual */public A
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//class C :/*virtual */public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public B, public C
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3)/*, A(s1)*/
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main(){
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << p3 << endl;
//	return 0;
//}

class A
{
public:
	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
	virtual void test(){ this->func(); }
};
class B : public A
{
public:
	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}