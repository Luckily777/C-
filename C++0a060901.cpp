//Ò»ÏµÁÐ ²âÊÔº¯Êý

void test()
{
	Vector<int> v;
	Vector<char> v2;
	Vector<string> v3;

	size_t size = v.size();
	size = v2.size();
	size = v3.size();

	size_t cap = v.capacity();
	cap = v2.capacity();
	cap = v3.capacity();
}

void test2()
{
	Vector<int> v;
	v.pushBack(1);
	size_t size = v.size();
	size_t cap = v.capacity();

	v.pushBack(2);
	size = v.size();
	cap = v.capacity();
	v.pushBack(3);
	size = v.size();
	cap = v.capacity();
	v.pushBack(4);
	size = v.size();
	cap = v.capacity();
	v.pushBack(5);
	size = v.size();
	cap = v.capacity();
	v.pushBack(6);
	size = v.size();
	cap = v.capacity();
}


void test3()
{
	Vector<string> v;
	v.pushBack("1");
	v.pushBack("2");
	v.pushBack("3");
	v.pushBack("4");
}

void test4()
{
	Vector<string> v;
	v.pushBack("1");
	v.pushBack("2");
	v.pushBack("3");
	v.pushBack("4");

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
		//Ð´²Ù×÷
		v[i] = "a";
	}
	cout << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.operator[](i) << " ";
	}
	cout << endl;

	cout << "µü´úÆ÷£º" << endl;
	//µü´úÆ÷
	Vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		*it = "b";
		++it;
	}
	cout << endl;

	cout << "·¶Î§for£º" << endl;
	for (string& str : v)
	{
		cout << str << " ";
		str = "c";
	}
	cout << endl;

	cout << "printVector:" << endl;
	printVector(v);
}

void test5()
{
	Vector<int> v;
	Vector<char> v2;
	Vector<string> v3;

	v.resize(5);

	v2.resize(5);

	v3.resize(5);
}

void test6()
{
	Vector<int> v;
	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.end(), 4);
	v.insert(v.end(), 5);
	v.insert(v.end(), 6);
	v.insert(v.end(), 7);
	printVector(v);

	v.erase(v.end() - 1);
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
	v.erase(v.begin());
	printVector(v);
}

void test7()
{
	Vector<int> v;
	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.end(), 4);
	v.insert(v.end(), 5);
	v.insert(v.end(), 6);
	v.insert(v.end(), 7);

	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 1)
			it = v.erase(it);
		else
			++it;
	}

	printVector(v);
}



int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}