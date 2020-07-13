#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
using namespace std;

void testSet()
{
	set<int> s;

	int array[] = { 10, 3, 2, 8, 11 };
	set<int, greater<int>> s2(array, array + 5);

	set<int, greater<int>> copy(s2);

	set<int, greater<int>>::iterator it = s2.begin();
	//set元素不能修改
	//遍历有序： 搜索树的中序遍历
	while (it != s2.end())
	{
		cout << *it << " ";
		//*it = 100;
		++it;
	}
	cout << endl;

	set<int, greater<int>>::const_iterator cit = s2.cbegin();
	while (cit != s2.cend())
	{
		cout << *cit << " ";
		//*cit = 100;
		++cit;
	}
	cout << endl;

	set<int, greater<int>>::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void printSet(const set<int>& s2)
{
	set<int>::const_iterator cit = s2.cbegin();
	while (cit != s2.cend())
	{
		cout << *cit << " ";
		//*cit = 100;
		++cit;
	}
	cout << endl;
}
void testSet2()
{
	int array[] = { 10, 3, 2, 8, 11 };
	set<int> s2(array, array + 5);
	printSet(s2);   // 2, 3, 8,  10 , 11
	s2.insert(6);
	printSet(s2);  // 2, 3, 6, 8, 10 , 11
	//insert(iterator, value): iterator只是一个建议，新插入的元素位置不一定是指定的位置，最终插入位置需要遵循搜索树的性质
	s2.insert(s2.begin(), 15);
	printSet(s2);  // 15, 2, 3, 6, 8, 10 , 11   ?  // 2, 3, 6, 8, 10 , 11, 15
	int array2[] = { 9, 7, 20, 0 };
	s2.insert(array2, array2 + 4);
	printSet(s2);
	//set不会插入重复元素
	s2.insert(10);
	printSet(s2);
	s2.erase(10);
	printSet(s2);
	//删除最左值
	s2.erase(s2.begin());
	printSet(s2);
	//删除接口传入的位置必须有效
	//s2.erase(s2.end());
	//printSet(s2);
	auto it = s2.begin();
	auto it2 = ++s2.begin();
	cout << *it << endl;
	cout << *it2 << endl;
	//删除会导致当前位置的迭代器失效, 不影响其他位置的迭代器，失效的迭代器需要重新获取
	s2.erase(it);
	cout << *it2 << endl;

	//删除区间中的所有值： 左闭右开
	/*s2.erase(s2.begin(), s2.end());
	printSet(s2);*/
}

void testSet3()
{
	int array[] = { 10, 3, 2, 8, 11 };
	set<int> s2(array, array + 5);

	set<int>::iterator it = s2.find(3);
	if (it != s2.end())
		cout << *it << endl;
	else
		cout << "未找到" << endl;

	it = s2.find(300);
	if (it != s2.end())
		cout << *it << endl;
	else
		cout << "未找到" << endl;

	cout << s2.count(3) << endl;
	cout << s2.count(300) << endl;

}

void testMap()
{
	//map： key不能重复，但是value可以重复
	//map:  默认比较是小于， 都是通过key进行比较，value不参与比较
	map<string, int> m;

	vector<pair<string, int>> vec;
	for (int i = 0; i < 10; i++)
	{
		pair<string, int> p(string("bite") + (char)(i + '0'), 5);
		vec.push_back(p);
		vec.push_back(pair<string, int>(string("69") + (char)(i + '0'), 10));
		vec.push_back(make_pair(string("68") + (char)(i + '0'), 3));
	}

	map<string, int> m2(vec.begin(), vec.end());

	map<string, int> copy(m2);

	//迭代器解引用类型： pair
	//迭代器遍历顺序： key的递增顺序
	//非const迭代器支持value修改，不支持key的修改
	map<string, int>::iterator it = m2.begin();
	while (it != m2.end())
	{
		cout << it->first << "-->" << it->second << endl;
		//it->first = string("0000");
		it->second = 100;
		++it;
	}
	cout << "value changed" << endl;
	it = m2.begin();
	while (it != m2.end())
	{
		cout << it->first << "-->" << it->second << endl;
		/*it->first = string("0000");*/
		it->second = 100;
		++it;
	}

	cout << m2.size() << endl;

	cout << "vector<vector<int>> ---->  int" << endl;
	vector<vector<int>> vec2;
	vec2.push_back(vector<int>(5, 1));
	vec2.push_back(vector<int>(3, 3));
	vector<pair<vector<vector<int>>, int>> vec3;
	vec3.push_back(make_pair(vec2, 10));
	map<vector<vector<int>>, int> m3(vec3.begin(), vec3.end());
	map<vector<vector<int>>, int>::iterator it5 = m3.begin();
	while (it5 != m3.end())
	{
		cout << "key: " << endl;
		vector<vector<int>> mat = it5->first;
		for (int i = 0; i < mat.size(); ++i)
		{
			for (int j = 0; j < mat[i].size(); ++j)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << "value: " << it5->second << endl;
		++it5;
	}
	cout << "const_iterator: " << endl;
	map<string, int>::const_iterator cit = m2.begin();
	while (cit != m2.end())
	{
		cout << cit->first << "-->" << cit->second << endl;
		//cit->second = 100;
		++cit;
	}
	cout << endl;
}

void testMap2()
{
	map<int, int> m;
	//at: key不存在，抛异常
	//cout << m.at(2) << endl;
	// operator[]: key不存在， 插入
	cout << m[2] << endl;

	//pair<iterator, bool>:  iterator： map中kv键值对对应的迭代器, bool: 插入是否成功
	//插入成功： iterator表示新插入kv键值对的迭代器
	//插入失败： iterator表示已经存在的kv键值对的迭代器
	//插入成功
	pair<map<int, int>::iterator, bool> ret = m.insert(make_pair(3, 3));
	cout << ret.first->first << "--->" << ret.first->second << endl;
	cout << ret.second << endl;

	//插入失败：key已经存在

	ret = m.insert(make_pair(3, 10));
	cout << ret.first->first << "--->" << ret.first->second << endl;
	cout << ret.second << endl;


}

void printMap(const map<int, int>& m2)
{
	map<int, int>::const_iterator cit = m2.begin();
	while (cit != m2.end())
	{
		cout << cit->first << "-->" << cit->second << endl;
		//cit->second = 100;
		++cit;
	}
	cout << endl;
}

void testMap3()
{
	map<int, int> m;
	//插入操作
	m[1] = 1;
	m[2] = 2;
	m[3] = 3;
	m[4] = 4;
	printMap(m);

	//修改
	m[3] = 100;
	m[1] = -1;
	printMap(m);

	//删除同样也会导致当前位置的迭代器失效
	map<int, int>::iterator it = m.begin();
	cout << it->first << "-->" << it->second << endl;
	m.erase(it);
	/*cout << it->first << "-->" << it->second << endl;*/

	cout << "find:" << endl;
	it = m.find(3);
	cout << (it == m.end()) << endl;
	it = m.find(100);
	cout << (it == m.end()) << endl;
	cout << "count:" << endl;
	cout << m.count(3) << endl;
	cout << m.count(100) << endl;


}
int main()
{
	//testSet();
	//testSet2();
	//testSet3();
	//testMap();
	//testMap2();
	testMap3();
	return 0;
}