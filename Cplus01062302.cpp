//��Ƭ����

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


class Student : public Person

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


void test2()
{
	Person p;
	Student st;

	//��Ƭ���������ָ�룬���ÿ���ֱ�Ӹ�ֵ���������ָ�룬���ã� �˴�������ʽ����ת��
	p = st;
	Person& rs = st;
	Person* ptrs = &st;

	//��������ܸ�ֵ���������
	//st = (Student) p;
	//����ָ�룬���ò���ֱ�Ӹ�ֵ������ָ�룬���á�����ͨ��ǿ������ת�������и�ֵ
	//����ǿ������ת������ȫ,���ܻᵼ�·���Խ��
	//һ�㲻����ǿ������ת�������ǲ��ö�̬ת�� dynamic_cast
	Student& rp = (Student&) p;
	Student* ptrp = (Student*) &p;
	cout << rp._num << endl;
	cout << ptrp->_num << endl;

	Student& rs2 = (Student&) rs;
	cout << rs2._num << endl;
	Student* ptrs2 = (Student*) ptrs;
	cout << ptrs2->_num << endl;
}