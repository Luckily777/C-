//�麯���Ĵ�С

class D
{};

class Car
{
public:
	virtual void Drive() {}
	//����������Ա�������麯����ָ��
};

void test()
{
	D d;
	Car car;
	cout << sizeof(Car) << endl;   // A: 1   B:0   C: 4    D:8
}