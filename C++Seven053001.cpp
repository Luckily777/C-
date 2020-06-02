// new delete
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