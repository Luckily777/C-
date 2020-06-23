#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
T Add(T& a, T& b)
{
	return a + b;
}

template <>
char* Add<char*>(char*& a, char*& b)
{
	strcat(a, b);
	return a;
}

//���ں���ģ�岻�ܴ�����������ͣ�һ��ᶨ��һ�������͵���ͨ����
//����ģ����ػ��Ƚ�����
char* Add(char*& a, char*& b)
{
	strcat(a, b);
	return a;
}

template <class T1, class T2>
T1 sub(T1& a, T2& b)
{
	cout << "sub(T1, T2)" << endl;
	return a;
}

void test()
{
	int a = 1, b = 2;
	float c = 1.5, d = 2.5;
	char e = 'a', f = 'b';
	char* ptr = new char[100];
	strcpy(ptr, "123");
	char* ptr2 = new char[100];
	strcpy(ptr2, "abc");

	Add(a, b);
	Add(c, d);
	Add(e, f);
	Add(ptr, ptr2);

	int* pa = &a;
	int* pb = &b;

}

//ģ�����������ģ�����(class, typename)�� ������ģ�����(��ֵ���ͣ�
//������ģ������� ������Ϊ����ʹ�ã� ����ֵ��Ҫ�ڱ���ʱȷ��
template <class T, size_t N>
class Array
{
private:
	T _array[N];
};

void test2()
{
	Array<int, 20> array;
}

//��ģ����ػ�
// 1. ȫ�ػ�--> ���еĲ�����Ϊ��������

//�ػ�֮ǰ��Ҫ���ڻ�����ģ��
template <class T1, class T2>
class A
{
public:
	A()
	{
		cout << "A(T1, T2)" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

//ȫ�ػ�
template <>
class A<int, char>
{
public:
	A()
	{
		cout << "A(int, char)" << endl;
	}
private:
	int _t1;
	char _t2;
};



//2.ƫ�ػ��� a. �����ػ���  b. ��ģ���������һ��������
template <class T1>
class A<T1, double>
{
public:
	A()
	{
		cout << "A(T1, double)" << endl;
	}
private:
	T1 _t1;
	double _t2;
};

template <class T1>
class A<T1, char>
{
public:
	A()
	{
		cout << "A(T1, char)" << endl;
	}
private:
	T1 _t1;
	double _t2;
};

template <class T1, class T2>
class A<T1&, T2&>
{
public:
	A()
	{
		cout << "A(T1&, T2&>" << endl;
	}
};

void test3()
{
	A<int, int>  a;
	A<int, char> b;
	A<float, char> f;
	A<int, double> c;
	A<int&, int&> d;
	A<int&, double&> e;
}

#include "template.h"
void test4()
{
	int a = 1, b = 1;
	double c = 2.1, d = 1.8;
	isEqual(a, b);  //isEqual<int>  ?
	isEqual(c, d);  //isEqual<double> ?
}

void test5()
{
	//C++���ԣ����ڲ�ͬ���͵����ݣ�����������ò�ͬ�����غ���
	// ����ostream����ĳ�Ա����operator <<
	cout << "abc" << 1 << 2.0 << endl;
	//����ostream����ĳ�Ա����operator<<
	cout.operator<<("abc").operator<<(1).operator<<(2.0).operator<<(endl);
	//������ͨ���� operator<<(ostream&, char*)
	operator<<(cout, "abc");
	cout << "abc" << 1 << 2.0 << endl;
	clog << "abc" << 1 << 2.0 << endl;


	int a;
	//����istream����ĳ�Ա���� operator>>
	cin >> a;
	cin.operator>>(a);

	//C���ԣ����ڲ�ͬ���͵����ݣ������������ͬһ������
	printf("%d\n", a);
	scanf("%d", &a);
}

void test6()
{
	//�����ļ�������
	ifstream fin("test.txt");
	if (!fin.is_open())
		cout << "�ļ���ʧ��" << endl;
	//�ı����� getline, >>
	char str[100];
	//>>: �����ո���߻��У���������
	/*fin >> str;
	cout << str << endl;
	fin >> str;
	cout << str << endl;*/
	//getline: Ĭ���������н������߶�������ֽڽ���
	char str2[4];
	fin.getline(str2, 3);
	cout << str2 << endl;

}

struct Student
{
	int _age;
	char _name[30];
};

void test7()
{
	//�ı���д
	ofstream fout("new.test.txt");
	if (!fout.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//<<
	fout << "123" << "456" << endl;
	fout << "abcd";
	fout.close();

	ifstream fin("new.test.txt");
	if (!fin.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	char str[100];
	fin >> str;
	cout << str << endl;
	fin >> str;
	cout << str << endl;
	fin.close();

}

//�����ƶ�д�� Ч�ʸߣ� �ɶ��Բ�
void writeFile(const char* filename)
{
	ofstream fout(filename);
	if (!fout.is_open())
		return;
	Student st;
	st._age = 20;
	strcpy(st._name, "bitekeji");

	//������д
	fout.write((char*)&st, sizeof(Student));
	fout.close();
}

void readFile(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
		return;
	Student st;
	fin.read((char*)&st, sizeof(Student));
	fin.close();
}

//�ı���д�� Ч�ʵͣ� �ɶ��Ժ�
void writeTxtFile(const char* filename)
{
	ofstream fout(filename);
	if (!fout.is_open())
		return;
	Student st;
	st._age = 20;
	strcpy(st._name, "bitekeji");
	fout << st._age << endl;
	fout << st._name << endl;
	fout.close();
}

void readTxtFile(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
		return;
	Student st;
	fin >> st._age;
	fin >> st._name;
	fin.close();
}

void test8()
{
	writeFile("test.binary.txt");
	readFile("test.binary.txt");

	writeTxtFile("test.text.txt");
	readTxtFile("test.text.txt");
}

void test9()
{
	//����ʾ��

	writeFile("test.binary.txt");
	readTxtFile("test.binary.txt");

	writeTxtFile("test.text.txt");
	readFile("test.text.txt");
}

void test10()
{
	//atoi

	//itoa: ����ת�ַ���
	char str[100];
	itoa(100, str, 10);
	itoa(100, str, 16);
	itoa(100, str, 2);
	itoa(100, str, 8);

	sprintf(str, "%d", 100);
	float f = 1.2;
	sprintf(str, "%0.1f", f);

	//�ѷ��ַ�������ת���ַ�����ʽ������
	stringstream ss;
	ss << f;
	string ret = ss.str();
	cout << ret << endl;
	int a = 120;
	ss.str("");  //Set
	ss.clear();  //clear: ������е�״̬λ
	ss << "123\n";
	ss << a;
	ret = ss.str();  //Get
	ss >> ret;
	cout << ret << endl;

}

int main()
{
	//test();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	test10();
	return 0;
}