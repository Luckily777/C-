//final override��default
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

//����һ�����ܱ��̳е�����
class B final
{

};

class C
{
public:
	//default: �ñ�������ʽ����һ��Ĭ�Ϻ���
	C() = default;
	//C(){}
	//delete: ��һ��������������ɾ�������������ٱ�ʹ��
	// ������������Ϊdelete: ������
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
