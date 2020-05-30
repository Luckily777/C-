#include <stdlib.h>
#include <iostream>
using namespace std;
void test()
{
	int array[10];  //��Ϊ���ֵ
	int array2[10] = { 1, 2, 3 };  //����ǰ������������Ϊ0
	int array3[10] = { 0 };  //����λ�ö�Ϊ0
}

void test1()
{
	//malloc:ֻ���пռ����룬�����г�ʼ��
	int* ptr = (int*)malloc(sizeof(int));
	*ptr = 4;
	//calloc: ���пռ����� + ���ʼ��
	int* ptr2 = (int*)calloc(1,sizeof(int));
	//realloc:  ��һ������Ϊnullptr/NULL, ���ܵȼ���malloc
	int* ptr3 = (int*)realloc(nullptr, sizeof(int));
	//�����ռ��С��
	// 1. ֱ��ԭ�ص�����С
	// 2. ���¿��ռ䣺 ��������ռ䣬���ݿ������ͷ�ԭ�пռ�
	int* ptr4 = (int*)realloc(ptr, sizeof(int)* 4);
	char* ptr5 = (char*)realloc(ptr2, sizeof(char));

	free(ptr3);
	free(ptr4);
	free(ptr5);
	//����realloc�еĿռ��������Ҫ��ʽ�ͷţ��ᵼ�¶����ͷŵ�����
	/*free(ptr);
	free(ptr2);*/
}

class Date
{
public:
	Date(int year = 1)
		:_year(year)
	{}
	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;

};

void test2()
{
	Date d(2020);
	Date* pd = (Date*)malloc(sizeof(Date));
	Date* pd2 = (Date*)calloc(1,sizeof(Date));
	
}

void test3()
{
	int* ptr = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 10);

	// �������͵Ŀռ䣺new + ����
	// �����ռ䣺new + ����[����]
	// �������Ϳռ����� + ��ʼ���� new + ����(��ʼֵ)
	// ����������new���������ռ䣬���ܳ�ʼ��
	int* ptr3 = new int;
	int* ptr4 = new int[10];
	int* ptr5 = new int(5);  //��ʼ��Ϊ5

	//�ͷſռ�
	//�����ռ䣺 delete ָ��
	//�����ռ䣺 delete[] ָ��
	//������ͷŵĲ���ƥ��ʹ�ã� malloc free,  new delete,  new [] delete[]
	delete ptr3;
	delete ptr5;
	delete[] ptr4;
}

void test4()
{
	//��̬�����Զ������͵Ķ���
	//new����̬���ռ� + ���ù��캯����ʼ��
	//���뵥���ռ䣺 new �Զ�������(�����б�)
	Date* pd = new Date(2020);
	Date* pd2 = new Date(2030);
	Date* pd4 = new Date;  //����Ĭ�Ϲ��죺�޲Σ�ȫȱʡ

	//���������Ŀռ�:new �Զ�������[����], �Զ�����Ĭ�Ϲ�����г�ʼ�������û��Ĭ�Ϲ��죬����������
	Date* pd3 = new Date[10];

	//�ͷ��Զ������͵Ŀռ�
	//delete: ������������������Դ + �ͷſռ�
	delete pd;
	delete pd2;
	delete pd4;
	//�����ռ䣺 ����N������ +  �ͷſռ�
	delete[] pd3;
}

void test5()
{
	//void* operator new(size_t n)�� ������������غ���������һ��ȫ�ֺ���
	//                            : ʹ�÷�ʽ��malloc����
	//                            : ��װmalloc + �쳣
	//new 10;
	//new��ִ�й���(�Զ�������)��operator new --> malloc  --> ���캯��

	char* ptr = (char*) operator new(sizeof(char));
	char* ptr2 = (char*)malloc(sizeof(char));

	//void operator delete(void* ptr):������������غ���������һ��ȫ�ֺ���
	//                               :ʹ�÷�ʽ��free����
	//                               ����װfree 
	// deleteִ�й���(�Զ�������)�� ���� --> operator delete --> free
	operator delete(ptr);
	free(ptr2);
	free(nullptr);
	operator delete(nullptr);
}

struct Node
{
public:
	Node()
	{
		cout << "Node()" << endl;
	}
	//���ƽڵ�ռ�����뷽ʽ
	void* operator new (size_t n)
	{
		//�ڴ������
		void* ptr = allocator<Node>().allocate(1);
		cout << "mem pool allocate" << endl;
		return ptr;
	}

	void operator delete(void* ptr)
	{
		allocator<Node>().deallocate((Node*)ptr, 1);
		cout << "mem pool deallocate" << endl;
	}

private:
	int _data;
	Node* _next;
};

void test6()
{
	Date* pd = new Date;
	Date* pd2 = new Date[10];

	Node* pn = new Node;
	Node* pn2 = new Node[10];

	delete pd;
	delete[] pd2;

	delete pn;
	delete[] pn2;
}

void test7()
{
	Date* pd = (Date*)malloc(sizeof(Date));
	//new��λ���ʽ�� new (��ַ) ����(�����б�)
	//	�����Ѿ����õĿռ�����ʽ���ù��캯��
	new (pd)Date(2030);
	Date* pd2 = (Date*)malloc(sizeof(Date));
	new (pd2)Date;
}

void test8()
{
	//char* ptr = new char[0x7fffffff];
	try
	{
		char* ptr = new char[10000];

		char* ptr2 = new char[0xfffffffful];
		
		cout << "delete " << endl;
		delete[] ptr;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
}
//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//���ͱ�̲�û�м���ʵ�ʵĴ�������ֻ�ǰ��ظ��Ĵ��뽻�������Զ����ɣ�
//���ٿ�����Ա���ظ��Ĺ���������߹���Ч�ʣ������Ҹ���
/*
template < typename / class ���Ͳ���1�� typename / class���Ͳ���2��.....>
��������
*/
//����ģ��
//����ģ��ʵ��������ʵ�ʲ������ͣ����ɿ�ִ�еĺ���
template <class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

template <class T>
T add(T a, T b)
{
	return a + b;
}

void test9()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	//��ʽʵ���������������Ӳ��������Զ��Ƶ�������ֱ�ӿ�ִ�еĴ���
	Swap(a, b);
	Swap(c, d);

	Date d1(2020);
	Date d2(2030);
	Swap(d1, d2);

	//Swap<int>(a, c);
	add(a, b);

	add<int>(a, c);
	add<char>(a, c);
	add(a, (int)c);
	//��ʽʵ������ ������ + <����> +(�����б�
	Swap<int>(a, b);
}

int main()
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}