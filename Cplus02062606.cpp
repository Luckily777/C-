//��̬
#include <iostream>
using namespace std;

��̬��
1. �̳�
2. �麯���� ��������麯������д
3. �����麯�������ͱ�����ָ�� / ����, һ�㶼���ø���ָ�� / ����ָ�����Լ�����ʵ�壬 ����Ϊ��Ƭ��Ϊ
����ͬʱ��������������ȱһ����

class A
{};

class B : public A
{

};
class Person {
public:
	Person()
	{
		cout << "����Person�������Դ" << endl;
	}
	virtual void BuyTicket() {
		cout << "��Ʊ-ȫ��" << endl;

	}

	virtual ~Person()
	{
		cout << "����Person������Դ" << endl;
		//cout << "~Person()" << endl;
	}
	/*virtual A& BuyTicket() {
		cout << "��Ʊ-ȫ��" << endl;
		return A();
	}*/
};
class Student : public Person {
public:
	Student()
	{
		cout << "����Student�����¼ӵ���Դ" << endl;
	}

	//�麯������д����д�����߼�
	//�����麯������д���������ຬ�к͸���ӿ���ȫ��ͬ�ĺ���--> ����ֵ�� ������, ������ȫ��ͬ(���⣺Э�䣬����������д�� 
	virtual void BuyTicket(int a = 10) {
		cout << "��Ʊ-���" << endl;

	}
	//Э�䣺 ����ֵ���Ϳ��Բ�ͬ�����Ƿ���ֵ���ͱ����Ǹ��ӹ�ϵ��ָ��/����
	/*virtual B& BuyTicket() {
		cout << "��Ʊ-���" << endl;
		return B();
		}*/

		//�������������͸������������ײ�ͬ��������ֻҪ�����������麯�����������������¸�������
	~Student()
	{
		cout << "����Student�����¼ӵ���Դ" << endl;
		//cout << "~Student()" << endl;
	}
};

void func(Person& p)
{
	p.BuyTicket();
}

void func2(Person* p)
{
	p->BuyTicket();
}


void test()
{
	Person p;
	Student s;

	func(p);
	func(s);

	func2(&p);
	func2(&s);
}

void test()
{
	/*Person p;
	Student s;*/

	/*Person* ptr = new Person;
	Student* ptr2 = new Student;

	delete ptr2;
	delete ptr;*/

	//�Ƕ�̬��������
	//��̬�� ��ʵ��ָ���ʵ��

	Person* ptr = new Person;
	Person* ptr2 = new Student;

	delete ptr2;
	delete ptr;

}

int main()
{
	test();
	return 0;
}