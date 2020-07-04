//���̳кͶ�̳�
#include <iostream>
using namespace std;

class Base {
	public:
		
		virtual void func1() { cout << "Base::func1" << endl; }
		virtual void func2() { cout << "Base::func2" << endl; }
	private:
		int a;
	};
	class Derive :public Base {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
		virtual void func4() { cout << "Derive::func4" << endl; }
	private:
		int b;
	};

	class Base1 {
	public:
		virtual void func1() { cout << "Base1::func1" << endl; }
		virtual void func2() { cout << "Base1::func2" << endl; }
	private:
		int b1;
	};
	class Base2 {
	public:
		virtual void func1() { cout << "Base2::func1" << endl; }
		virtual void func2() { cout << "Base2::func2" << endl; }
	private:
		int b2;
	};
	
	class Derive : public Base1, public Base2 {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
	private:
		int d1;
	};
	
	//���� ����ָ�룺 void ����()
	typedef void(*vfPtr)();
	
	void doVF(vfPtr* vftable)
	{
		cout << "����ַ:" << vftable << endl;
		//nullptr�� ����
		for (int i = 0; vftable[i] != nullptr; ++i)
		{
			//��ȡ��ǰ���λ�õĺ���ָ��
			vfPtr func = vftable[i];
			//ִ��ָ��ĺ���
			func();
		}
	}
	
	void test()
	{
		Base1 b;
		Base2 b2;
		Derive d;
		cout << "Base1:" << &b << endl;
		vfPtr* vftable = (vfPtr*)(*((int*)&b));
		doVF(vftable);
	
		cout << "Base2:" << &b2 << endl;
		vftable = (vfPtr*)(*((int*)&b2));
		doVF(vftable);
		
		//����Derive�ĵ�һ�����
		vftable = (vfPtr*)(*((int*)&d));
		cout << "Derive first vftable:" << &d << endl;
		doVF(vftable);
	
		//����Derive�ĵڶ������: ��ַƫ��
		vftable = (vfPtr*)(*((int*)((char*)&d + sizeof(Base1))));
		cout << "Derive second vftable:" << (int*)((char*)&d + sizeof(Base1)) << endl;
		doVF(vftable);
	}
	
	int main()
	{
		test();
		return 0;
	}