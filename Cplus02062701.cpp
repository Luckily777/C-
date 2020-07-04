//多态的两个接口

#include <iostream>
using namespace std;

class Car
{
public:
	//final定义的函数不能被重写， 体现实现继承
	/*virtual void Drive() final {}*/
	virtual void Drive() {}
};
class Benz :public Car
{
public:
	//override: 强制子类重写父类的某一个虚函数， 体现接口继承
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
	virtual void Drive(int a = 10){ cout << "Benz-舒适-(int)" << endl; }
};


void test()
{
	Car* ptr = new Benz;
	ptr->Drive();
}