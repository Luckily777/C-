// �ڴ�����
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
	int* ptr2 = (int*)calloc(1, sizeof(int));
	//realloc:  ��һ������Ϊnullptr/NULL, ���ܵȼ���malloc
	int* ptr3 = (int*)realloc(nullptr, sizeof(int));
	//�����ռ��С��
	// 1. ֱ��ԭ�ص�����С
	// 2. ���¿��ռ䣺 ��������ռ䣬���ݿ������ͷ�ԭ�пռ�
	int* ptr4 = (int*)realloc(ptr, sizeof(int) * 4);
	char* ptr5 = (char*)realloc(ptr2, sizeof(char));

	free(ptr3);
	free(ptr4);
	free(ptr5);
	//����realloc�еĿռ��������Ҫ��ʽ�ͷţ��ᵼ�¶����ͷŵ�����
	/*free(ptr);
	free(ptr2);*/
}

void test2()
{
	Date d(2020);
	Date* pd = (Date*)malloc(sizeof(Date));
	Date* pd2 = (Date*)calloc(1, sizeof(Date));

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