//��������
#include <iostream>
using namespace std;

class Date {
public:
	//���캯��
	Date(int y = 1, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}

	//��������
	//�������죺���캯��һ��������ʽ��Ҳ���ڴ�������ʱ�Զ�����
	//���ó�������һ���Ѿ����ڵĶ���ȥ����һ���µĶ��󣬴������¶���͵�ǰ�����������ͬ
	//���ͱ��������ã��������������ĵݹ飬�������﷨��飬��֧�ִ�ֵ����
	//������Ĭ�����ɵĿ�������Ϊ�ֽڿ�����ǳ������ֻ��������ģ���е����ݣ���������Դ��

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//һ������ع���
	Date(const Date& d, const Date& d2) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "const Date& d" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};



class String {
public:
	String(const char* str = "luckily") {
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String() {
		if (_str) {
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


Date fun() {
	Date d;
	return d;
}

void Test() {
	Date d;
	Date d2(2020, 4, 1);
	Date& rd = d;

	Date copy1(d);

	Date copy2(Date(2020, 5, 20));//�Ż���ֱ�ӵ��ù��캯������copy2
		                          //���Ż������ù��촴����������+ ��������

	Date copy3(fun());
}

void Teststring() {
	String s("123");
	String copy(s);//��������
}