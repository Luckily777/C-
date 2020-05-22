//类的模型大小
#include <stdio.h>
#include <iostream>
using namespace std;

class C {
	int _a;
};

class D {
	int _a;
	void fun1() {
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class E {
	void fun1() {
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class F {

};

void test() {
	cout << sizeof(C) << " " << sizeof(D) << " " << sizeof(E) << " " << sizeof(F) << " " << endl;
	F f;
}


//类的大小也遵循内存对齐的规则
class G
{
	char _c;   //1
	double _d; // 16
	int _a;  // 20
	char _c2;  //21
	//24
	//嵌套类本身遵循内存对齐的原则，计算大小： H: 24
	class H
	{
		double _d;  //8
		char _c; //9
		int _a; //16
		char _c1; //17
		//24
	};
	H _h;
};
//sizeof(G):  

void test3()
{
	cout << sizeof(G) << endl;
}

struct I
{
	char _c;   //1
	double _d; // 16
	int _a;  // 20
	char _c2;  //21
};

void test4()
{
	I oi;
	cout << (char*)&oi._c2 - (char*)&oi << endl;
}


union U
{
	int _a;
	char _c;
};
void test5()
{
	int a = 1;  //0x 00 00 00 01
	char* pa = (char*)&a;
	if (*pa == 1)
		cout << "littel end" << endl;
	else
		cout << "big end" << endl;
	U u;
	u._a = 1;
	if (u._c == 1)
		cout << "littel end" << endl;
	else
		cout << "big end" << endl;

}


int main()
{
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}