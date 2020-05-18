#include <stdio.h>
#include <iostream>
using namespace std;


//命名空间
namespace N1 {
	void Print(int a) {
		printf("%d \n", a);
	}


	int a;
	int b;


	//嵌套定义
	namespace N2 {
		void Fun1(int a) {
			printf("%d\n", a);
		}
		int a;
		int b;
	}
}

//相同的命名空间不能够定义重复的变量和函数
//可以分段定义，编译器会合并相同的命名空间
namespace N1 {
	int c;
	int d;
	void Fun2(){
		printf("fun2()\n");
	}
	void Fun3() {
		printf("fun3()\n");
	}
}

void Fun1(int a) {
	printf("%d\n", a);
}

void Print(int a) {
	printf("%d \n", a);
}

void Fun2() {
	printf("fun2()\n");
}

void Fun3() {
	printf("fun3()\n");
}


int a;
int b;
//命名空间的使用


//1. using N1::a;
//2. using N1::a;将a释放在全局域之中
//3. using namespace N1; 将其全部释放在全局域之中

void NmaespaceUse(){
	N1::a = 1;
	N1::Print(N1::a);
	N1::Print(a);
	N1::N2::a = 2;
	N1::c = 3;
	N1::Fun2;
	N1::Fun3;
}


void Fun4(int a) {
	a = 10;//局部域
	N1::a = 20;//命名空间域
	N1::N2::a = 30;//命名空间域
	::a = 40;//全局作用域
}