//map

void testMap()
{
	//map�� key�����ظ�������value�����ظ�
	//map:  Ĭ�ϱȽ���С�ڣ� ����ͨ��key���бȽϣ�value������Ƚ�
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

	//���������������ͣ� pair
	//����������˳�� key�ĵ���˳��
	//��const������֧��value�޸ģ���֧��key���޸�
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
	//at: key�����ڣ����쳣
	//cout << m.at(2) << endl;
	// operator[]: key�����ڣ� ����
	cout << m[2] << endl;

	//pair<iterator, bool>:  iterator�� map��kv��ֵ�Զ�Ӧ�ĵ�����, bool: �����Ƿ�ɹ�
	//����ɹ��� iterator��ʾ�²���kv��ֵ�Եĵ�����
	//����ʧ�ܣ� iterator��ʾ�Ѿ����ڵ�kv��ֵ�Եĵ�����
	//����ɹ�
	pair<map<int, int>::iterator, bool> ret = m.insert(make_pair(3, 3));
	cout << ret.first->first << "--->" << ret.first->second << endl;
	cout << ret.second << endl;

	//����ʧ�ܣ�key�Ѿ�����

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
	//�������
	m[1] = 1;
	m[2] = 2;
	m[3] = 3;
	m[4] = 4;
	printMap(m);

	//�޸�
	m[3] = 100;
	m[1] = -1;
	printMap(m);

	//ɾ��ͬ��Ҳ�ᵼ�µ�ǰλ�õĵ�����ʧЧ
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