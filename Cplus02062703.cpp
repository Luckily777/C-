//虚函数的大小

class D
{};

class Car
{
public:
	virtual void Drive() {}
	//包含隐含成员变量：虚函数表指针
};

void test()
{
	D d;
	Car car;
	cout << sizeof(Car) << endl;   // A: 1   B:0   C: 4    D:8
}