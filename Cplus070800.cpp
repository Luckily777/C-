//mulitisetºÍmulitisemap
#include <map>
#include <set>
#include <iostream>
using namespace std;

void test()
{
	//multiset<int>  s;
	set<int>  s;
	s.insert(1);
	s.insert(10);
	s.insert(-1);
	s.insert(1);
	s.insert(2);
	s.insert(10);
	s.insert(0);

	for (const auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void testMap()
{
	//multimap: Ã»ÓĞoperator[], at
	multimap<int, int> m;
	//map<int, int> m;

	m.insert(make_pair(1, 1));
	m.insert(make_pair(10, 1));
	m.insert(make_pair(1, 2));
	m.insert(make_pair(0, 1));
	m.insert(make_pair(1, 3));

	for (const auto& p : m)
	{
		cout << p.first << "--->" << p.second << endl;
	}
	cout << "equal_range:" << endl;
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> p = m.equal_range(10);
	multimap<int, int>::iterator it = p.first;
	while (it != p.second)
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}


}

//int main()
//{
//	//test();
//	testMap();
//	return 0;
//}