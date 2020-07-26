//final override及default
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

//定义一个不能被继承的类型
class B final
{

};

class C
{
public:
	//default: 让编译器显式生成一个默认函数
	C() = default;
	//C(){}
	//delete: 把一个函数声明成已删除函数，不能再被使用
	// 拷贝构造声明为delete: 防拷贝
	C(const C& c) = delete;
	C& operator=(const C& c) = delete;
private:
	int _c;
};

//C::C(const C& c)
//:_c(c._c)
//{
//	cout << "C(const C&)" << endl;
//}

void testDelete()
{
	C c;
	//C copy(c);
}

int getA(int a)
{
	return a;
}
