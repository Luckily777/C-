//���μ̳� �������� ������
class Person
{
public:
	string _name; // ����
};

class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};

void test()
{
	Assistant ass;
	ass._name = "1";
	cout << sizeof(ass) << endl;
	ass.Student::_name = "1";
	ass.Teacher::_name = "2";

}

class A
{
public:
	int _a;
};

class B :virtual public A
{
public:
	int _b;
};

class C :virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

void test()
{
	D d;
	d.B::_a = 1;
	d._b = 2;
	d.C::_a = 3;
	d._c = 4;
	d._d = 5;
}