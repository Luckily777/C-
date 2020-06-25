//子类的继承

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
// proteced: 类外不可见，类内部和子类的可见
protected:
	string _name = "peter"; // 姓名
private:
	int _age = 18; // 年龄
};

//继承： 类代码复用
// class/struct 类名 ： 需要继承的类
//        子类/派生类    父类/基类
class Student : public Person
//class Student : protected Person
//class Student : private Person
//classs定义的类， 默认继承方式：private
//class Student : Person
//struct定义的类： 默认继承方式：public
//struct Student : Person

{
public:
	void show()
	{
		cout << _name << "\t" << _id << endl;
		//父类private成员在子类中不可见, 但是子类确实有父类的私有成员
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
	//Print, id在父类中的访问权限为public
	p.Print();
	p._id = 3;

	Student st;
	//子类继承方式为protected/private, 从父类继承下来的所有成员的最低访问权限为protected/private
	//所以在子类外不可见
	st.Print();
	st._id = 2;
	//st._name = "123";
	//st._age = 18;
}