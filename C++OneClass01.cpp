#include <stdio.h>
#include <iostream>
using namespace std;


//�����ռ�
namespace N1 {
	void Print(int a) {
		printf("%d \n", a);
	}


	int a;
	int b;


	//Ƕ�׶���
	namespace N2 {
		void Fun1(int a) {
			printf("%d\n", a);
		}
		int a;
		int b;
	}
}

//��ͬ�������ռ䲻�ܹ������ظ��ı����ͺ���
//���Էֶζ��壬��������ϲ���ͬ�������ռ�
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
//�����ռ��ʹ��


//1. using N1::a;
//2. using N1::a;��a�ͷ���ȫ����֮��
//3. using namespace N1; ����ȫ���ͷ���ȫ����֮��

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
	a = 10;//�ֲ���
	N1::a = 20;//�����ռ���
	N1::N2::a = 30;//�����ռ���
	::a = 40;//ȫ��������
}