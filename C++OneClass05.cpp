#include <stdio.h>
#include <iostream>
using namespace std;

//����
//���ã����� + & + ��������
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
	//������ö�������ʼ��
	//Ҳ���ǲ��ܹ����� int& ra3;
	int b = -1;
	ra1 = b;//��ֵ ���ö���֮�󣬲�����ȥ����ʵ���ָ��
	ra1 = -100;
}

void test() {
	//const������
	const int a = 10;
	const int& ra = a;
	const int& r = 10;
	double d = 2.0;
	double& rd1 = d;
	int c = d;
	//d��ʽ����ת���������ɵ���һ����ʱ�����ͱ��������rd2��ָ���Ϊ����ʱ��������ʱ�����߱��г������ԣ����ܹ�������
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

/*���ܹ���ɽ���
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
	Swap(a, b);//���ܹ���ɽ���
}

int& Add1(int& a) {
	return ++a;
}

//����������ֵʱ��һ��Ҫע�⣬���ر�������������һ��Ҫ���ں�������������
int& Add2(int a) {
	return ++a;
}

void Test3() {
	int a = 0;
	int& b= Add1(a);
	int c= Add1(a);
	int& d= Add2(a);//�޷����
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
	////��������ֵ��˳�� ��������
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

