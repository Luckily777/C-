//��������
#include <string.h>
#include <iostream>
using namespace std;

class A {
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};

class Date {
public:
	//���캯��
	Date(int y = 1, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}

	//����������������Դ���������ٶ����ڶ����������ڽ���ʱ���������Զ�����
	//���û����Դ��Ҫ�������Բ�����ʽд����������ֱ��ʹ�ñ�����Ĭ�����ɵ���������

	~Date(){
		//�Զ������Զ������͵���������������Զ������ͳ�Ա����Դ������
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	//A _a;//a����ָ�������Դ�Ŀռ�
};
