//������� 
//һ��������ǲ��ܹ����з������ģ�ֻ���������һ�����ڶ���ͳ�ʼ������һ��
//��һ�����ڶ����ʱ�����ʹ��
template <class T>
bool isEqual(const T& a, const T& b)
{
	return a == b;
}


#include "template.h"

template <class T>
bool isEqual(const T& a, const T& b)
{
	return a == b;
}

void t()
{
	double f = 2.1, e = 1.2;
	isEqual(f, e);
	isEqual(1, 2);
}



#include "template.h"
void test4()
{
	int a = 1, b = 1;
	double c = 2.1, d = 1.8;
	isEqual(a, b);  //isEqual<int>  ?
	isEqual(c, d);  //isEqual<double> ?
}
