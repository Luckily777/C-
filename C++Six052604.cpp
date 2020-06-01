//内部类
#include <iostream>
using namespace std;
enum Color
{
	BLACK,
	WHITE
};

class C
{
public:
	//内部类：在一个类内部定义一个新的类
	//内部类天然的作为外部类的友元类
	//内部类作为一个独立的类存在，不附属于外部类
	//外部类不能看作内部类的友元类，对于内部类的成员没有特殊的访问权限，需要遵循访问限定符的限制
	class D
	{
	public:
		void fun(const C& c)
		{
			//可以通过外部类对象访问外部类的私有成员
			cout << c._color << endl;
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << C::_sc << endl;
			//可以直接访问外部类的static成员
			cout << _sc << endl;

		}
	private:
		int _d;
	};
private:
	int _c;
	static int _sc;
	Color _color;
	//内部类可以在类的任何地方定义
	class E
	{
	private:
		int _e;
	};
};

