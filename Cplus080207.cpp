//�߳���

#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

//unsigned long sum = 0L;
atomic<int> sum(0);

struct number
{
	int _num = 0;
	number& operator++()
	{
		++_num;
		return *this;
	}
};

number n;
atomic<number> atomic_number(n);


void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++;
}

void fun2(size_t num)
{
	for (int i = 0; i < num; ++i)
		++n;
}


void testThread()
{
	int num;
	cin >> num;

	thread t1(fun, num);
	thread t2(fun, num);

	t1.join();
	t2.join();

	cout << sum << endl;

	//atomic:������
	/*atomic<int> sum2 = sum;
	atomic<int> copy(sum);*/
}


void testThread2()
{
	int num;
	cin >> num;

	thread t1(fun2, num);
	thread t2(fun2, num);

	t1.join();
	t2.join();

	cout << n._num << endl;
}

mutex mtx;
int global = 0;
void fun3(int num)
{
	for (int i = 0; i < num; ++i)
	{
		//mtx.try_lock: ������������������������߳�û���ͷŵ�ǰ��������ֱ�ӷ��ؼ���ʧ�ܵĽ��
		//mtx.lock:  ����������������������߳�û���ͷŵ�ǰ�����������ȴ���ֱ�������߳��ͷŵ�ǰ��
		mtx.lock();
		//�����ǰ�߳�ӵ�и�����ִ�еڶ��εļ����������ᵼ������
		//mtx.lock();
		++global;
		mtx.unlock();
	}

}

void testThread3()
{
	int num;
	cin >> num;

	thread t1(fun3, num);
	thread t2(fun3, num);

	t1.join();
	t2.join();

	cout << global << endl;
}

//������
template <class Mutex>
class lockGuard
{
public:
	//���캯������
	lockGuard(Mutex& mtx)
		:_mtx(mtx)
	{
		//cout << "lockGuard(Mutex&)" << endl;
		_mtx.lock();
	}

	//������������
	~lockGuard()
	{
		//cout << "~lockGuard" << endl;
		_mtx.unlock();
	}

	//������
	lockGuard(const lockGuard<Mutex>&) = delete;
	lockGuard& operator=(const lockGuard<Mutex>&) = delete;
private:
	Mutex& _mtx;
};

void fun4(int num)
{
	for (int i = 0; i < num; ++i)
	{
		//����������
		lockGuard<mutex> lg(mtx);
		//������
		//lockGuard<mutex> copy(lg);
		++global;
	}

}

void testThread4()
{
	int num;
	cin >> num;

	thread t1(fun4, num);
	thread t2(fun4, num);

	t1.join();
	t2.join();

	cout << global << endl;
}

//int main()
//{
//	//testThread();
//	//testThread2();
//	//testThread3();
//	testThread4();
//	return 0;
//}