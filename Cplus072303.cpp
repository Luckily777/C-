//����ֵ
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

void testLR()
{
	//����⣺
	//��ֵ���ȿ��Գ�����=�����ߡ����߿���ȡ��ַ��
	int a = 10;
	int b = a;
	int* p = &a;
	int* p2 = &b;

	//��ֵ��ֻ�ܳ�����=���ұߣ����߲�����ȡ��ַ
	/*10 = 20;
	int* p3 = &10;*/

	//C++�У� ��ֵ
	//����ֵ�� ������ ��ʱ����/��������
	// ����ֵ�� �������ڼ�������

	// ������ֵ�Ķ�Ϊ��ֵ

	//��ʱ����/����������������ֵ���صı����� ������Ĺ��캯�������ı���
	/*getA(a) = b;
	int* p4 = &(getA());*/
}

class D
{

public:
	D(int d)
		:_d(d)
	{
		cout << "D(int)" << endl;
	}
	D(const D& d)
	{
		cout << "D(const D&)" << endl;
	}

private:
	int _d;
};

D getD(D d)
{
	return d;
}

void func3(const D& d)
{

}
void testRef()
{
	int a = 10;
	//��ֵ���ã����õ�ʵ��ȿ���Ϊ��ֵ��Ҳ����Ϊ��ֵ

	//ra �� ʵ��Ϊ��ֵ
	int& ra = a;

	// : riʵ��Ϊ��ֵ
	const int& ri = 10;

	//��ֵ���ã����õ�ʵ��ֻ������ֵ

	//��ֵ���ã� ʵ��Ϊ����
	int&& lr = 10;
	//��ֵ���ã� ʵ��Ϊ��ʱ����
	int&& lr2 = getA(a);

	const int& r3 = getA(a);

	//��ֵ���ã� ����������ֵ
	//int&& r4 = a;
}


class String
{
public:
	String(char* str = "")
		:_str(new char[strlen(str) + 1])
		, _size(strlen(str))
		, _capacity(strlen(str))
	{
		strcpy(_str, str);
		cout << "String(char*)" << endl;
	}

	String(const String& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
		_size = _capacity = strlen(str._str);
		cout << "String(const String&)" << endl;
	}
	//�ƶ����죺 ��߿���Ч��
	String(String&& str)
		:_str(str._str)
	{
		str._str = nullptr;
		_size = _capacity = str._size;
		cout << "String(String&&)" << endl;
	}

	String& operator=(const String& str)
	{
		if (this != &str)
		{
			delete[] _str;
			_str = new char[strlen(str._str) + 1];
			strcpy(_str, str._str);
			_size = _capacity = strlen(str._str);
			cout << "String& operator=(const String&)" << endl;
		}
		return *this;
	}

	//�ƶ���ֵ
	String& operator=(String&& str)
	{
		if (this != &str)
		{
			swap(_str, str._str);
			_size = _capacity = str._size;
			cout << "String operator=(String&&)" << endl;
		}

		return *this;
	}

	~String()
	{
		cout << "��������" << endl;
		if (_str)
		{

			delete[] _str;
			cout << "~String()" << endl;
		}

	}

private:
	char* _str;
	int _size;
	int _capacity;
};

String getString()
{
	String str("123");
	return str;
}

void testString()
{
	////ǳ������ �ƶ����죬 ֱ�ӻ�ȡ����ֵ����ֵ������Դ
	//String ret = getString();

	////����� �������죬 retΪ��ֵ
	//String copy(ret);

	//String ret2 = String("456");  // ���� + �������� �� �Ż��� ����


	String ret;

	ret = String("789");

	int a = 10;
}

int main()
{
	//test();
	//testAuto();
	//testDelete();
	//testRef();
	testString();
	return 0;
}