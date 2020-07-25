//��ɢ��


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

		// ����
		bool Insert(const pair<K, V>& val)
		{
			// ��ȡ��ϣ��ַ
			size_t hashAddr = HashFunc(val.first);

			// ����Ƿ���Ҫ����
			CheckCapacity();

			while (_ht[hashAddr]._state != EMPTY)
			{
				if (_ht[hashAddr]._state == EXIST &&
					_ht[hashAddr]._val.first == val.first)
				{
					// key�Ѿ�����
					return false;
				}

				// ������ϣ��ͻ,��������̽����д���
				hashAddr++;
				if (hashAddr != _ht.capacity())
					hashAddr = 0;
			}

			_ht[hashAddr]._state = EXIST;
			_ht[hashAddr]._val = val;
			_size++;
			return true;
		}

		// ����
		size_t Find(const K& key)
		{
			size_t hashAddr = HashFunc(key);

			while (_ht[hashAddr]._state != EMPTY)
			{
				if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
					return hashAddr;

				// ����̽��
				hashAddr++;
				if (hashAddr == _ht.capacity())
					hashAddr = 0;
			}

			return -1;
		}

		// ɾ��
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
			// �������Ӵﵽ70%����ʱ������
			if (_totalSize * 10 >= _ht.capacity())
			{
				HashTable<K, V> newHT(GetNextPrime(_ht.capacity()));

				// �˴�ֻ�轫��ЧԪ�ذ��Ƶ��¹�ϣ����
				// ��ɾ����Ԫ�ز��ô���
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
		size_t _totalSize;  // ��ϣ���е�����Ԫ�أ���Ч����ɾ��, ����ʱ��Ҫ�õ�
	};
}
