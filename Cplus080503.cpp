//����ģʽ

#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

//����ģʽ
// 1. ���캯��˽��
// 2. �ṩһ����̬�ķ������ص���
// 3. ����һ����̬�ĵ�����Ա
// 4. ��������͸�ֵ����Ϊdelete����

// �ص㣺 ʵ�ּ򵥣� ���߳��龰��Ч�ʸ�
// ȱ�㣺 ������������ ������������ʼ����˳���޷�����
class singleton
{
public:
	static singleton* getInstance()
	{
		return &_single;
	}
private:
	//���캯��˽��
	singleton() {};

	//������
	singleton(const singleton& s) = delete;
	singleton& operator=(const singleton& s) = delete;

	static singleton _single;
};

//��̬��Ա�ĳ�ʼ��
singleton singleton::_single;


//����ģʽ
// 1. ���캯��˽��
// 2. �ṩһ����̬�ķ������ص���: ��һ�ε��ã� �������� ��������ֱ�ӷ���
// 3. ����һ����̬�ĵ���ָ�룬 ָ���ʼ��Ϊnullptr
// 4. ��������͸�ֵ����Ϊdelete����
// 5. ��֤�̰߳�ȫ(�޸�ָ��), ˫������Ч��

// �ص㣺 �ӳټ��أ����������飬 ����ָ�������������ĳ�ʼ��˳��
// ʵ�ָ���
class singleton2
{
public:
	static singleton2* getInstance()
	{
		//˫���
		if (_ptr == nullptr)
		{
			_mtx.lock();
			if (_ptr == nullptr)
			{
				//��һ�ε��ã���������
				_ptr = new singleton2;
			}
			_mtx.unlock();
		}
		return _ptr;
	}

	//��д�ɲ�д
	class GC
	{
	public:
		~GC()
		{
			if (_ptr)
				delete _ptr;
		}
	};

private:
	singleton2() {};

	//������
	singleton2(const singleton2&) = delete;
	singleton2& operator=(const singleton2&) = delete;

	static singleton2* _ptr;
	static mutex _mtx;
	static GC _gc;
};

singleton2* singleton2::_ptr = nullptr;
mutex singleton2::_mtx;
singleton2::GC singleton2::_gc;

void testSingleton()
{
	singleton* s1 = singleton::getInstance();
	singleton2* s2 = singleton2::getInstance();
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "---------------------------------" << endl;
		s1 = singleton::getInstance();
		s2 = singleton2::getInstance();
		cout << "s1:" << s1 << endl;
		cout << "s2:" << s2 << endl;
	}
}


//void testSingleton2(int n)
//{
//	cout << singleton2::getInstance() << endl;
//}

void testSingleton2(int n)
{
	for (int i = 0; i < n; ++i)
		//cout << singleton2::getInstance() << endl;
		singleton2::getInstance();
}

void testThread()
{
	int n;
	cin >> n;
	thread t1(testSingleton2, n);
	thread t2(testSingleton2, n);
	thread t3(testSingleton2, n);
	thread t4(testSingleton2, n);
	thread t5(testSingleton2, n);
	thread t6(testSingleton2, n);
	thread t7(testSingleton2, n);
	thread t8(testSingleton2, n);
	thread t9(testSingleton2, n);
	thread t10(testSingleton2, n);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
}