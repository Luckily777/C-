//thisָ��
#include <iostream>
using namespace std;
class Data {
public:
	//void Dispaly(Date* const this)ʼ��ָ��ǰ���ô˺����Ķ���ָ�򲻻ᷢ������
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
	int _year; // ��
	int _month; // ��
	int _day; // ��
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
	//this�ڲ��������õĳ����¿���Ϊ��
	//pd1->Display();  thisָ��գ��������쳣
	pd1->fun1(); //thisָ��Ϊ�գ�����thisû�н��н����ã���������ִ��
	(*pd1).fun1();  //fun1(&(*pd1))
	//fun1(pd1)
	//pd1->_day = 1;

	return 0;
}