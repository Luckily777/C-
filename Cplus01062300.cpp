#include <iostream>
#include <string>
using namespace std;


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	int _id = 1;
//// proteced: ���ⲻ�ɼ������ڲ�������Ŀɼ�
//protected:
//	string _name = "peter"; // ����
//private:
//	int _age = 18; // ����
//};
//
////�̳У� ����븴��
//// class/struct ���� �� ��Ҫ�̳е���
////        ����/������    ����/����
//class Student : public Person
////class Student : protected Person
////class Student : private Person
////classs������࣬ Ĭ�ϼ̳з�ʽ��private
////class Student : Person
////struct������ࣺ Ĭ�ϼ̳з�ʽ��public
////struct Student : Person
//
//{
//public:
//	void show()
//	{
//		cout << _name << "\t" << _id << endl;
//		//����private��Ա�������в��ɼ�, ��������ȷʵ�и����˽�г�Ա
//		//cout << _age << endl;
//	}
////protected:
//public:
//	int _num = 2020;
//};

//class Empty
//{};
//
//void test()
//{
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//
//	Person p;
//	//Print, id�ڸ����еķ���Ȩ��Ϊpublic
//	p.Print();
//	p._id = 3;
//
//	Student st;
//	//����̳з�ʽΪprotected/private, �Ӹ���̳����������г�Ա����ͷ���Ȩ��Ϊprotected/private
//	//�����������ⲻ�ɼ�
//	st.Print();
//	st._id = 2;
//	//st._name = "123";
//	//st._age = 18;
//}
//
//void test2()
//{
//	Person p;
//	Student st;
//
//	//��Ƭ���������ָ�룬���ÿ���ֱ�Ӹ�ֵ���������ָ�룬���ã� �˴�������ʽ����ת��
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	//��������ܸ�ֵ���������
//	//st = (Student) p;
//	//����ָ�룬���ò���ֱ�Ӹ�ֵ������ָ�룬���á�����ͨ��ǿ������ת�������и�ֵ
//	//����ǿ������ת������ȫ,���ܻᵼ�·���Խ��
//	//һ�㲻����ǿ������ת�������ǲ��ö�̬ת�� dynamic_cast
//	Student& rp = (Student&) p;
//	Student* ptrp = (Student*) &p;
//	cout << rp._num << endl;
//	cout << ptrp->_num << endl;
//
//	Student& rs2 = (Student&) rs;
//	cout << rs2._num << endl;
//	Student* ptrs2 = (Student*) ptrs;
//	cout << ptrs2->_num << endl;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	void showId(int a)
//	{
//		cout << _id << endl;
//	}
//public:
//	int _id = 1;
//protected:
//	string _name = "peter"; // ����
//
//	int _age = 18; // ����
//};
//
//void showId(int a)
//{
//	cout << "ȫ�ֺ����� void showId()" << endl;
//}
//
////ȫ�ֱ���_id
//int _id = 10;
//
////���࣬������������Ƕ����ģ���ͬ���������п�����ͬ���ĳ�Ա
//class Student : public Person
//{
//public:
//	void setNum(int num)
//	{
//		this->_num = num;
//	}
//	void showId()
//	{
//		//ͬ�����أ� �����е�ͬ����Ա�������е�ͬ����Ա����
//		cout << _id << endl;
//		cout << Person::_id << endl;
//		//ֻҪ���������ͻṹ��ͬ�����أ����Ǻ�������
//		//showId(10);
//		/*Person::showId(10);*/
//		//ȫ�ֺ���
//		//::showId(10);
//		//showId();
//	}
//
//	//���౾���showId() �� showId(int) ���ɺ�������
//	/*void showId(int a)
//	{}*/
//
//	void setId(int id)
//	{
//		//��ԱID��ֵ
//		_id = id;
//		//ȫ��ID��ֵ
//		//::_id = id;
//	}
//public:
//	int _id = 100;
//	int _num = 2020;
//};
//
//void test()
//{
//	Student st;
//	//cout << st._num << endl;
//	//st.setNum(1999);
//	//cout << st._num << endl;  // A ���ֵ  B 2020   C 1999  D 2021
//	cout << sizeof(Person) << endl;  // 36
//	cout << sizeof(Student) << endl;  //  A 40   B  44  C  36  D 48
//	st.showId();
//
//	cout << "ȫ��ID: " << _id << endl;
//	st.setId(89);
//	cout << "ȫ��ID: " << _id << endl;
//	cout << "��ԱID: " << endl;
//	st.showId();
//}

class Person
{
public:
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int, int)" << endl;
	}
	Person(int id, int age, int num)
	{
		cout << "Person(int ,int, int)" << endl;
	}

	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{
		cout << "Person(const Person&)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_id = p._id;
			_age = p._age;
		}
		cout << "Person& operator=(const Person&)" << endl;
		return *this;
	}
protected:
	int _id;

	int _age; // ����
};

class Student : public Person
{
	//�������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
public:
	//�������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
	//��ʽ����Ĺ��캯��Ҳ�Զ����ø����Ĭ�Ϲ��죬�ڳ�ʼ���б��е��ø��๹��
	//�����Ա�����ø��๹�캯����ɳ�ʼ��
	Student(int id = 100, int age = 25)
		:_num(id)
		, Person(id, age)
	{
		cout << "Student(int, int)" << endl;
	}

	//�������Զ����ɵĿ��������Զ����ø���Ŀ�������
	//��ʽ����Ŀ������죬�Զ����ø����Ĭ�Ϲ��죬���Ǹ���Ŀ�������
	//���ø��࿽�������ǣ�����Ƭ�Ĳ���
	Student(const Student& st)
		:Person(st)
		, _num(st._num)
	{
		cout << "Student (const Student&)" << endl;
	}

	//�������Զ����ɵĸ�ֵ����������Զ����ø���ĸ�ֵ���������
	//���ำֵ������͸��ำֵ���������ͬ������
	Student& operator=(const Student& st)
	{
		if (this != &st)
		{
			Person::operator=(st);
			/*_id = st._id;
			_age = st._age;*/
			_num = st._num;
		}
		cout << "Student& operator=(const Student&)" << endl;
		return *this;
	}

private:
	int _num;
};

void test()
{
	Student st;
}

void test2()
{
	Student st;
	Student copy(st);  // �ȼ��ڣ� Student copy = st;
}

void test3()
{
	Student st;
	Student st2(1, 1);
	cout << "��ֵ��" << endl;
	st2 = st;
}

int main()
{
	//test();
	//test2();
	test3();
	return 0;
}