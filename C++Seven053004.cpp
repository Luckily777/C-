//泛型编程

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

//泛型编程并没有减少实际的代码量，只是把重复的代码交给机器自动生成，
//减少开发人员的重复的工作量，提高工作效率，增加幸福感
/*
template < typename / class 泛型参数1， typename / class泛型参数2，.....>
函数定义
*/
//函数模板
//函数模板实例化：用实际参数类型，生成可执行的函数
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
	//隐式实例化：编译器更加参数进行自动推导，产生直接可执行的代码
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
	//显式实例化： 函数名 + <类型> +(参数列表）
	Swap<int>(a, b);
}
