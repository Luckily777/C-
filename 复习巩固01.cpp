#include <iostream>
using namespace std;


//
//class A {
//public:
//	A(char* s)
//	{
//		cout << s << endl;
//	} 
//	~A() {}
//};
//class B :virtual public A
//{
//public :
//	B(char* s1, char* s2) : A(s1) {
//		cout << s2 << endl;
//	}
//};
//
//class C :virtual public A
//{
//public :
//	C(char* s1, char* s2) : A(s1) {
//		cout << s2 << endl;
//	}
//};
//class D :public B, public C
//{
//public:
//	D(char* s1, char* s2, char* s3, char* s4) 
//		:B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};


//class A {
//	void test(float a) { cout << "1"; }
//};
//class B :public A {
//	void test(int b) { cout << "2"; }
//};


#include<iostream>
using namespace std;
class B0//基类BO声明
{
	public ://外部接口
	virtual void display()//虚成员函数
	{
		cout << "B0::display0" << endl;
	}
};
class B1 :public B0//公有派生
{
	public :
	void display() { cout << "B1::display0" << endl; }
};
class D1 : public B1//公有派生
{
	public :
	void display() { cout << "D1::display0" << endl; }
};
void fun(B0 ptr)//普通函数
{
	ptr.display();
} 
int main()//主函数
{
	B0 b0;//声明基类对象和指针
	B1 b1;//声明派生类对象
	D1 d1;//声明派生类对象
	fun(b0);//调用基类B0函数成员
	fun(b1);//调用派生类B1函数成员
	fun(d1);//调用派生类D1函数成员
}
//
//int main() {
//	/*D* p = new D("class A", "class B", "class C", "class D");
//	delete p;*/
//
//	A* a = new A;
//	B* b = new B;
//	a = b;
//	a.test(1.1);
//	return 0;
//}

