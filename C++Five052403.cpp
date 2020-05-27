//const函数
void printD()  // 等价于 printD(Date* const this)
{
	cout << _year << " " << _month << " " << _day << endl;
	//可以修改内容
	//this->_year = 100;
	//可以调用const成员函数
	fun();
}
//const成员函数中的const修饰的为第一个参数，即this指针
//const成员函数内部补能修改成员变量的值
void printD() const  //等价于 printD(const Date* const this)
{
	cout << _year << " " << _month << " " << _day << endl;
	//不能修改内容
	//this->_year = 100;
	//补能调用非const成员函数，读写的权限不能被放大
	//++*this;

}

void fun()const
{

}
