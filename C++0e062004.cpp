//IO���������
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

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
