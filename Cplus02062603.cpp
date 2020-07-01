//同名隐藏

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	void showId(int a)
	{
		cout << _id << endl;
	}
public:
	int _id = 1;
protected:
	string _name = "peter"; // 姓名

	int _age = 18; // 年龄
};

void showId(int a)
{
	cout << "全局函数： void showId()" << endl;
}

//全局变量_id
int _id = 10;

//父类，子类的作用域都是独立的，不同的作用域中可以有同名的成员
class Student : public Person
{
public:
	void setNum(int num)
	{
		this->_num = num;
	}
	void showId()
	{
		//同名隐藏： 父类中的同名成员被子类中的同名成员隐藏
		cout << _id << endl;
		cout << Person::_id << endl;
		//只要函数名，就会构成同名隐藏，不是函数重载
		//showId(10);
		/*Person::showId(10);*/
		//全局函数
		//::showId(10);
		//showId();
	}

	//子类本身的showId() 和 showId(int) 构成函数重载
	/*void showId(int a)
	{}*/

	void setId(int id)
	{
		//成员ID赋值
		_id = id;
		//全局ID赋值
		//::_id = id;
	}
public:
	int _id = 100;
	int _num = 2020;
};

void test()
{
	Student st;
	//cout << st._num << endl;
	//st.setNum(1999);
	//cout << st._num << endl;  // A 随机值  B 2020   C 1999  D 2021
	cout << sizeof(Person) << endl;  // 36
	cout << sizeof(Student) << endl;  //  A 40   B  44  C  36  D 48
	st.showId();

	cout << "全局ID: " << _id << endl;
	st.setId(89);
	cout << "全局ID: " << _id << endl;
	cout << "成员ID: " << endl;
	st.showId();
}
