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
//// proteced: 类外不可见，类内部和子类的可见
//protected:
//	string _name = "peter"; // 姓名
//private:
//	int _age = 18; // 年龄
//};
//
////继承： 类代码复用
//// class/struct 类名 ： 需要继承的类
////        子类/派生类    父类/基类
//class Student : public Person
////class Student : protected Person
////class Student : private Person
////classs定义的类， 默认继承方式：private
////class Student : Person
////struct定义的类： 默认继承方式：public
////struct Student : Person
//
//{
//public:
//	void show()
//	{
//		cout << _name << "\t" << _id << endl;
//		//父类private成员在子类中不可见, 但是子类确实有父类的私有成员
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
//	//Print, id在父类中的访问权限为public
//	p.Print();
//	p._id = 3;
//
//	Student st;
//	//子类继承方式为protected/private, 从父类继承下来的所有成员的最低访问权限为protected/private
//	//所以在子类外不可见
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
//	//切片：子类对象，指针，引用可以直接赋值给父类对象，指针，引用， 此处不是隐式类型转换
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	//父类对象不能赋值给子类对象
//	//st = (Student) p;
//	//父类指针，引用不能直接赋值给子类指针，引用。可以通过强制类型转换，进行赋值
//	//但是强制类型转换不安全,可能会导致访问越界
//	//一般不进行强制类型转换，而是采用动态转换 dynamic_cast
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
//	string _name = "peter"; // 姓名
//
//	int _age = 18; // 年龄
//};
//
//void showId(int a)
//{
//	cout << "全局函数： void showId()" << endl;
//}
//
////全局变量_id
//int _id = 10;
//
////父类，子类的作用域都是独立的，不同的作用域中可以有同名的成员
//class Student : public Person
//{
//public:
//	void setNum(int num)
//	{
//		this->_num = num;
//	}
//	void showId()
//	{
//		//同名隐藏： 父类中的同名成员被子类中的同名成员隐藏
//		cout << _id << endl;
//		cout << Person::_id << endl;
//		//只要函数名，就会构成同名隐藏，不是函数重载
//		//showId(10);
//		/*Person::showId(10);*/
//		//全局函数
//		//::showId(10);
//		//showId();
//	}
//
//	//子类本身的showId() 和 showId(int) 构成函数重载
//	/*void showId(int a)
//	{}*/
//
//	void setId(int id)
//	{
//		//成员ID赋值
//		_id = id;
//		//全局ID赋值
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
//	//cout << st._num << endl;  // A 随机值  B 2020   C 1999  D 2021
//	cout << sizeof(Person) << endl;  // 36
//	cout << sizeof(Student) << endl;  //  A 40   B  44  C  36  D 48
//	st.showId();
//
//	cout << "全局ID: " << _id << endl;
//	st.setId(89);
//	cout << "全局ID: " << _id << endl;
//	cout << "成员ID: " << endl;
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

	int _age; // 年龄
};

class Student : public Person
{
	//编译器自动生成的默认构造自动调用父类的默认构造
public:
	//编译器自动生成的默认构造自动调用父类的默认构造
	//显式定义的构造函数也自动调用父类的默认构造，在初始化列表中调用父类构造
	//父类成员必须用父类构造函数完成初始化
	Student(int id = 100, int age = 25)
		:_num(id)
		, Person(id, age)
	{
		cout << "Student(int, int)" << endl;
	}

	//编译器自动生成的拷贝构造自动调用父类的拷贝构造
	//显式定义的拷贝构造，自动调用父类的默认构造，不是父类的拷贝构造
	//调用父类拷贝构造是，有切片的操作
	Student(const Student& st)
		:Person(st)
		, _num(st._num)
	{
		cout << "Student (const Student&)" << endl;
	}

	//编译器自动生成的赋值运算符函数自动调用父类的赋值运算符函数
	//子类赋值运算符和父类赋值运算符构成同名隐藏
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
	Student copy(st);  // 等价于： Student copy = st;
}

void test3()
{
	Student st;
	Student st2(1, 1);
	cout << "赋值：" << endl;
	st2 = st;
}

int main()
{
	//test();
	//test2();
	test3();
	return 0;
}