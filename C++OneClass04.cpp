#include <stdio.h>
#include <iostream>
using namespace std;

//��������
//��������ͬ��������ͬ������ͬһ��������C++֧�֣�C��֧��
//�������ֻ�Ƿ���ֵ��ͬ�Ļ������ܹ����ɺ�������
int Add(int a = 1, int b = 2) {
	return a + b;
}

float Add(float a, float b) {
	return a + b;
}

int Add(int a, int b ,int c) {
	return a + b + c;
}

int Add(char a, char b) {
	return a + b;
}

int Add(int a, char b) {
	return a + b;
}

int Add(char a, int b) {
	return a + b;
}


//extern "C" �ñ���������C���Եı��������б���
extern "C" {
	int sub(int a, int b);
	int mul(int a, int b);
}


void Test() {
	int a = 1;
	int b = 2;
	float c = 1.5;
	float d = 2.5;
	char f = 'a';
	int e = 3;
	Add(a, b);
	Add(c, d);
	Add(a, b,e);
	Add(a, f);
	Add(f, a);
}

void test() {
	sub(4, 2);
	mul(4, 2);
}