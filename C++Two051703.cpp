//auto�Զ������Ƶ�
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

//auto��C++�е����ã��Զ����������Ƶ����������������
//����ʱ������ݳ�ʼ���ı��ʽ�����Զ��Ƶ�
//auto�൱�����͵�ռλ�������������ڱ���ʱ�����Ƶ�
void test5()
{
	//auto int a = 0;  //C++��֧��
	auto b = 2;
	auto f = 3.0;
	auto c = 'a';
	auto d = 'a' + 'b';
	cout << typeid(b).name() << endl;//����
	cout << typeid(f).name() << endl;//������
	cout << typeid(c).name() << endl;//�ַ���
	cout << typeid(d).name() << endl;//����Ҳ�������ַ���

	//auto����ı��������ʼ�� 
	auto e; //���Ǵ����
	
			
			//auto���Զ���������
	auto a1 = 3, c1 = 4;
	
	
	//auto�ڶ���������ʱ��ÿһ���ı��ʽ������Ҫһ��
	//auto a2 = 1.5, c2 = 2;
	
	
	//auto���ڳ����ͱ����Ķ��壬�Ƚϼ�
	//std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator it;
	
	
	//auto����ָ�룬 �Ӳ���*,û������
	auto pb = &b;
	auto* pb2 = &b;
	cout << typeid(pb).name() << endl;
	cout << typeid(pb2).name() << endl;


	//������������ʱ�������&����
	auto& ra = b;  // int&
	auto ra2 = b;  // int


}
//�����������Ͳ���ʹ��auto
//void fun6(auto a, auto b);

//�������鲻��ʹ��auto
//auto array[] = { 1, 2, 3, 4, 45, 6 };