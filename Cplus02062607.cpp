//��̬��ϰ




class A
{
public:
	void printV()
	{
		cout << "A::printV()" << endl;
	}
};

class B : public A
{
public:
	//�¶�����麯��
	virtual void printV()
	{
		cout << "B::printV()" << endl;
		A::printV();
	}

	//�̳���A����ͨ����printV
};

class C : public B
{
public:
	//�ӿ���ȫһ�£��麯����д
	virtual void printV()
	{
		cout << "C::printV()" << endl;
	}
};

void func(A& A)
{
	A.printV();
}

void fund(B& b)
{
	b.printV();
}

void test()
{
	A a;
	B b;
	C c;

	/*func(a);
	func(b);*/

	/*fund(b);
	fund(c);*/

	b.printV();
}

int main()
{
	test();
	return 0;
}