#include <stdio.h>
#include <iostream>
using namespace std;
namespace bite
{
	void print(int a)
	{
		printf("%d \n", a);
	}

	int a;
	int b;
	//Ƕ�׶���
	namespace bite_69
	{
		void fun1(int a)
		{
			printf("%d \n", a);
		}
			int a;
			int b;
		
	}
}

//���Էֶζ��壬��������ϲ���ͬ�������ռ䣬
//��ͬ�������ռ䲻�ܶ����ظ��ı����ͺ���
namespace bite
{
	int c;
	int d;
	void fun2()
	{
		printf("fun2()\n");
	}
	void fun3()
	{
		printf("fun3()\n");
	}
}

void fun2()
{
	printf("fun2()\n");
}

void fun1(int a)
{
	printf("%d \n", a);
}

void print(int a)
{
	printf("%d \n", a);
}

int a;
int b;

//�����ռ��Աʹ�÷�ʽ
// 1. �����ռ� + :: + ��Ա --> �Ƽ�ʹ�����ַ�ʽ
// 2. �����Ա using + �����ռ� + :: + ��Ա�� ����ʹ�ó�Աʱ������Ҫ��������, ע�⣺��Ա��¶��ȫ�����У����ȫ��������ͬ����Ա���ᵼ��������ͻ
// 3. չ�������ռ� using + �����ռ� �� �����ռ������еĳ�Ա��¶��ȫ������
//using bite::fun3;
//using bite::a;
//using namespace bite;
void test()
{
	bite::a = 1;
	bite::print(bite::a); //bite�����ռ��µĳ�Աa
	bite::print(a); //ȫ��a
	bite::bite_69::a = 2;
	bite::c = 3;
	bite::fun2();
	bite::fun3();
	bite::fun3();
	//fun2();
	//print(a);

}


void fun4(int a)
{
	a = 10;  //�ֲ���
	bite::a = 20; //�����ռ���
	bite::bite_69::a = 30;  //�����ռ���
	::a = 40; //ȫ��������


}

void test2()
{
	int a = 10;
	int b;
	printf("%d\n", a);
	//scanf("%d", &b);
	//C++���������ͷ�ļ�<iostream> + std�����ռ�
	// ����Ҫ��ʾָ��������������ĸ�ʽ��֧���������������
	std::cout << a << "\n" << std::endl;
	//std::cin >> b >> a;
	char* p = "1234";
	//*p = '9';
	int* pa = &a;
	std::cout << pa << std::endl; //���ַ���ָ�������ַ
	std::cout << p << std::endl;  //�ַ���ָ���������
}

//ȱʡ����������������һ��Ĭ��ֵ�� ʵ��ʹ��ʱ�����û�д��Σ���Ӧ���β�ʹ��Ĭ��ֵ
//ȫȱʡ
void fun5(int a = 1, int b = 2, int c = 3)
{
	std::cout << a << b << c << std::endl;
}

//��ȱʡ: ���ֲ�����ȱʡֵ
void fun6(int a, int b = 1, int c = 2)
{
	std::cout << a << b << c << std::endl;
}
//��ȱʡ������ �����������һ��������ֵ���м䲻���м��
//void fun7(int a = 1, int b = 2, int c);
//void fun7(int a = 1, int b, int c = 2);
//ȱʡֵֻ�ܳ������������߶���ĵط�������ͬʱ����
//����
void fun8(int a, int b, int c);
//����
void fun8(int a = 100, int b = 200, int c = 300)
{
	std::cout << a << b << c << std::endl;
}

//�������أ� ��������ͬ��������ͬ�� ����ͬһ�������� C++֧�֣�C��֧��
//������ͬ�� ���ͣ� ������˳��ͬ
//�����Ƿ���ֵ��ͬ�����ܹ��ɺ�������
int Add(int a = 1, int b = 2)
{
	return a + b;
}


float Add(float a, float b)
{
	return a + b;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}

int Add(char a, int b)
{
	return a + b;
}

int Add(int a, char b)
{
	return a + b;
}
/*
void Add(int a, char b)
{
	int c = a + b;
}
*/
//extern "C" �ñ���������C���Եı��������б���
extern "C" {
	int sub(int a, int b); 
	int mul(int a, int b);
}
void test4()
{
	int a = 1;
	int b = 2;
	float c = 1.5;
	float d = 2.5;
	char f = 'a';
	int e = 3;
	Add(a, b);
	Add(c, d);
	Add(a, b, e);
	Add(a, f);
	Add(f, a);
}

//void test5()
//{
//	sub(4, 2);
//	mul(4, 2);
//}

void test6()
{
	//���ã����� + & + �������� 
	int a = 10;
	//a�ı���
	int& ra = a;
	int& ra2 = a;
	ra2 = 30;
	ra = 100;
	a = 1000;
	cout << &a << endl;
	cout << &ra << endl;
	cout << &ra2 << endl;
	//���ö���ʱ�����ʼ��
	//int& ra3;
	int b = -1;
	ra = b; //��ֵ, ���ö���֮�󣬲�����ȥ����ʵ���ָ��
	ra = -100;
}

void test7()
{
	//const����
	const int a = 10;
	const int& ra = a;
	const int& r = 10;
	double d = 2.0;
	double& rd = d;
	int c = d;
	//d��ʽ����ת��������һ����ʱ�����α�����rd2ָ���Ϊ����ʱ��������ʱ�������г���
	const int& rd2 = d;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& ra, int& rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

//������ɽ���
/*
void Swap(int ra, int rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
*/
void test8()
{
	int a = 1;
	int b = 2;
	Swap(&a, &b);
	Swap(a, b);
}

int& Add10(int& a)
{
	return ++a;
}
//����������ֵ�� ע�ⷵ�ر�������������һ��Ҫ���ں�������������
int& Add20(int a)
{
	return ++a;
}

void test9()
{
	int a = 0;
	int& b = Add10(a);
	int c = Add10(a);
	int& d = Add20(a);  //3
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

