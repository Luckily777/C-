//�߳�
#include <thread>

void tfunc1()
{
	cout << "tfunc1()" << endl;
}

void tfunc2(int a)
{
	cout << "tfunc2(int)" << endl;
}

void tfunc3(int a, int b, int c)
{
	cout << "tfunc3(int, int,int)" << endl;
}



void testThread()
{
	//thread t1;

	thread t1(tfunc1);
	thread t2(tfunc2, 1);
	thread t3(tfunc3, 1, 2, 3);
	return;
	cout << "�̵߳ȴ�" << endl;
	t1.join();
	t2.join();
	t3.join();
}

//RAII: ��Դ��ȡ������ʼ��
//  �ڹ��캯���г�ʼ����Դ
//  ������������������Դ
class ThreadManage
{
public:
	ThreadManage(thread& t)
		:_thread(t)
	{}

	~ThreadManage()
	{
		if (_thread.joinable())
			_thread.join();
	}
private:
	thread& _thread;
};

void testThread2()
{
	//thread t1;

	thread t1(tfunc1);
	thread t2(tfunc2, 1);
	thread t3(tfunc3, 1, 2, 3);
	ThreadManage tm1(t1);
	ThreadManage tm2(t2);
	ThreadManage tm3(t3);

	return;
	/*cout << "�̵߳ȴ�" << endl;
	t1.join();
	t2.join();
	t3.join();*/
}

class ThreadClass
{
public:
	void funcT(int a)
	{
		cout << a << endl;
	}
};

void testClassFunc()
{
	ThreadClass tc;
	//�������Ϊ��Ա����������Ҫд���������򣬲�����Ҫ��ʾȡ��ַ��������Ҫ����thisָ��Ķ���
	thread t1(&ThreadClass::funcT, &tc, 10);
	t1.join();
}

void func2(int& a)
{
	a += 10;
}

void func3(int* a)
{
	*a += 10;
}

void testThreadRef()
{
	int a = 0;
	cout << a << endl;
	//���������������Ϊ���ã����߳�����Ҫ�޸�ԭʼ�ı���������Ҫͨ��refת��
	thread t1(func2, ref(a));
	t1.join();
	cout << a << endl;

	thread t2(func3, &a);
	t2.join();
	cout << a << endl;
}