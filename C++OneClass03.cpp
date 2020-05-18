#include <stdio.h>
#include <iostream>
using namespace std;

//缺省参数
//全缺省
void Func1(int a = 1, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}

//半缺省:部分缺省
void Func2(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}


//缺省值只能够出现在声明或者定义的地方，不能够同时出现
void Func3(int a, int b, int c);
void Func3(int a = 100, int b = 200, int c = 300) {
	cout << a << b << c << endl;
}


