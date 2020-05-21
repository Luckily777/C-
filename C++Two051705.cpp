//C++struct: 可以定义数据和函数
//C++定义类的方式：
// 1. struct + 类名 + {} + ";"
// 2. class + 类名 + {} + ";"
#include <stdio.h>
#include <iostream>
#include <string.h>
struct Student
{
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}

	int _number;
	int _id;
	char name[10];
	char gender[10];
	char major[10];
};
//C++的封装的语法体现： 类， 访问限定符
//访问权限：public, protected, private
//只限制成员在类外的访问权限，类内部不受访问限定符的限制
class Student2
{
public: //公有的成员在类外可见
	//成员函数
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}
private:  //私有的成员在类外不可见
	//成员变量， 属性
	int _number;
	int _id;
protected:  // 保护的成员在类外不可见
	char name[10];
	char gender[10];
	char major[10];
};

void test10()
{
	Student st;
	strcpy(st.name, "123");
	st.setId(20);

	Student2 st2;
	st2.display();
	st2._id = 10;
}

