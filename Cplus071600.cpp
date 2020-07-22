//unordered map和 unordered set

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

#include <iostream>
using namespace std;

void testUMap()
{
	unordered_map<int, int> um;
	map<int, int> m;

	um.insert(make_pair(1, 1));
	um.insert(make_pair(10, 1));
	um.insert(make_pair(2, 1));
	um.insert(make_pair(15, 1));
	um.insert(make_pair(8, 1));

	m.insert(make_pair(1, 1));
	m.insert(make_pair(10, 1));
	m.insert(make_pair(2, 1));
	m.insert(make_pair(15, 1));
	m.insert(make_pair(8, 1));

	//operator[]: 插入
	um[100] = 100;
	//operator[]: 修改
	um[15] = 15;

	um.at(2) = 2;

	//key不存在抛异常
	//um.at(20) = 20;

	//迭代器遍历无序
	cout << "unordered_map: " << endl;
	unordered_map<int, int>::iterator uit = um.begin();
	while (uit != um.end())
	{
		cout << uit->first << "-->" << uit->second << endl;
		++uit;
	}

	uit = um.find(100);
	cout << uit->first << "--->" << uit->second << endl;
	int cnt = um.count(100);
	cout << "cnt: 100  --> " << cnt << endl;
	uit = um.find(20);
	cnt = um.count(20);
	cout << (uit == um.end()) << endl;
	cout << "cnt: 20  --> " << cnt << endl;


	//迭代器遍历有序
	/*cout << "map: " << endl;
	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
	cout << it->first << " ";
	++it;
	}
	cout << endl;*/


}

void testSet()
{
	unordered_set<int> us;

	set<int> s;

	us.insert(10);
	us.insert(99);
	us.insert(48);
	us.insert(27);
	us.insert(16);

	//迭代器遍历无序
	unordered_set<int>::iterator uit = us.begin();
	while (uit != us.end())
	{
		cout << *uit << " ";
		++uit;
	}
	cout << endl;


	s.insert(10);
	s.insert(9);
	s.insert(8);
	s.insert(7);
	s.insert(6);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

//int main()
//{
//	//testUMap();
//	testSet();
//	return 0;
//}