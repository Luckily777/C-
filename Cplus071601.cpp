//��ϣ�������̽��

#include <iostream>
#include <vector>
using namespace std;
//��ϣ������̽��

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

template <class K, class V>
struct HashNode
{
	pair<K, V> _value;
	//����״̬
	State _state;

	HashNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		, _state(EMPTY)
	{}
};

template <class K, class V>
class HashTable
{
public:
	HashTable(size_t n = 10)
	{
		_table.resize(n);
		_size = 0;
	}

	bool insert(const pair<K, V>& value)
	{
		//0. �������
		checkCapacity();
		//1. �����ϣλ��
		int idx = value.first % _table.size();

		//2. �ж�λ���Ƿ���ã��Լ������Ƿ��Ѿ�����
		while (_table[idx]._state == EXIST)
		{
			//�����Ѿ�����
			if (_table[idx]._value.first == value.first)
				return false;
			++idx;
			//�ж�λ���Ƿ�Խ��
			if (idx == _table.size())
				idx = 0;
		}
		//һ���ҵ���һ���յ�λ�û�����ɾ����λ��
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}

	HashNode<K, V>* find(const K& key)
	{
		int idx = key % _table.size();
		//�����ս�������
		while (_table[idx]._state != EMPTY)
		{
			//ֻ��״̬Ϊ���ڵ�������Ч
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
				return &_table[idx];
			++idx;
			if (idx == _table.size())
				idx = 0;
		}
		return nullptr;
	}

	void checkCapacity()
	{
		//�����������ӣ����������
		if (_size * 10 / _table.size() >= 7)
		{
			HashTable ht(2 * _table.size());

			//�ɱ�Ԫ�����²��뵽�±���
			for (int i = 0; i < _table.size(); ++i)
			{
				if (_table[i]._state == EXIST)
				{
					ht.insert(_table[i]._value);
				}
			}

			swap(_table, ht._table);
		}
	}

	bool erase(const K& key)
	{
		HashNode<K, V>* ptr = find(key);
		if (ptr)
		{
			//��ɾ��, ֻ��Ҫ�޸�״̬Ϊɾ��״̬
			ptr->_state = DELETE;
			--_size;
			return true;
		}
		return false;

	}
private:
	vector<HashNode<K, V>> _table;
	//��¼ʵ��Ԫ�صĸ���
	size_t _size;
};

void testHT()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(11, 1));
	ht.insert(make_pair(21, 1));
	ht.insert(make_pair(2, 1));
	ht.insert(make_pair(9, 1));
	ht.insert(make_pair(15, 1));
	ht.insert(make_pair(13, 1));
	ht.insert(make_pair(28, 1));
	ht.insert(make_pair(72, 1));
	ht.insert(make_pair(99, 1));
	ht.insert(make_pair(56, 1));

	HashNode<int, int>* ptr = ht.find(99);
	cout << ptr->_value.first << "--->" << ptr->_value.second << endl;
	ptr = ht.find(100);
	cout << ptr << endl;

	bool ret = ht.erase(72);
	ret = ht.erase(35);

}

int main()
{
	testHT();
	return 0;
}