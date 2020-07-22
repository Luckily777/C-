//哈希表的线性探测

#include <iostream>
#include <vector>
using namespace std;
//哈希表：线性探测

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
	//数据状态
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
		//0. 检查容量
		checkCapacity();
		//1. 计算哈希位置
		int idx = value.first % _table.size();

		//2. 判断位置是否可用，以及数据是否已经存在
		while (_table[idx]._state == EXIST)
		{
			//数据已经存在
			if (_table[idx]._value.first == value.first)
				return false;
			++idx;
			//判断位置是否越界
			if (idx == _table.size())
				idx = 0;
		}
		//一定找到了一个空的位置或者已删除的位置
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}

	HashNode<K, V>* find(const K& key)
	{
		int idx = key % _table.size();
		//遇到空结束查找
		while (_table[idx]._state != EMPTY)
		{
			//只有状态为存在的数据有效
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
		//超过负载因子，则进行增容
		if (_size * 10 / _table.size() >= 7)
		{
			HashTable ht(2 * _table.size());

			//旧表元素重新插入到新表中
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
			//假删除, 只需要修改状态为删除状态
			ptr->_state = DELETE;
			--_size;
			return true;
		}
		return false;

	}
private:
	vector<HashNode<K, V>> _table;
	//记录实际元素的个数
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