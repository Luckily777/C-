#include <iostream>
using namespace std;

//class Car
//{
//public:
//	//final����ĺ������ܱ���д�� ����ʵ�ּ̳�
//	/*virtual void Drive() final {}*/
//	virtual void Drive() {}
//};
//class Benz :public Car
//{
//public:
//	//override: ǿ��������д�����ĳһ���麯���� ���ֽӿڼ̳�
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//	virtual void Drive(int a = 10){ cout << "Benz-����-(int)" << endl; }
//};
//
//
//void test()
//{
//	Car* ptr = new Benz;
//	ptr->Drive();
//}
//
////�����ࣺ�������麯������
////�����಻��ʵ��������
////���壺 ʵ�ֶ�̬
////���֣��ӿڼ̳�
//class A
//{
//public:
//	//���麯���� û�к�������麯��
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
//	//����������Ա�������麯����ָ��
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
//	//�����ź���ָ�������
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
////���� ����ָ�룺 void ����()
//typedef void(*vfPtr)();
//
//void doVF(vfPtr* vftable)
//{
//	cout << "����ַ:" << vftable << endl;
//	//nullptr�� ����
//	for (int i = 0; vftable[i] != nullptr; ++i)
//	{
//		//��ȡ��ǰ���λ�õĺ���ָ��
//		vfPtr func = vftable[i];
//		//ִ��ָ��ĺ���
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
//	//����Derive�ĵ�һ�����
//	vftable = (vfPtr*)(*((int*)&d));
//	cout << "Derive first vftable:" << &d << endl;
//	doVF(vftable);
//
//	//����Derive�ĵڶ������: ��ַƫ��
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