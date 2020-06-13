#include <list>
#include <iostream>
using namespace std;

template <class T>
void printLst(const list<T>& lst)
{
	for (const T& e : lst)
		cout << e << " ";
	cout << endl;
}

void t()
{
	list<int> lst;

	list<char> lst2(5, 'a');  // aaaaa

	char str[] = "12345";

	list<char> lst3(str, str + 5);  // 12345

	list<char> lst4(lst2.begin(), lst2.end());  // aaaaa  

	list<char> copy(lst3);  // 12345

	list<char>::iterator it = lst3.begin();
	while (it != lst3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int> lst5(3, 1);
	list<int>::iterator it2 = lst5.begin();
	while (it2 != lst5.end())
	{
		cout << *it2 << " ";
		*it2 = 5;
		++it2;
	}
	cout << endl;

	it2 = lst5.begin();
	while (it2 != lst5.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	for (char ch : lst3)
	{
		cout << ch << " ";
	}
	cout << endl;

	list<char>::reverse_iterator rit = lst3.rbegin();
	while (rit != lst3.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<char>::const_iterator cit = lst3.cbegin();
	while (cit != lst3.cend())
	{
		cout << *cit << " ";
		//*cit = 'z';
		++cit;
	}

	/*for (char& ch : lst3)
	{
		cout << ch << " ";
		ch = 'x';
	}
	cout << endl;

	for (char ch : lst3)
	{
		cout << ch << " ";
	}
	cout << endl;*/


}

class A
{
public:
	A(int a, int b)
		:_a(a)
	{
		cout << "A(int, int)" << endl;
	}

	bool operator<(const A& a)
	{
		return _a < a._a;
	}

	bool operator>(const A& a)
	{
		return _a > a._a;
	}
private:
	int _a;
};

void t2()
{
	/*list<int> lst;
	lst.push_back(1);
	lst.push_front(0);
	lst.push_front(-1);
	lst.push_front(-2);
	for (const auto& e : lst)
		cout << e << " ";
	cout << endl;

	lst.pop_back();
	printLst(lst);
	lst.pop_front();
	printLst(lst);
*/
	list<A> lst;
	A a(5, 6);


	lst.emplace_back(10, 9);
	lst.emplace_front(-1, 0);
	lst.emplace_back(a);

}

void t3()
{
	list<int> lst;
	//list迭代器在插入元素之后，不会失效
	lst.insert(lst.begin(), 1);
	list<int>::iterator it = lst.begin();
	cout << "*it: " << *it << endl;
	printLst(lst);
	lst.insert(lst.begin(), 3, 0);
	cout << "*it: " << *it << endl;
	printLst(lst);
	list<int> copy(lst);
	lst.insert(lst.end(), copy.begin(), copy.end());
	cout << "*it: " << *it << endl;

	printLst(lst);

	//删除会导致迭代器失效，调用删除接口之后，需要重新更新迭代器：1. 获取erase返回值， 2. 调用迭代器接口
	cout << "erase:" << endl;
	it = lst.erase(it);
	cout << "*it: " << *it << endl;
	printLst(lst);
	lst.erase(lst.begin(), lst.end());
	printLst(lst);

	cout << "resize: " << endl;
	lst.resize(5);
	printLst(lst);
	lst.resize(7, 1);
	printLst(lst);

	//remove: 删除指定值， 如果有多个，全部删掉，如果没有，不进行删除的操作
	cout << "remove" << endl;
	lst.remove(1);
	printLst(lst);
	lst.remove(10);
	printLst(lst);
	lst.remove(0);
	printLst(lst);

	int a[5] = { 1, 2, 1, 2, 1 };
	list<int> lst2(a, a + 5);
	printLst(lst2);
	lst2.remove(2);
	printLst(lst2);
}

void t4()
{
	list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	list<int> lst2;
	lst2.push_back(7);
	lst2.push_back(8);
	lst2.push_back(9);
	printLst(lst);
	printLst(lst2);

	//splice: 拼接时，被拼接的元素直接存入第一个lst, 第二个list中不在保留被拼接的元素
	lst.splice(++lst.begin(), lst2);
	cout << "splice:" << endl;
	printLst(lst);
	printLst(lst2);
	lst2.splice(lst2.begin(), lst, ++lst.begin(), --lst.end());
	printLst(lst);
	printLst(lst2);
	lst.splice(lst.end(), lst2, --lst2.end());
	printLst(lst);
	printLst(lst2);

	lst2.push_back(7);
	lst2.push_back(8);
	lst2.push_back(9);
	lst2.push_back(2);
	printLst(lst2);
	//unique: 使用之前需要lst元素有序
	lst2.unique();
	cout << "unique:" << endl;
	printLst(lst2);
	lst2.sort();
	cout << "sort:" << endl;
	printLst(lst2);
	lst2.unique();
	cout << "sorted unique:" << endl;
	printLst(lst2);

}

void t5()
{
	list<A> lst;
	lst.emplace_back(1, 1);
	lst.emplace_back(2, 2);
	lst.emplace_back(3, 3);
	lst.emplace_back(4, 5);
	lst.emplace_back(5, 5);
	//如果需要给自定义类型进行排序，自定义类型需要支持比较运算
	lst.sort();

	list<int> lst2;
	lst2.push_back(4);
	lst2.push_back(10);
	lst2.push_back(6);
	lst2.push_back(1);

	list<int>lst3(lst2);
	lst2.sort();
	lst3.sort();
	lst2.merge(lst3);
	printLst(lst2);

	cout << "reverse:" << endl;
	lst2.reverse();
	printLst(lst2);
}

//int main()
//{
//	//t();
//	//t2();
//	//t3();
//	//t4();
//	t5();
//	return 0;
//}