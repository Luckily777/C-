//2.��������
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "sub.h"
//inline�����������������ʱ���Ὣ����ָ���չ����û��ջ֡�Ŀ��������õ�����˴����Ч��
//�ܹ�����꺯����ʹ��


#define ADD(a, b)  a + b
#define MUL(a, b)  a * b

inline int Add(int a, int b)
{
	return a + b;
}

//inlineֻ��һ�����飬�������ظ���ʵ������������жϣ�����������ֱ��չ�������븺�𲻻�չ���ᰴ�պ�������
inline int fun5()
{
	int e = 0;
	for (int i = 0; i < 10000; ++i)
	{
		int a = i;
		int b = a * i;
		int c = b * i;
		int d = c * i;
		e += d;
	}
	return e;
}

void test4()
{
	int a = 1;
	int b = 2;
	int c = Add(a, b);  //���ú���������ջ֡�� ��������ִ�гɱ�
	int d = ADD(a, b);  //���滻�� int d = a + b
	int e = ADD(a + b, b);  //���滻  int e = a + b + b
	int f = MUL(a + b, b);  // a + b * b;
	int g = fun5();
	int i = sub(a, b);
}