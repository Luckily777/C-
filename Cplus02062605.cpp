//菱形继承 数据冗余 二义性
class Person
{
public:
	string _name; // 姓名
};

class Student : virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
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