//迭代器
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test4()
{
	//正向迭代器
	string str("0123456789");
	//迭代器的遍历方式
	//迭代器是一个可读可写的接口
	string::iterator it = str.begin();
	while (it != str.end())
	{
		//迭代器解引用
		cout << *it << " ";
		//修改元素内容
		//*it = 'a';
		//迭代器向后移动
		++it;
	}
	cout << endl;

	it = str.begin();
	while (it != str.end())
	{
		//迭代器解引用
		cout << *it << " ";
		//迭代器向后移动
		++it;
	}
	cout << endl;

	//反向迭代器
	cout << "reverse_iterator:" << endl;
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		//反向迭代器向前移动
		++rit;
	}
	cout << endl;

	//const迭代器
	cout << "const_iterator:" << endl;
	string::const_iterator cit = str.begin();
	//const迭代器建议使用const接口获取：c...()
	string::const_iterator cit2 = str.cbegin();
	while (cit != str.end())
	{
		cout << *cit << " ";
		//const迭代器不支持写操作，其为只读迭代器
		//*cit = '1';
		++cit;
	}
	cout << endl;

	/*vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>::iterator vit = vec.begin();
	while (vit != vec.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;*/
}