#include <stdio.h>
#include <iostream>
using namespace std;

//ȱʡ����
//ȫȱʡ
void Func1(int a = 1, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}

//��ȱʡ:����ȱʡ
void Func2(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}


//ȱʡֵֻ�ܹ��������������߶���ĵط������ܹ�ͬʱ����
void Func3(int a, int b, int c);
void Func3(int a = 100, int b = 200, int c = 300) {
	cout << a << b << c << endl;
}


