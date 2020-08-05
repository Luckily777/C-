//ֻ���ڶѺ�ջ�ϴ����������
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

//
//ֻ���ڶ��ϴ����������
// 1. ���캯��˽��
// 2. �ṩһ����̬�Ķ��ϴ�������ķ���
// 3. ������(������������Ϊ˽�У��Ҳ�ʵ�֣� ��������Ϊdelete������
class HeapOnly
{
public:
	static HeapOnly* getInstance()
	{
		//���ϴ�������
		return new HeapOnly;
	}
private:
	HeapOnly()
	{}

	//HeapOnly(const HeapOnly& ho);
	HeapOnly(const HeapOnly& ho) = delete;
};

//HeapOnly g;
void test()
{
	//HeapOnly ho;

	HeapOnly* ptr = HeapOnly::getInstance();

	//HeapOnly copy(*ptr);
}

//ֻ����ջ�ϴ����������
// a.
// 1. ���캯��˽��
// 2. �ṩһ�����еľ�̬��ջ�ϴ�������ķ���
class StackOnly
{
public:
	static StackOnly getInstance()
	{
		return StackOnly();
	}
private:
	StackOnly() {};
};

//StackOnly so;
void testStackOnly()
{
	//StackOnly* ptr = new StackOnly;
	StackOnly so = StackOnly::getInstance();
}

//ֻ����ջ�ϴ����������
// b.
// 1. ���캯��˽��
// 2. �ṩһ�����еľ�̬��ջ�ϴ�������ķ���
// 3. ��operator new��������Ϊdelete����
class StackOnly2
{
public:
	static StackOnly2 getInstance()
	{
		return StackOnly2();
	}
	void* operator new(size_t n) = delete;
private:
	StackOnly2() {};
};

void testStackOnly2()
{
	//StackOnly2* so2 = new StackOnly2;
	StackOnly2 so2 = StackOnly2::getInstance();
}