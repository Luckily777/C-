//�ڲ���
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
	//�ڲ��ࣺ��һ�����ڲ�����һ���µ���
	//�ڲ�����Ȼ����Ϊ�ⲿ�����Ԫ��
	//�ڲ�����Ϊһ������������ڣ����������ⲿ��
	//�ⲿ�಻�ܿ����ڲ������Ԫ�࣬�����ڲ���ĳ�Աû������ķ���Ȩ�ޣ���Ҫ��ѭ�����޶���������
	class D
	{
	public:
		void fun(const C& c)
		{
			//����ͨ���ⲿ���������ⲿ���˽�г�Ա
			cout << c._color << endl;
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << C::_sc << endl;
			//����ֱ�ӷ����ⲿ���static��Ա
			cout << _sc << endl;

		}
	private:
		int _d;
	};
private:
	int _c;
	static int _sc;
	Color _color;
	//�ڲ������������κεط�����
	class E
	{
	private:
		int _e;
	};
};

