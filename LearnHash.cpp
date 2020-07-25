//闭散列


namespace Close_Hash
{
	enum State { EMPTY, EXIST, DELETE };

	template<class K, class V>
	class HashTable
	{
		struct Elem
		{
			pair<K, V> _val;
			State _state;
		};

	public:
		HashTable(size_t capacity = 3)
			: _ht(capacity), _size(0), _totalSize(0)
		{
			for (size_t i = 0; i < capacity; ++i)
				_ht[i]._state = EMPTY;
		}

		// 插入
		bool Insert(const pair<K, V>& val)
		{
			// 获取哈希地址
			size_t hashAddr = HashFunc(val.first);

			// 检测是否需要扩容
			CheckCapacity();

			while (_ht[hashAddr]._state != EMPTY)
			{
				if (_ht[hashAddr]._state == EXIST &&
					_ht[hashAddr]._val.first == val.first)
				{
					// key已经存在
					return false;
				}

				// 发生哈希冲突,采用线性探测进行处理
				hashAddr++;
				if (hashAddr != _ht.capacity())
					hashAddr = 0;
			}

			_ht[hashAddr]._state = EXIST;
			_ht[hashAddr]._val = val;
			_size++;
			return true;
		}

		// 查找
		size_t Find(const K& key)
		{
			size_t hashAddr = HashFunc(key);

			while (_ht[hashAddr]._state != EMPTY)
			{
				if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
					return hashAddr;

				// 线性探测
				hashAddr++;
				if (hashAddr == _ht.capacity())
					hashAddr = 0;
			}

			return -1;
		}

		// 删除
		bool Erase(const K& key)
		{
			size_t hashAddr = Find(key);
			if (hashAddr != -1)
			{
				_ht[hashAddr]._state = DELETE;
				_size--;
				return true;
			}

			return false;
		}

		size_t Size()const
		{
			return _size;
		}

		bool Empty() const
		{
			return _size == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			swap(_totalSize, ht._totalSize);
			_ht.swap(ht._ht);
		}

	private:
		size_t HashFunc(const K& key)
		{
			return key % _ht.capacity();
		}

		void CheckCapacity()
		{
			// 负载因子达到70%以上时，扩容
			if (_totalSize * 10 >= _ht.capacity())
			{
				HashTable<K, V> newHT(GetNextPrime(_ht.capacity()));

				// 此处只需将有效元素搬移到新哈希表中
				// 已删除的元素不用处理
				for (size_t i = 0; i < _ht.capacity(); ++i)
				{
					if (_ht[i]._state == EXIST)
					{
						newHT.Insert(_ht[i]._val);
					}
				}

				this->Swap(newHT);
			}
		}
	private:
		vector<Elem> _ht;
		size_t _size;
		size_t _totalSize;  // 哈希表中的所有元素：有效和已删除, 扩容时候要用到
	};
}
