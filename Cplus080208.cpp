//�쳣����

#include <vector>
#include <iostream>
using namespace std;
int func()
{
	//return 1;
	try
	{
		//�׳��쳣
		throw 0;
	}
	catch (char n)
	{
		cout << "func catch(int)" << endl;
	}
	cout << "func" << endl;
	return 1;
}

void testE1()
{
	try
	{
		//try: ���ܷ����쳣�Ĵ��룬д��try�������
		func();
	}
	//catch�����Ӧ���͵��쳣
	catch (char ch)
	{
		cout << "catch(char)" << endl;
	}
	catch (char* str)
	{
		cout << "catch(char*)" << endl;
	}
	catch (float n)
	{
		cout << "testE1 catch (int)" << endl;
	}
	//catch(...): ��������catch��������󣬽������ܲ���
	catch (...)
	{
		cout << "catch(...)" << endl;
		//�쳣�������׳�
		throw;
	}
	cout << "TestE1" << endl;
}


void testE2()
{
	try
	{
		testE1();
	}
	catch (int n)
	{
		cout << "testE2 catch (int)" << endl;
	}
	cout << "testE2" << endl;
}

void testE3()
{
	int* ptr = new int[1000];
	try
	{
		func();
	}
	catch (char ch)
	{

	}
	catch (char* str)
	{
	}
	catch (...)
	{
		//�����׳�֮ǰ����ɱ�Ҫ�Ĳ���
		cout << "catch(...) delete" << endl;
		delete[] ptr;
		//�쳣�������׳�
		throw;
	}

	cout << "testE3 delete" << endl;
	delete[] ptr;
}

void testE4()
{
	try
	{
		testE3();
	}
	catch (int a)
	{
		cout << "testE4 catch(int)" << endl;
	}
}

void testE5()
{
	try
	{
		vector<double> vec;
		//vec.at(10) = 2.0;
		//vec.resize(0x3fffffff);
		char* ptr = new char[0x7fffffff];
	}
	//�������쳣�ĸ���������û���ָ����в��񣬿���ƥ�����м̳���ϵ����������
	//ͨ���������麯����д����ɶ�̬���߼������ղ�����̬����Ϊ������쳣�ľ�ȷ����
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
}



//int main()
//{
//	//testE1();
//	//testE2();
//	//testE4();
//	testE5();
//	return 0;
//}