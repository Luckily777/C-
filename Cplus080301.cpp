//����ָ��

#include <iostream>
using namespace std;
//RAII˼�룺���ݶ�����������ڿ�����Դ����������
//RAIIһ��Ӧ�ã� ����ָ�� -->��������ָ�������������ڿ��ƶ�̬���ٵ���Դ����������
template <class T>
struct smartPtr
{
public:
	smartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~smartPtr()
	{
		cout << "~smartPtr : delete" << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};

void testSP()
{
	while (1)
	{
		int* ptr = new int[100];
		//smartPtr<int> sp(ptr);

		throw 1;
		/*cout << "delete" << endl;
		delete[] ptr;*/
	}
}

void testSP2()
{
	//int num = 1000;
	while (1)
	{
		try
		{
			testSP();
		}
		catch (int a)
		{

		}
	}
}

int main()
{
	//testSP();
	testSP2();
	return 0;
}