//C++struct: ���Զ������ݺͺ���
//C++������ķ�ʽ��
// 1. struct + ���� + {} + ";"
// 2. class + ���� + {} + ";"
#include <stdio.h>
#include <iostream>
#include <string.h>
struct Student
{
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}

	int _number;
	int _id;
	char name[10];
	char gender[10];
	char major[10];
};
//C++�ķ�װ���﷨���֣� �࣬ �����޶���
//����Ȩ�ޣ�public, protected, private
//ֻ���Ƴ�Ա������ķ���Ȩ�ޣ����ڲ����ܷ����޶���������
class Student2
{
public: //���еĳ�Ա������ɼ�
	//��Ա����
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}
private:  //˽�еĳ�Ա�����ⲻ�ɼ�
	//��Ա������ ����
	int _number;
	int _id;
protected:  // �����ĳ�Ա�����ⲻ�ɼ�
	char name[10];
	char gender[10];
	char major[10];
};

void test10()
{
	Student st;
	strcpy(st.name, "123");
	st.setId(20);

	Student2 st2;
	st2.display();
	st2._id = 10;
}

