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
class B0//����BO����
{
	public ://�ⲿ�ӿ�
	virtual void display()//���Ա����
	{
		cout << "B0::display0" << endl;
	}
};
class B1 :public B0//��������
{
	public :
	void display() { cout << "B1::display0" << endl; }
};
class D1 : public B1//��������
{
	public :
	void display() { cout << "D1::display0" << endl; }
};
void fun(B0 ptr)//��ͨ����
{
	ptr.display();
} 
int main()//������
{
	B0 b0;//������������ָ��
	B1 b1;//�������������
	D1 d1;//�������������
	fun(b0);//���û���B0������Ա
	fun(b1);//����������B1������Ա
	fun(d1);//����������D1������Ա
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

