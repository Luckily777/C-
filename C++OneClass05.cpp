#include <stdio.h>
#include <iostream>
using namespace std;

//引用
//引用：类型 + & + 引用名称
void Test(){
	int a = 10;
	int& ra1 = a;
	int& ra2 = a;
	ra2 = 30;
	ra1 = 100;
	a = 100;
	cout << &a << endl;
	cout << &ra1 << endl;
	cout << &ra2 << endl;
	//如果引用定义必须初始化
	//也就是不能够出现 int& ra3;
	int b = -1;
	ra1 = b;//赋值 引用定义之后，不会再去更改实体的指向
	ra1 = -100;
}

void test() {
	//const的引用
	const int a = 10;
	const int& ra = a;
	const int& r = 10;
	double d = 2.0;
	double& rd1 = d;
	int c = d;
	//d隐式类型转换，所生成的是一个临时的整型变量，因此rd2所指向的为此临时变量，临时变量具备有常量特性，不能够被更改
	const int& rd2 = d;
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& ra, int& rb) {
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

/*不能够完成交换
void Swap(int ra,int rb){
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
*/

void Test2() {
	int a = 1;
	int b = 2;
	Swap(&a, &b);
	Swap(a, b);//不能够完成交换
}

int& Add1(int& a) {
	return ++a;
}

//引用做返回值时，一定要注意，返回变量的生命周期一定要大于函数的生命周期
int& Add2(int a) {
	return ++a;
}

void Test3() {
	int a = 0;
	int& b= Add1(a);
	int c= Add1(a);
	int& d= Add2(a);//无法完成
	cout << d << endl;
	cout << a << endl;
	cout << d << endl;
}


int main()
{
	//test();
	//test2();
	//fun5(1, 2, 3);
	//fun5();
	//fun5(100, 200, 300); 
	////参数接收值的顺序： 从左向右
	//fun6(5);
	//fun6(5, 6);
	//fun6(7, 8, 9);
	//fun8();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}

