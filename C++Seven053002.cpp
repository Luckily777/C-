//new和delete

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

	// 单个类型的空间：new + 类型
	// 连续空间：new + 类型[个数]
	// 单个类型空间申请 + 初始化： new + 类型(初始值)
	// 基本类型用new申请连续空间，不能初始化
	int* ptr3 = new int;
	int* ptr4 = new int[10];
	int* ptr5 = new int(5);  //初始化为5

	//释放空间
	//单个空间： delete 指针
	//连续空间： delete[] 指针
	//申请和释放的操作匹配使用： malloc free,  new delete,  new [] delete[]
	delete ptr3;
	delete ptr5;
	delete[] ptr4;
}

void test4()
{
	//动态创建自定义类型的对象：
	//new：动态开空间 + 调用构造函数初始化
	//申请单个空间： new 自定义类型(参数列表)
	Date* pd = new Date(2020);
	Date* pd2 = new Date(2030);
	Date* pd4 = new Date;  //调用默认构造：无参，全缺省

	//申请连续的空间:new 自定义类型[个数], 自动调用默认构造进行初始化，如果没有默认构造，编译器报错
	Date* pd3 = new Date[10];

	//释放自定义类型的空间
	//delete: 调用析构函数清理资源 + 释放空间
	delete pd;
	delete pd2;
	delete pd4;
	//连续空间： 调用N次析构 +  释放空间
	delete[] pd3;
}
void test5()
{
	//void* operator new(size_t n)： 不是运算符重载函数，而是一个全局函数
	//                            : 使用方式和malloc类似
	//                            : 封装malloc + 异常
	//new 10;
	//new的执行过程(自定义类型)：operator new --> malloc  --> 构造函数

	char* ptr = (char*) operator new(sizeof(char));
	char* ptr2 = (char*)malloc(sizeof(char));

	//void operator delete(void* ptr):不是运算符重载函数，而是一个全局函数
	//                               :使用方式和free类似
	//                               ：封装free 
	// delete执行过程(自定义类型)： 析构 --> operator delete --> free
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
	//定制节点空间的申请方式
	void* operator new (size_t n)
	{
		//内存池申请
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
	//new定位表达式，给予申请的空间进行初始化
	Date* pd = (Date*)malloc(sizeof(Date));
	//new定位表达式： new (地址) 类型(参数列表)
	//	：在已经开好的空间上显式调用构造函数
	new (pd)Date(2030);
	Date* pd2 = (Date*)malloc(sizeof(Date));
	new (pd2)Date;
}