// ��Χfor + NULL��ֵ
// for��Ҫ�����ı����������ķ�Χ
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std

void test6()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";
	cout << endl;
	//��Χfor: ʹ�ó����� ���ݷ�Χȷ��
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}


void test7(int array[])
{
	//array���һ��ָ�����ͣ�û��ȷ�������ݷ�Χ�����Բ��ܹ�ʹ�÷�Χfor
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}





//NULL����0
void test8()
{
	int* p = NULL;  // int* p = 0;
	int* p2 = 0;  //������ָ��û������
}

void fun6(int a)
{
	cout << "fun6(int)" << endl;
}

void fun6(int* pa)
{
	cout << "fun6(int*)" << endl;
}

struct AS
{

};

void test9()
{
	fun6(NULL);  //������Ĭ��NULLΪ���ε�0��������ָ���ֵ
	fun6((int*)NULL); // NULL: �����ԣ� ָ���ֵ������0
	//nullptr: ָ���ֵ�� ������nullptr��ʾָ���ֵ��������ȷ
	fun6(nullptr);
	//nullptr������ʽת��������ָ������(���ú��Զ���)
	int* p = nullptr;
	char* p1 = nullptr;
	float* p2 = nullptr;
	AS* pas = nullptr;
	//nullptr���ͣ� nullptr_t
	cout << typeid(nullptr).name() << endl;
	cout << sizeof(nullptr) << endl;
	auto p3 = nullptr;
	cout << typeid(p3).name() << endl;
}