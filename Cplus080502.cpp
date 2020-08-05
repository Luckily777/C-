//禁止拷贝和不能继承的类


#include <mutex>
#include <thread>
#include <iostream>
using namespace std;


//禁止拷贝的类
// 拷贝构造和赋值运算符声明为delete函数， 或者声明为私有的，且不实现
class NoCopy
{
public:
	NoCopy() {};
private:
	/*NoCopy(const NoCopy& nc);
	NoCopy& operator=(const NoCopy& nc);*/

	NoCopy(const NoCopy& nc) = delete;
	NoCopy& operator=(const NoCopy& nc) = delete;
};

//不能被继承的类
//1. 父类的构造声明为私有的

class NoH
{
private:
	NoH() {};
};

//或者父类定义为final类
class NoH2 final
{};

//class sub : public NoH
class sub /*: public NoH2*/
{
};


void testNoH()
{
	sub b;
}