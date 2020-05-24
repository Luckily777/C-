#include <iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};
//class Date
//{
//public:
//	Date(int y = 1, int m = 1, int d = 1)
//	{
//		_year = y;
//		_month = m;
//		_day = d;
//	}
//	//�������죺 ���캯��һ��������ʽ��Ҳ���ڴ�������ʱ�Զ�����
//	//���ó����� ��һ���Ѿ����ڵĶ���ȥ����һ���µĶ��� �������¶���͵�ǰ�����������ͬ
//	//���ͱ��������ã��������������ݹ飬�������﷨��飬��֧�ִ�ֵ����
//	//������Ĭ�����ɵĿ�������Ϊ�ֽڿ�����ǳ����(ֻ��������ģ���е����ݣ���������Դ)
//	
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "const Date& d" << endl;
//	}
//	
//	//һ������ع���
//	Date(const Date& d, const Date& d2)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d2._day;
//		cout << "const Date& d" << endl;
//	}
//	//���������� ������Դ���������ٶ����ڶ����������ڽ���ʱ���������Զ�����
//	//���û����Դ��Ҫ�������Բ�����ʽд����������ֱ��ʹ�ñ�����Ĭ�����ɵ���������
//
//	~Date()
//	{
//		//�Զ������Զ������͵���������������Զ������ͳ�Ա����Դ������
//		cout << "~Date()" << endl;
//	}
//	
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	//A _a;
//};

//class String
//{
//public:
//	String(const char* str = "bite")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	//�������Դ��������ʽ���忽�����죬������
//
//	~String()
//	{
//		if (_str)
//		{
//			free(_str);
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//Date fun()
//{
//	Date d;
//	return d;
//}
//
//void test1()
//{
//	Date d;
//	Date d2(2020, 4, 1);
//	Date& rd = d;
//
//	Date copy(d);
//
//	Date copy2(Date(2020, 5, 20));  //�Ż��� ֱ�ӵ��ù��캯������copy2, ���Ż������ù��촴����������+ ��������
//	
//	Date copy3(fun());
//}
//
//void test2()
//{
//	const volatile int a = 10;
//	int* pa = (int*)&a;
//	*pa = 20;
//	cout << a << endl;
//	cout << *pa << endl;
//}
//
//void test3()
//{
//	String s("123");
//	String copy(s);  //��������
//
//}

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}
	
	bool isEqual(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	//��������غ�������ǿ����Ŀɶ���
	//���������⣬�����ʹ�÷�ʽ����ͨ����һ��
	//����ֵ operator + ��Ҫ���ص������ (�����б�) {}
	///��������غ�������ǳ�Ա������������ĸ������������Ҫ�ĸ�����һ��������������ᴫ��thisָ����Ϊ��һ������
	// thisָ��ʼ��ռ��������������ĵ�һ��λ��
	bool operator==(const Date& d) //�ײ�ӿڣ� bool operator==(Date* const this, const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	// ��ֵ��d = d2
	// ��ֵ��������غ���: �޸��Ѿ����ڵĶ�������ݣ� ����ȥ�����µĶ���
	// �����д��������Ҳ��Ĭ�����ɣ�Ĭ�����ɵ�Ҳ���ֽڿ�������ǳ����
	// �����ǰ��������Դ���������ʽ���帳ֵ��������غ�����������
	Date& operator=(const Date& d2)
	{
		//�ж��Ƿ���Լ���ֵ
		if (this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		
		cout << "operator=(const Date& d2)" << endl;
		//���ص�ǰ���ô˺����Ķ�����
		return *this;
	}
	
//private:
	int _year;
	int _month;
	int _day;
};

//��ͨ����������غ����������ĸ������������Ҫ�ĸ���һ��
//bool operator==(const Date& d1, const Date& d)
//{
//	return d1._year == d._year
//		&& d1._month == d._month
//		&& d1._day == d._day;
//}
//�����������غ���
//ostream& operator<<(ostream& _cout, const Date& date)
//{
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}



void test4()
{
	Date d(2020, 1, 1);
	Date d2(d);

	Date d3(2020, 5, 23);
	cout << d.isEqual(d2) << endl;
	cout << d.isEqual(d3) << endl;
	cout << (d == d2) << endl;  //�ȼ��� d.operator==(d2);
	cout << d.operator==(d2) << endl;
	cout << (d == d3) << endl;  //�ȼ��� d.operator==(d3);
	cout << d.operator==(d3) << endl;
	//cout << d << endl;
}

void test5()
{
	Date d(2020, 5, 22);
	Date d2(2019, 1, 1);
	// =���ã�������󶼴��ڣ����ø�ֵ��������غ����� �����߶��󲻴��ڣ����ÿ�������
	d2 = d; //��ֵ��������غ���
	d2.operator=(d);//ͬ�ϵȼ�
	d2 = d2;
	Date d3(2018, 10, 1);
	//������ֵ����������ֵ
	d = d2 = d3;
	d.operator=(d2.operator=(d3));  //ͬ�ϵȼ�
	Date d4 = d3;  //���ÿ������죺d4�����ڣ���d3����d4�������Ե��ù��죬���Ǹ�ֵ�����
}
//int main()
//{
//	//test1();
//	////test2();
//	//test3();
//	//test4();
//	test5();
//	return 0;
//}