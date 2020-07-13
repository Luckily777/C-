//set

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
	//setԪ�ز����޸�
	//�������� ���������������
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
	//insert(iterator, value): iteratorֻ��һ�����飬�²����Ԫ��λ�ò�һ����ָ����λ�ã����ղ���λ����Ҫ��ѭ������������
	s2.insert(s2.begin(), 15);
	printSet(s2);  // 15, 2, 3, 6, 8, 10 , 11   ?  // 2, 3, 6, 8, 10 , 11, 15
	int array2[] = { 9, 7, 20, 0 };
	s2.insert(array2, array2 + 4);
	printSet(s2);
	//set��������ظ�Ԫ��
	s2.insert(10);
	printSet(s2);
	s2.erase(10);
	printSet(s2);
	//ɾ������ֵ
	s2.erase(s2.begin());
	printSet(s2);
	//ɾ���ӿڴ����λ�ñ�����Ч
	//s2.erase(s2.end());
	//printSet(s2);
	auto it = s2.begin();
	auto it2 = ++s2.begin();
	cout << *it << endl;
	cout << *it2 << endl;
	//ɾ���ᵼ�µ�ǰλ�õĵ�����ʧЧ, ��Ӱ������λ�õĵ�������ʧЧ�ĵ�������Ҫ���»�ȡ
	s2.erase(it);
	cout << *it2 << endl;

	//ɾ�������е�����ֵ�� ����ҿ�
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
		cout << "δ�ҵ�" << endl;

	it = s2.find(300);
	if (it != s2.end())
		cout << *it << endl;
	else
		cout << "δ�ҵ�" << endl;

	cout << s2.count(3) << endl;
	cout << s2.count(300) << endl;

}