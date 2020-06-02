//new��delete

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
	//new��λ���ʽ����������Ŀռ���г�ʼ��
	Date* pd = (Date*)malloc(sizeof(Date));
	//new��λ���ʽ�� new (��ַ) ����(�����б�)
	//	�����Ѿ����õĿռ�����ʽ���ù��캯��
	new (pd)Date(2030);
	Date* pd2 = (Date*)malloc(sizeof(Date));
	new (pd2)Date;
}