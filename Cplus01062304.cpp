//子类的构造函数，拷贝构造

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