#include <string>
#include <iostream>
#include <vector>
using namespace std;
template <class K>
struct keyOfValue
{
	const K& operator()(const K& key)
	{
		return key;
	}
};


//��ɢ�У� ָ������ + ������

template <class V>
struct HashNode
{
	V _value;
	HashNode<V>* _next;

	HashNode(const V& val = V())
		:_value(val)
		, _next(nullptr)
	{}
};

//ǰ������
template <class K, class V, class KeyOfValue, class HF>
class HashTable;

template <class K, class V, class KeyOfValue, class HF>
struct HashIterator
{
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue, HF> Self;

	typedef HashTable<K, V, KeyOfValue, HF> HT;

	Node* _node;
	HT* _ht;

	HashIterator(Node* node, HT* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			//�ҵ���һ���ǿ������ͷ���
			// 1. ��λ��ǰ�ڵ��ڹ�ϣ���е�λ��
			//kov: ��ȡvalue��key
			KeyOfValue kov;
			//hf: ��ȡkeyת��֮�������
			HF hf;
			size_t idx = hf(kov(_node->_value)) % _ht->_table.size();

			// 2. �ӱ��е���һ��λ�ÿ�ʼ���ҵ�һ���ǿ������ͷ���
			++idx;
			Node* cur = _ht->_table[idx];

			for (; idx < _ht->_table.size(); ++idx)
			{
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
			}
			// 3. �ж��Ƿ��ҵ�һ���ǿյ�ͷ���
			if (idx == _ht->_table.size())
				_node = nullptr;
		}
		return *this;
	}
};

template <class K, class V, class KeyOfValue, class HF>
class HashTable
{
public:

	//����������Ϊ��Ԫ��
	template <class K, class V, class KeyOfValue, class HF>
	friend struct HashIterator;

	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue, HF> iterator;

	iterator begin()
	{
		//��һ���ǿ������ͷ���
		for (size_t i = 0; i < _table.size(); ++i)
		{
			Node* cur = _table[i];
			if (cur)
				return iterator(cur, this);
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	bool insert(const V& value)
	{
		checkCapacity();

		//1. ����λ��
		KeyOfValue kov;
		HF hf;
		int idx = hf(kov(value)) % _table.size();

		//2. ����key�Ƿ��Ѿ�����
		Node* cur = _table[idx];
		while (cur)
		{
			if (kov(cur->_value) == kov(value))
				return false;
			cur = cur->_next;
		}

		//3. ����: ͷ��
		cur = new Node(value);

		cur->_next = _table[idx];
		_table[idx] = cur;

		++_size;
		return true;
	}

	void checkCapacity()
	{
		if (_size == _table.size())
		{
			size_t newSize = _size == 0 ? 5 : 2 * _size;
			vector<Node*> newHt;
			newHt.resize(newSize);
			KeyOfValue kov;
			HF hf;
			//�����ɱ��еķǿյ�����
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[i];
				//������ǰ������
				while (cur)
				{
					//0. ��¼�ɱ��е���һ��Ԫ��
					Node* next = cur->_next;

					//1. �����µ�λ��
					int idx = hf(kov(cur->_value)) % newHt.size();

					//2. ͷ��
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					// 3. ������һ��Ԫ��
					cur = next;
				}
				_table[i] = nullptr;
			}

			_table.swap(newHt);
		}
	}

	Node* find(const K& key)
	{
		if (_table.size() == 0)
			return nullptr;

		HF hf;

		int idx = hf(key) % _table.size();

		Node* cur = _table[idx];
		KeyOfValue kov;
		while (cur)
		{
			if (kov(cur->_value) == key)
				return cur;
			cur = cur->_next;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		HF hf;
		int idx = hf(key) % _table.size();
		Node* cur = _table[idx];
		//������ɾ���߼�
		Node* prev = nullptr;

		KeyOfValue kov;
		while (cur)
		{
			if (kov(cur->_value) == key)
			{
				//ɾ��
				//�ж�ɾ�����Ƿ�Ϊͷ���
				if (prev == nullptr)
				{
					_table[idx] = cur->_next;
				}
				else
				{
					prev->_next = cur->_next;
				}

				delete cur;
				--_size;
				return true;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}
		return false;
	}

private:
	vector<Node*> _table;
	size_t _size = 0;
};

//void testHt()
//{
//	HashTable<int, int, keyOfValue<int>> ht;
//
//	ht.insert(10);
//	ht.insert(7);
//	ht.insert(35);
//	ht.insert(12);
//	ht.insert(25);
//	ht.insert(4);
//	ht.insert(14);
//	ht.insert(11);
//	ht.insert(9);
//
//	HashNode<int>* cur = ht.find(12);
//	cout << cur << endl;
//	cur = ht.find(100);
//	cout << cur << endl;
//
//	bool ret = ht.erase(12);
//	ret = ht.erase(100);
//	ret = ht.erase(25);
//}

//�ַ�ת��Ϊ����
struct strToInt
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

template <class K>
struct hashFun
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template <class K, class V, class HF = hashFun<K>>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& value)
		{
			return value.first;
		}
	};
public:
	bool insert(const pair<K, V>& value)
	{
		return _ht.insert(value);
	}
private:
	HashTable<K, pair<K, V>, MapKeyOfValue, HF> _ht;
};

template <class K, class HF = hashFun<K>>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& value)
		{
			return value;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue, HF>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	bool insert(const K& value)
	{
		return _ht.insert(value);
	}
private:
	HashTable<K, K, SetKeyOfValue, HF> _ht;
};

void testMap()
{
	UnorderedMap<int, int> um;
	um.insert(make_pair(1, 1));
	um.insert(make_pair(15, 15));
	um.insert(make_pair(3, 3));
	um.insert(make_pair(2, 2));
	um.insert(make_pair(14, 14));
	um.insert(make_pair(40, 40));

}

void testSet()
{
	UnorderedSet<int> um;
	um.insert(1);
	um.insert(3);
	um.insert(6);
	um.insert(18);
	um.insert(21);
	um.insert(31);

	UnorderedSet<int>::iterator it = um.begin();
	while (it != um.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void testSet2()
{
	UnorderedSet<string, strToInt> us;
	us.insert("123");
	us.insert("456");
	us.insert("01");
	us.insert("36");
}

int main()
{
	//testHt();
	//testMap();
	//testSet();
	testSet2();
	return 0;
}