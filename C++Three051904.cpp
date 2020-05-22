//this指针
#include <iostream>
using namespace std;
class Data {
public:
	//void Dispaly(Date* const this)始终指向当前调用此函数的对象，指向不会发生变量
	void Display()  
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		//this = nullptr;
		this->_year = 2022;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void fun1()
	{
		cout << "Date::fun1()" << endl;
	}
//private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};

int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();

	Date* pd1 = &d1;
	pd1->Display();
	pd1 = nullptr;
	//this在不做解引用的场景下可以为空
	//pd1->Display();  this指针空，解引用异常
	pd1->fun1(); //this指针为空，但是this没有进行解引用，程序正常执行
	(*pd1).fun1();  //fun1(&(*pd1))
	//fun1(pd1)
	//pd1->_day = 1;

	return 0;
}