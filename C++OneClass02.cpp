#include <stdio.h>
#include <iostream>
using namespace std;


//�������
void test() {
	int a = 10;
	int b;
	printf("%d\n", a);//��׼����c���
	scanf("%d", &b);//��׼����c����

	//C++�������
	//����Ҫ��ʾָ��������������ĸ�ʽ��֧�����������
	std::cout << a << "\n" << std::endl;
	std::cin >> b >> a;//c++������
	cout << a << "\n" << endl;
	cin >> b >> a;
}

void testSting() {
	char* p = "1234";
	int* pa = &p;
	cout << pa << endl;//���ַ���ָ�������ַ
	cout << p << endl;//�ַ���ָ���������
}