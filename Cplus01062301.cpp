//����ļ̳�

#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
public:
	int _id = 1;
// proteced: ���ⲻ�ɼ������ڲ�������Ŀɼ�
protected:
	string _name = "peter"; // ����
private:
	int _age = 18; // ����
};

//�̳У� ����븴��
// class/struct ���� �� ��Ҫ�̳е���
//        ����/������    ����/����
class Student : public Person
//class Student : protected Person
//class Student : private Person
//classs������࣬ Ĭ�ϼ̳з�ʽ��private
//class Student : Person
//struct������ࣺ Ĭ�ϼ̳з�ʽ��public
//struct Student : Person

{
public:
	void show()
	{
		cout << _name << "\t" << _id << endl;
		//����private��Ա�������в��ɼ�, ��������ȷʵ�и����˽�г�Ա
		//cout << _age << endl;
	}
//protected:
public:
	int _num = 2020;
};

class Empty
{};

void test()
{
	cout << sizeof(Person) << endl;
	cout << sizeof(Student) << endl;
	cout << sizeof(Empty) << endl;

	Person p;
	//Print, id�ڸ����еķ���Ȩ��Ϊpublic
	p.Print();
	p._id = 3;

	Student st;
	//����̳з�ʽΪprotected/private, �Ӹ���̳����������г�Ա����ͷ���Ȩ��Ϊprotected/private
	//�����������ⲻ�ɼ�
	st.Print();
	st._id = 2;
	//st._name = "123";
	//st._age = 18;
}