//��̬�������ӿ�

#include <iostream>
using namespace std;

class Car
{
public:
	//final����ĺ������ܱ���д�� ����ʵ�ּ̳�
	/*virtual void Drive() final {}*/
	virtual void Drive() {}
};
class Benz :public Car
{
public:
	//override: ǿ��������д�����ĳһ���麯���� ���ֽӿڼ̳�
	virtual void Drive() override { cout << "Benz-����" << endl; }
	virtual void Drive(int a = 10){ cout << "Benz-����-(int)" << endl; }
};


void test()
{
	Car* ptr = new Benz;
	ptr->Drive();
}