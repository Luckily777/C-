//�������ӿں���
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test5()
{
	string str("0123456789");
	//size: ������Ч�ַ��ĸ���
	int ret = str.size();
	//length: ������Ч�ַ��ĸ���
	ret = str.length();
	//capacity: ���Դ�ŵ������Ч�ַ��ĸ���
	ret = str.capacity();
	size_t maxSize = str.max_size();

	//clear: ֻ������ݣ����ı�����
	str.clear();
	ret = str.size();
	ret = str.capacity();

}

void test6()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();
	//resize(n)
	// 1. ��n > size, �� n > capacity: ����(���µĿռ� + ���� + �ͷ�ԭ�пռ䣩 + �µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0' + �޸�size
	str.resize(20);
	size = str.size();
	cap = str.capacity();
	//2. �� n < size: ֻ�޸�size
	str.resize(10);
	size = str.size();
	cap = str.capacity();
	//3. �� n > size, �� n < capacity: �µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0' + �޸�size
	str.resize(30, 'a');
	size = str.size();
	cap = str.capacity();

}

void test7()
{
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	//reserve: ����������һ�����޸�size������, 
	//�����С�������ǰ����С�����Ҫ��С������С��size,�����κβ����������С����������size������м�С�Ĳ���
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test8()
{
	string s;
	//������ʵ������Ŀռ���ܲ�ͬ�� �ַ����ص㣺��'\0'��������Ҫ��'\0'Ԥ���ռ�
	//PJ��string ���ݹ��̣� ���Ϊ���ַ������󣬳�ʼ������СΪ15����һ������2������������1.5������
	int size = s.size();
	//ʹ��reserve��ǰ���ÿռ䣬�������Խ�ʡ���ݵĿ�������ߴ���Ч��
	s.reserve(200);
	int cap = s.capacity();

	cout << "��ʼ������" << cap << endl;
	for (int i = 0; i < 200; ++i)
	{
		s.push_back(i);
		if (cap != s.capacity())
		{
			cap = s.capacity();
			cout << cap << endl;
		}
	}
}

void test9()
{
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();
	s.resize(13);
	s.reserve(10);
	size = s.size();
	cap = s.capacity();

	s.shrink_to_fit();
	size = s.size();
	cap = s.capacity();

	s.reserve(10000);
	size = s.size();
	cap = s.capacity();

	s.reserve(15);
	size = s.size();
	cap = s.capacity();
}